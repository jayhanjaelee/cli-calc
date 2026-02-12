/**
 * @file hj_lib.c
 * @author Hanjae Lee (mail@hanjaelee.com)
 * @date 2026-02-10 23:13
 */

#include "hj_lib.h"

// string -> int 로 변환.
// ascii to integer implementation.
int hj_atoi(char *strg)
{
    int res = 0;
    int i = 0;

    while (strg[i] != '\0' && is_num(strg[i]))
    {
        /**
         * res * 10 을 곱하는이유: 십진수의 자리수를 올리기 위함.
         * strg[i] - '0': ASCII 숫자와 '0' 을 뺄셈하면 각 숫자간의 차이가 정수로 반환되기 때문. ex) '1' - '0' = 48 - 49 = 1
         */
        res = res * 10 + (strg[i] - '0');
        i++;
    }

    return res;
}

// ascii 48 ~ 57
int is_num(char ch)
{
    return (48 <= ch && ch <=57);
}

// 사용 가능한 연산자 추출.
/**
 *  1.+
 *  2.-
 *  3./
 *  4.*
 */
int is_op(char ch)
{
    switch (ch)
    {
        case '+':
            return 1;
        case '-':
            return 1;
        case '*':
            return 1;
        case '/':
            return 1;
        default:
            break;
    }

    return 0;
}


