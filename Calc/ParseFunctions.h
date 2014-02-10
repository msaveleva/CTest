//
//  ParseFunctions.h
//  Calc
//
//  Created by Maria Saveleva on 07/02/14.
//  Copyright (c) 2014 Maria Saveleva. All rights reserved.
//

#ifndef Calc_ParseFunctions_h
#define Calc_ParseFunctions_h
#include "ConstsEnums.h"

double* parse_string(char *string);
int make_number_from_digits(char *arr);
symbolType detect_symbol_type(char symbol);
priority detect_symbol_priority(char symbol);

#endif
