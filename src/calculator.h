#ifndef SRC_CALCULATOR_H
#define SRC_CALCULATOR_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack {
  char stack_symbol;
  struct stack* next;
} stack;

double m_proccesing(char* input_str, double x);
int is_correct_symbols(char* instring, char* symbol);
char function_processing(char* symbol, int* symbol_point);
char function_checking(const char* symbol, int* symbol_point,
                       char* function_calling, char expected_res);
int is_correct_input(char* symbol);
void unary_between_brackets_processing(const char* symbol,
                                       char* temp_outstring);
int outstring_processing(char* symbol, char* outstring, stack* operations);
int numbers_processing(char* symbol, char* outstring, int* symbol_point,
                       int* outstring_point);
int calculation_proccesing(char* outstring, double* stack_of_notion, double x);

stack* push(struct stack*, char);
char cut_symbol_from_stack(struct stack**);
int priority_of_symbols(char);

int is_number(char symbol);
int is_bracket(char symbol);
int is_operation_symbol(char symbol);
int is_function_symbol(char symbol);

#endif  // SRC_CALCULATOR_H