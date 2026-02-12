# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

**cli-calc** is a command-line calculator written in C, designed as a learning project. It reads mathematical expressions from stdin, parses them to extract operands and operators, and (in future phases) performs calculations.

## Build Commands

```bash
make              # Build the calculator (output: bin/calc)
make DEBUG=1      # Build with debug symbols (-g -O0)
make clean        # Remove build artifacts (obj/, bin/)
```

## Running the Application

```bash
./bin/calc        # Interactive mode - reads expressions from stdin
./bin/calc --h    # Show usage message
```

Example input: `2*3`

## Architecture

The calculator is organized into modular components:

- **main.c**: Entry point that implements an input loop reading from stdin using `getline()`. Calls `parse_input()` to process each expression.

- **parser.c/parser.h**: `parse_input()` extracts operands and operators from input strings by iterating through characters and using validators from `hj_lib`. Currently parses left-hand side (lhs), operator (op), and right-hand side (rhs) into separate variables.

- **hj_lib.c/hj_lib.h**: Core utility functions:
  - `hj_atoi()`: Custom string-to-integer conversion (implements ASCII to integer logic)
  - `is_num()`: Validates if a character is a digit (ASCII 48-57)
  - `is_op()`: Validates if a character is a supported operator (+, -, *, /)

- **utils.c/utils.h**: String utilities:
  - `trim_newline()`: Removes trailing newline from input

- **calc.c/calc.h**: Placeholder module for calculation logic (currently only contains `hello_calc()` stub).

## Current State

The project is in active development with recent commits adding:
- Input loop with `getline()`
- Number validation via `is_num()`
- Operator validation via `is_op()`
- String-to-integer conversion with `hj_atoi()`

The parsing pipeline is functional but incomplete—calculations are not yet performed.

## Code Style

- Uses standard C99 (`-std=c99`)
- Includes header guards in .h files
- File headers include author (Hanjae Lee) and date
- Comments are in English and Korean
- Compiler flags: `-Wall -Wextra` (strict warnings)
