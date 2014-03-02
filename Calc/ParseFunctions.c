//
//  ParseFunctions.c
//  Calc
//
//  Created by Maria Saveleva on 07/02/14.
//  Copyright (c) 2014 Maria Saveleva. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>
#include "ParseFunctions.h"

rpnData* parse_string(char *string)
{
    char result_digits[50][50];
    char result_operators[50];
    static rpnData result_string[100];
    double result_numbers[100];

    int i = 0;
    int digits_cnt = 0;
    int digit_string = 0;
    int operators_cnt = 0;
    while (string[i] != '\n') {
        if (detect_symbol_type(string[i]) == sym_digit || string[i] == '.') {
            result_digits[digit_string][digits_cnt] = string[i];
            digits_cnt++;
        } else {
            if (detect_symbol_type(string[i]) == sym_operator) {
                result_operators[operators_cnt] = string[i];
                operators_cnt++;
                if (string[i] != '(' && string[i] != ')') {
                    result_digits[digit_string][digits_cnt] = '\n';
                    digit_string++;
                    digits_cnt = 0;
                }
            } else {
                if (detect_symbol_type(string[i]) == sym_constant) {
                    textType type = parse_consts_and_functions(string, i);
                    switch (type) {
                        case const_pi:
                            result_numbers[digit_string] = kMPI;
                            break;
                        case const_eil:
                            result_numbers[digit_string] = kME;
                            break;
                        case func_sin:
                            result_operators[operators_cnt] = 's';
                            operators_cnt++;
                            break;
                        case func_cos:
                            result_operators[operators_cnt] = 'c';
                            operators_cnt++;
                            break;
                        case func_exp:
                            result_operators[operators_cnt] = 'e';
                            operators_cnt++;
                            break;
                            
                        default:
                            break;
                    }
                }
            }
        }
        i++;
    }
    
    result_operators[operators_cnt] = '\n';
    
    for (int i = 0; i <= digit_string; i++) {
        
        if (result_numbers[i] == kMPI || result_numbers[i] == kME) {
            continue;
        }
        
        double result = 0;
        sscanf(result_digits[i], "%lf", &result);
        result_numbers[i] = result;
        printf("Parse result: %lf\n", result);
    }
    
    int num_cnt = 0;
    int op_cnt = 0;
    for (int i = 0; i <= (digit_string + operators_cnt); i++) {
        if (result_operators[op_cnt] == 's' || result_operators[op_cnt] == 'c' || result_operators[op_cnt] == 'e') {
            result_string[i].op = result_operators[op_cnt];
            result_string[i].type = sym_function;
            printf("%c", result_string[i].op);
            i++;
            op_cnt++;
            result_string[i].op = result_operators[op_cnt];
            result_string[i].type = sym_operator;
            printf("%c", result_string[i].op);
            op_cnt++;
            continue;
        }
        
        result_string[i].number = result_numbers[num_cnt];
        result_string[i].type = sym_digit;
        printf("%lf", result_string[i].number);
        i++;
        num_cnt++;
        
        if (result_operators[op_cnt] == ')') {
            result_string[i].op = result_operators[op_cnt];
            result_string[i].type = sym_operator;
            printf("%c", result_string[i].op);
            i++;
            op_cnt++;
        }
        
        result_string[i].op = result_operators[op_cnt];
        result_string[i].type = sym_operator;
        printf("%c", result_string[i].op);
        op_cnt++;
        
        if (result_operators[op_cnt] == '(') {
            i++;
            result_string[i].op = result_operators[op_cnt];
            result_string[i].type = sym_operator;
            printf("%c", result_string[i].op);
            op_cnt++;
        }
    }
    
    result_string[i].type = sym_operator;
    result_string[i].op = '\n';
    
    return result_string;
}

symbolType detect_symbol_type(char symbol)
{
    if (isdigit(symbol)) {
        return sym_digit;
    } else {
        if (isalpha(symbol)) {
            return sym_constant;
        } else {
            if (ispunct(symbol)) {
                return sym_operator;
            } else {
                return sym_space;
            }
        }
    }
}

priority detect_symbol_priority(char symbol)
{
    if (symbol == '+' || symbol == '-') {
        return low;
    } else {
        if (symbol == '*' || symbol == '/') {
            return normal;
        } else {
            return high;
        }
    }
}

textType parse_consts_and_functions(char *string, int cnt)
{
    if (string[cnt] == 'P' && string[cnt+1] == 'I') {
        return const_pi;
    }
    
    if (string[cnt] == 'E') {
        return const_eil;
    }
    
    if (string[cnt] == 's' && string[cnt+1] == 'i' && string[cnt+2] == 'n') {
        return func_sin;
    }
    
    if (string[cnt] == 'c' && string[cnt+1] == 'o' && string[cnt+2] == 's') {
        return func_cos;
    }
    
    if (string[cnt] == 'e' && string[cnt+1] == 'x' && string[cnt+2] == 'p') {
        return func_exp;
    }
    
    return can_not_read;
}
