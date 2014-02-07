//
//  main.c
//  Calc
//
//  Created by Maria Saveleva on 07/02/14.
//  Copyright (c) 2014 Maria Saveleva. All rights reserved.
//

#include <stdio.h>
#include <math.h>

typedef enum {
    o_add, //+
    o_subtract, //-
    o_multiply, //*
    o_divide, // '/'
    o_left_parenthesis, // (
    o_right_parenthesis // )
} operator;

typedef enum {
    m_sin,
    m_cos,
    m_exp
} math_function;

const double pi = 3.14159;
const double eil = 2.71828;

int main()
{
    return 0;
}

