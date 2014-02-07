//
//  OperationStack.c
//  Calc
//
//  Created by Maria Saveleva on 07/02/14.
//  Copyright (c) 2014 Maria Saveleva. All rights reserved.
//

#include <stdio.h>
#include "OperationStack.h"

void stack_init(o_Stack *stack, int max_size)
{
    char *newContents;
    
    //allocate new array to hold new contents
    newContents = (char *)malloc(sizeof(char)*max_size);
    
    stack->contents = newContents;
    stack->max_size = max_size;
    stack->top = -1; //i.e. is empty
}

void stack_destroy(o_Stack *stack)
{
    free(stack->contents);
    
    stack->contents = NULL;
    stack->max_size = 0;
    stack->top = -1;
}

int stack_is_empty(o_Stack *stack)
{
    return (stack->top < 0);
}

void stack_push(o_Stack *stack, char symbol)
{
    stack->contents[++stack->top] = symbol;
}

char stack_pop(o_Stack *stack)
{
    return stack->contents[stack->top--];
}