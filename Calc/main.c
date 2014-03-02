//
//  main.c
//  Calc
//
//  Created by Maria Saveleva on 07/02/14.
//  Copyright (c) 2014 Maria Saveleva. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include <math.h>
#include "ParseFunctions.h"
#include "ConstsEnums.h"
#include "OperationStack.h"

int main()
{
    char str[100];
    rpnData output_queue[100];
    o_Stack stack;
    
    printf("Please enter an expression:\n");
    fgets(str, 100, stdin);
    
    rpnData *parsed_string = parse_string(str);
    
    //make reverse polish notation
    int i = 0;
    int output_queue_cnt = 0;
    while (parsed_string[i].op != '\n') {
        switch (parsed_string[i].type) {
            case sym_digit:
                output_queue[output_queue_cnt] = parsed_string[i];
                output_queue_cnt++;
                break;
            case sym_operator:
                if (parsed_string[i].op == 's' ||
                    parsed_string[i].op == 'c' ||
                    parsed_string[i].op == 'e') {
                    stack_push(&stack, parsed_string[i]);
                    break;
                }
                
                if (parsed_string[i].op == '(') {
                    stack_push(&stack, parsed_string[i]);
                    break;
                }
                
                if (parsed_string[i].op == ')') {
                    while (stack.contents[stack.top].op != '(') {
                        output_queue[output_queue_cnt] = stack_pop(&stack);
                        output_queue_cnt++;
                    }
                    stack_pop(&stack);
                    
                    if (stack.contents[stack.top].op == 's' ||
                        stack.contents[stack.top].op == 'c' ||
                        stack.contents[stack.top].op == 'e') {
                        output_queue[output_queue_cnt] = stack_pop(&stack);
                        output_queue[output_queue_cnt].type = sym_function;
                        output_queue_cnt++;
                    }
                } else {
                    rpnData last_stack_element = stack_pop(&stack);
                    if (detect_symbol_priority(last_stack_element.op) == normal) {
                        output_queue[output_queue_cnt] = last_stack_element;
                        output_queue_cnt++;
                        stack_push(&stack, parsed_string[i]);
                    } else {
                        stack_push(&stack, last_stack_element);
                        stack_push(&stack, parsed_string[i]);
                    }
                }
                
            default:
                break;
        }
        i++;
    }
    
    for (int j = stack.top; j > 0; j--) {
        output_queue[output_queue_cnt] = stack_pop(&stack);
        output_queue_cnt++;
    }
    
    output_queue[output_queue_cnt].op = '\n';
    output_queue[output_queue_cnt].type = sym_operator;
    
    for (int z = 0; z < output_queue_cnt; z++) {
        if (output_queue[z].type == sym_digit) {
            printf("%lf", output_queue[z].number);
        } else {
            printf("%c", output_queue[z].op);
        }
    }
    
    //calculate reverse polish notation
    while (output_queue[1].type != sym_operator) {
        int k = 0;
        while (output_queue[k].op != '\n') {
            if (output_queue[k].type == sym_operator) {
                double result = 0;
                
                double a = output_queue[k-2].number;
                double b = output_queue[k-1].number;
                
                switch (output_queue[k].op) {
                    case '+':
                        result = a + b;
                        break;
                    case '-':
                        result = a - b;
                        break;
                    case '*':
                        result = a * b;
                        break;
                    case '/':
                        result = a / b;
                        break;
                        
                    default:
                        break;
                }
                output_queue[k-2].number = result;
                
                int p = k-1;
                while (output_queue[p].op != '\n') {
                    if (output_queue[p+1].op == '\n') {
                        break;
                    }
                    output_queue[p] = output_queue[p+2];
                    p++;
                }
                output_queue[p].op = '\n';
            } else if (output_queue[k].type == sym_function) {
                double result = 0;
                double a = output_queue[k-1].number;
                
                switch (output_queue[k].op) {
                    case 's':
                        result = sin(a);
                        break;
                    case 'c':
                        result = cos(a);
                        break;
                    case 'e':
                        result = exp(a);
                        break;
                        
                    default:
                        break;
                }
                output_queue[k-1].number = result;
                
                //replace array number with result
                while (output_queue[k].op != '\n') {
                    output_queue[k] = output_queue[k+1];
                    k++;
                }
            }
            k++;
        }
    }
    
    printf("\nResult: %f\n", output_queue[0].number);
    
    return 0;
}
