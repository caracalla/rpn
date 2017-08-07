#include <stdio.h>
#include "calc.h"

#define MAXVAL 100

int stack_position = 0;
double value_stack[MAXVAL];

void push(double value) {
  if (stack_position < MAXVAL) {
    value_stack[stack_position] = value;
    stack_position++;
  } else {
    printf("error: stack full, can't push %g\n", value);
  }
}

double pop() {
  if (stack_position > 0) {
    stack_position--;
    return value_stack[stack_position];
  } else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

void clear_stack() {
  stack_position = 0;
}
