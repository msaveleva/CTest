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

double* parse_string(char *string)
{
    char result_digits[50][50];
    char result_operators[50];
    static double result_string[100];
    
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
                result_digits[digit_string][digits_cnt] = '\n';
                operators_cnt++;
                digit_string++;
                digits_cnt = 0;
            }
        }
        i++;
    }
    result_operators[operators_cnt] = '\n';
    
    double result_numbers[100];
    for (int i = 0; i <= digit_string; i++) {
        double result = 0;
        sscanf(result_digits[i], "%lf", &result);
        result_numbers[i] = result;
        printf("Parse result: %lf\n", result);
    }
    
    int k = 0;
    for (int i = 0; i <= (digit_string + operators_cnt); i++) {
        result_string[i] = result_numbers[k];
        printf("%lf", result_string[i]);
        i++;
        result_string[i] = result_operators[k];
        printf("%c", (char)result_string[i]);
        k++;
    }
    
    return result_string;
}

symbolType detect_symbol_type(char symbol)
{
    if (isdigit(symbol)) {
        return sym_digit;
    } else {
        if (isalpha(symbol)) {
            if (symbol == 'P' || symbol == 'E') {
                return sym_constant;
            } else {
                return sym_function;
            }
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
