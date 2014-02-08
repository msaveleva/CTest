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
    char output_queue[100];
    char stack[50];
    
    printf("Please enter an expression:\n");
    fgets(str, 100, stdin);
    
    int i = 0;
    int output_queue_cnt = 0;
    int stack_cnt = 0;
    while (str[i] != '\n') {
        switch (detect_symbol_type(str[i])) {
            case sym_digit:
                output_queue[output_queue_cnt] = str[i];
                output_queue_cnt++;
                break;
            case sym_operator:
                if (detect_symbol_priority(stack[stack_cnt - 1]) == normal) {
                    output_queue[output_queue_cnt] = stack[stack_cnt-1];
                    output_queue_cnt++;
                    stack[stack_cnt-1] = str[i];
                } else {
                    stack[stack_cnt] = str[i];
                    stack_cnt++;
                }
                break;
                
            case sym_space:
                break;
                
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

    printf("Output: %s\n", output_queue);
    printf("Stack: %s\n", stack);
    
    return 0;
}

