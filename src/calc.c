/**
 * @file calc.c
 * @author Hanjae Lee (mail@hanjaelee.com)
 * @date 2026-02-10 22:01
 */

#include <stdio.h>
#include "calc.h"

void calculate(struct calculator *calc)
{
    switch (calc->op)
    {
        case '+':
            calc->total = calc->lhs + calc->rhs;
            break;
        case '-':
            calc->total = calc->lhs - calc->rhs;
            break;
        case '*':
            calc->total = calc->lhs * calc->rhs;
            break;
        case '/':
            calc->total = calc->lhs / calc->rhs;
            break;
        default:
            break;
    }
}

void print_calculator(struct calculator *calc) {
    printf("calculator info: |lhs:%d|rhs:%d|op:%c|total:%d|\n",
            calc->lhs, calc->rhs, calc->op, calc->total);
}
