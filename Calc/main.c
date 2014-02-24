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

int main()
{
    char str[100];
    rpnData output_queue[100];
    rpnData stack[50];
    
    printf("Please enter an expression:\n");
    fgets(str, 100, stdin);
    
    rpnData *parsed_string = parse_string(str);
    
//    printf("Operator: %lf", parsed_string[1]);
    
    //make reverse polish notation
    int i = 0;
    int output_queue_cnt = 0;
    int stack_cnt = 0;
    while (parsed_string[i].op != '\n') {
        switch (parsed_string[i].type) {
            case sym_digit:
                output_queue[output_queue_cnt] = parsed_string[i];
                output_queue_cnt++;
                break;
            case sym_operator:
                if (detect_symbol_priority(stack[stack_cnt-1].op) == normal) {
                    output_queue[output_queue_cnt] = stack[stack_cnt-1];
                    output_queue_cnt++;
                    stack[stack_cnt-1] = parsed_string[i];
                } else {
                    stack[stack_cnt] = parsed_string[i];
                    stack_cnt++;
                }
                
            default:
                break;
        }
        i++;
    }
        
//        switch (detect_symbol_type(parsed_string[i] + '0')) {
//            case sym_digit:
//                output_queue[output_queue_cnt] = parsed_string[i];
//                output_queue_cnt++;
//                break;
//            case sym_operator:
//                if (detect_symbol_priority(stack[stack_cnt - 1]) == normal) {
//                    output_queue[output_queue_cnt] = stack[stack_cnt-1];
//                    output_queue_cnt++;
//                    stack[stack_cnt-1] = parsed_string[i];
//                } else {
//                    stack[stack_cnt] = parsed_string[i];
//                    stack_cnt++;
//                }
//                break;
//                
//            case sym_space:
//                break;
//                
////            case sym_constant:
////                if (str[i] == 'P') {
////                    output_queue[output_queue_cnt] = kMPI;
////                }
////                if (str[i] == 'E') {
////                    output_queue[output_queue_cnt] = kME;
////                }
////                output_queue_cnt++;
//                
//            default:
//                break;
//        }
//        
//        i++;
//    }
    
//    for (int j = stack_cnt - 1; j >= 0; j--) {
//        output_queue[output_queue_cnt] = stack[j];
//        output_queue_cnt++;
//    }
//    output_queue[output_queue_cnt] = '\n';
    
//    printf("Output: %s", output_queue);
//    printf("Stack: %s\n", stack);
    
    //calculate reverse polish notation
//    while (output_queue[1] != '\n') {
//        int k = 0;
//        while (output_queue[k] != '\n') {
//            if (detect_symbol_type(output_queue[k]) == sym_operator) {
//                double result = 0;
//                
//                double a = output_queue[k-2];
//                double b = output_queue[k-1];
//                
//                switch ((int)output_queue[k]) {
//                    case '+':
//                        result = a + b;
//                        break;
//                    case '-':
//                        result = a - b;
//                        break;
//                    case '*':
//                        result = a * b;
//                        break;
//                    case '/':
//                        result = a / b;
//                        break;
//                        
//                    default:
//                        break;
//                }
//                output_queue[k-2] = result;
//                
//                int p = k-1;
//                while (output_queue[p] != '\n') {
//                    output_queue[p] = output_queue[p+2];
//                    p++;
//                }
//                output_queue[p] = '\n';
//            }
//            k++;
//        }
//    }
    
//    printf("\nResult: %f\n", output_queue[0]);
    
    return 0;
}
