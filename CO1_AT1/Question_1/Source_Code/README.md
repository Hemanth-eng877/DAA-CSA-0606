# Multi-Source Log Processing System — Source Code

This directory contains the modular C source code (`main.c`) that simulates and analyzes the recurrence relation for the **Multi-Source Log Processing System**:

\[
T(n) = 2T(n/2) + \log_2 n
\]

## Files Included
- `main.c`: Complete C program implementing recursive simulation, call tracking, and scalability analysis.
- `sample_output.txt`: Realistic execution output demonstrating benchmark tables and interactive evaluation.

## Compilation Instructions
To compile `main.c` using GCC:
```bash
gcc -Wall -Wextra -O2 main.c -o q1_log_processing -lm
```

## Execution Instructions
Run interactive mode or specify an input size as a command-line argument:
```bash
# Interactive mode (displays benchmark table then prompts for input)
./q1_log_processing

# Command-line mode for specific input size n
./q1_log_processing 1024
```
