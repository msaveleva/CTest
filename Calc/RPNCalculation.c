//
//  RPNCalculation.c
//  Calc
//
//  Created by Maria Saveleva on 03/03/14.
//  Copyright (c) 2014 Maria Saveleva. All rights reserved.
//

#include <stdio.h>
#include "RPNCalculation.h"

double calculate_reverse_polish_notation(rpnData *output_queue)
{
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
                k = k-2;
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
                int tmp = k;
                while (output_queue[tmp].op != '\n') {
                    output_queue[tmp] = output_queue[tmp+1];
                    tmp++;
                }
                k--;
            }
            k++;
        }
    }
    
    return output_queue[0].number;
}