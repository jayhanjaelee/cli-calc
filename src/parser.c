/**
 * @file parser.c
 * @author Hanjae Lee (mail@hanjaelee.com)
 * @date 2026-02-10 22:01
 */

#include <stdio.h>
#include <string.h>

#include "parser.h"
#include "utils.h"
#include "hj_lib.h"

/**
  * input 에서 피연산자, 연산자 추출하는 함수.
  */
void parse_input(char *input, int *lhs, int *rhs, char *op)
{
    trim_newline(input);
    size_t input_len = strlen(input);

    for (size_t i = 0; i < input_len; i++)
    {
        // 각 문자가 숫자인지, 문자인지 체크해서
        // lhs, rhs, op 로 할당.
        char *tmp_str = NULL;

        if (is_num(input[i]))
        {
            // do sth
            if (*lhs == 0) {
                *lhs = hj_atoi(&input[i]);
            } else if (*rhs == 0) {
                *rhs = hj_atoi(&input[i]);
            }

            // 처음 숫자를 찾고서 연산자를 찾을 때 까지 스킵.
            while (i < input_len - 1 && is_num(input[i + 1])) {
                i++;
            }
        } else if (is_op(input[i]))
        {
            // do sth
            *op = input[i];
        }
    }
}

