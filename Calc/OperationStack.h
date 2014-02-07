//
//  OperationStack.h
//  Calc
//
//  Created by Maria Saveleva on 07/02/14.
//  Copyright (c) 2014 Maria Saveleva. All rights reserved.
//

#ifndef Calc_OperationStack_h
#define Calc_OperationStack_h

typedef struct {
    char *contents;
    int top;
    int max_size;
} o_Stack;

void stack_init(o_Stack *stack, int max_size);
void stack_destroy(o_Stack *stack);
int stack_is_empty(o_Stack *stack);
void stack_push(o_Stack *stack, char symbol);
char stack_pop(o_Stack *stack);

#endif
