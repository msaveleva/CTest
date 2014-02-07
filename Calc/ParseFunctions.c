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

//the last symbol of array with digits always must be '\n'
int make_number_from_digits(char *arr)
{
    int arrCounter = 0;
    for (int i = 0; i < 100; i++) {
        if (arr[i] != '\n') {
            arrCounter++;
        } else {
            break;
        }
    }
    
    int result = 0;
    int multiplier = 1;
    for (int i = (arrCounter - 1); i >=0; i--) {
        int number = arr[i] - '0';
        result = result + number * multiplier;
        multiplier *= 10;
    }
    
    printf("make_number_from_digits result: %d\n", result);
    return result;
}

symbolType detect_symbol_type(char symbol)
{
    if (isdigit(symbol)) {
        return sym_digit;
    } else {
        if (isalpha(symbol)) {
            return sym_function;
        } else {
            if (ispunct(symbol)) {
                return sym_operator;
            } else {
                return sym_space;
            }
        }
    }
}
