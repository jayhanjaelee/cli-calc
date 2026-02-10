/**
 * @file hj_lib.c
 * @author Hanjae Lee (mail@hanjaelee.com)
 * @date 2026-02-10 23:13
 */

#include "hj_lib.h"

// string -> int 로 변환.
int hj_atoi(char *strg)
{
    int res = 0;
    int i = 0;

    while (strg[i] != '\0')
    {
        res = res * 10 + (strg[i] - '0');
        i++;
    }

    return res;
}

