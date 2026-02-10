/**
 * @file parser.c
 * @author Hanjae Lee (mail@hanjaelee.com)
 * @date 2026-02-10 22:01
 */

#include <stdio.h>
#include <string.h>

#include "parser.h"
#include "utils.h"

// ascii 48 ~ 57
int is_num(char ch)
{
    return (48 <= ch && ch <=57);
}

// 사용 가능한 연산자 추출.
/**
  + - / *
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

void parse_input(char *input, int *lhs, int *rhs, char *op)
{
    trim_newline(input);
    size_t input_len = strlen(input);

    for (size_t i = 0; i < input_len; i++)
    {
        // 각 문자가 숫자인지, 문자인지 체크해서
        // lhs, rhs, op 로 할당.
        printf("%c isnum:%d\n", input[i], is_num(input[i]));

    }
}

