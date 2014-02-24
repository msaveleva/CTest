//
//  ConstsEnums.h
//  Calc
//
//  Created by Maria Saveleva on 07/02/14.
//  Copyright (c) 2014 Maria Saveleva. All rights reserved.
//

#ifndef Calc_ConstsEnums_h
#define Calc_ConstsEnums_h

extern const double kMPI;
extern const double kME;

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

typedef enum {
    low, //+ -
    normal, //* /
    high //sin, cons, exp
} priority;

typedef enum {
    sym_operator,
    sym_function,
    sym_constant,
    sym_space,
    sym_digit
} symbolType;

typedef struct {
    symbolType type;
    union {
        double number;
        char op; //operator
    };
} rpnData;

#endif /* Calc_ConstsEnums_h */
