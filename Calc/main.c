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
    char *stack_top = &stack[0];
    
    printf("Please enter an expression:\n");
    fgets(str, 100, stdin);
    
    int i = 0;
    int output_queue_cnt = 0;
    while (str[i] != '\n') {
        switch (detect_symbol_type(str[i])) {
            case sym_digit:
                output_queue[output_queue_cnt] = str[i];
                output_queue_cnt++;
                break;
            case sym_operator:
                

                break;
            case sym_space:
                break;
                
            default:
                break;
        }
        
        i++;
    }
    printf("Output: %s\n", output_queue);
    
    return 0;
}

