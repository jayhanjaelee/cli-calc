/**
 * @file calc.h
 * @author Hanjae Lee (mail@hanjaelee.com)
 * @date 2026-02-10 22:01
 */

#ifndef CALC_H
#define CALC_H

// 내용을 입력하세요
struct calculator {
    int lhs;
    int rhs;
    char op;
    int total;
};

void calculate(struct calculator *calc);
void print_calculator(struct calculator *calc);

#endif /* CALC_H */

