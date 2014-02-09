//
//  main.c
//  Calc
//
//  Created by Maria Saveleva on 07/02/14.
//  Copyright (c) 2014 Maria Saveleva. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ParseFunctions.h"
#include "ConstsEnums.h"

int main()
{
    char str[100];
    double output_queue[100];
    double stack[50];
    
    printf("Please enter an expression:\n");
    fgets(str, 100, stdin);
    
    //make reverse polish notation
    int i = 0;
    int output_queue_cnt = 0;
    int stack_cnt = 0;
    while (str[i] != '\n') {
        switch (detect_symbol_type(str[i])) {
            case sym_digit:
                output_queue[output_queue_cnt] = (double)(str[i] - '0');
                output_queue_cnt++;
                break;
            case sym_operator:
                if (detect_symbol_priority(stack[stack_cnt - 1]) == normal) {
                    output_queue[output_queue_cnt] = stack[stack_cnt-1];
                    output_queue_cnt++;
                    stack[stack_cnt-1] = (double)str[i];
                } else {
                    stack[stack_cnt] = (double)str[i];
                    stack_cnt++;
                }
                break;
                
            case sym_space:
                break;
                
            case sym_constant:
                if (str[i] == 'P') {
                    output_queue[output_queue_cnt] = kMPI;
                }
                if (str[i] == 'E') {
                    output_queue[output_queue_cnt] = kME;
                }
                output_queue_cnt++;
                
            default:
                break;
        }
        
        i++;
    }
    
    for (int j = stack_cnt - 1; j >= 0; j--) {
        output_queue[output_queue_cnt] = stack[j];
        output_queue_cnt++;
    }
    output_queue[output_queue_cnt] = '\n';
    
//    printf("Output: %s", output_queue);
//    printf("Stack: %s\n", stack);
    
    //calculate reverse polish notation
    while (output_queue[1] != '\n') {
        int k = 0;
        while (output_queue[k] != '\n') {
            if (detect_symbol_type(output_queue[k]) == sym_operator) {
                double result = 0;
                
                double a = output_queue[k-2];
                double b = output_queue[k-1];
                
                switch ((int)output_queue[k]) {
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
                output_queue[k-2] = result;
                
                int p = k-1;
                while (output_queue[p] != '\n') {
                    output_queue[p] = output_queue[p+2];
                    p++;
                }
                output_queue[p] = '\n';
            }
            k++;
        }
    }
    
    printf("Output: %f\n", output_queue[0]);
    
    return 0;
}

