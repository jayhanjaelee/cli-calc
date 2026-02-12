/**
 * @file main.c
 * @author Hanjae Lee (mail@hanjaelee.com)
 * @date 2026-02-10 21:21
 */

#include <stdio.h>
#include <string.h>

#include "parser.h"
#include "calc.h"

int main(int argc, char *argv[])
{
    // 커맨드라인 인자가 없으면
    // usage 보여주기
    if (argc == 2 && strcmp(argv[1], "--h") == 0)
    {
        printf("Usage: calc <nums>\n");
        printf("Ex: calc 2*2\n");
    }

    while (1)
    {
        char *input = NULL;
        size_t linecap = 0;
        ssize_t written_bytes = getline(&input, &linecap, stdin);

        if (written_bytes == -1 || written_bytes == EOF){
            printf("Quit\n");
            break;
        }

        // printf("input: %s", input);

        int lhs = 0, rhs = 0;
        char op = '\0';
        parse_input(input, &lhs, &rhs, &op);

        struct calculator calc = {
            .lhs = lhs,
            .rhs = rhs,
            .op = op,
        };
    }

    return 0;
}

