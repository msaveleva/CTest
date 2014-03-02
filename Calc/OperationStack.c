//
//  OperationStack.c
//  Calc
//
//  Created by Maria Saveleva on 07/02/14.
//  Copyright (c) 2014 Maria Saveleva. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#include "OperationStack.h"

int stack_is_empty(o_Stack *stack)
{
    return (stack->top < 0);
}

void stack_push(o_Stack *stack, rpnData elem)
{
    stack->contents[++stack->top] = elem;
}

rpnData stack_pop(o_Stack *stack)
{
    return stack->contents[stack->top--];
}