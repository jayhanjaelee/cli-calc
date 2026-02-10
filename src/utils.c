/**
 * @file utils.c
 * @author Hanjae Lee (mail@hanjaelee.com)
 * @date 2026-02-10 22:51
 */

#include <string.h>

#include "utils.h"

// 내용을 입력하세요
void trim_newline(char *str)
{
    str[strcspn(str, "\n")] = '\0';
}

