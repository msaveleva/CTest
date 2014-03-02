//
//  OperationStack.h
//  Calc
//
//  Created by Maria Saveleva on 07/02/14.
//  Copyright (c) 2014 Maria Saveleva. All rights reserved.
//

#ifndef Calc_OperationStack_h
#define Calc_OperationStack_h
#include "ConstsEnums.h"

typedef struct {
    rpnData contents[50];
    int top;
    int max_size;
} o_Stack;

int stack_is_empty(o_Stack *stack);
void stack_push(o_Stack *stack, rpnData elem);
rpnData stack_pop(o_Stack *stack);

#endif
