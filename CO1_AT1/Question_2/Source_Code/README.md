# Intelligent Warehouse Automation System — Source Code

This directory contains the modular C source code (`main.c`) that simulates and analyzes the recurrence relation for the **Intelligent Warehouse Automation System**:

\[
T(n) = 4T(n/2) + n
\]

## Files Included
- `main.c`: Complete C program implementing recursive simulation, call tracking, and scalability analysis using Master Theorem parameters.
- `sample_output.txt`: Realistic execution output demonstrating benchmark tables across power-of-two warehouse sizes and interactive evaluation.

## Compilation Instructions
To compile `main.c` using GCC without warnings:
```bash
gcc -Wall -Wextra -O2 main.c -o q2_warehouse_scheduling
```

## Execution Instructions
Run interactive mode or specify a warehouse grid size as a command-line argument:
```bash
# Interactive mode (displays benchmark table then prompts for input)
./q2_warehouse_scheduling

# Command-line mode for specific warehouse size n
./q2_warehouse_scheduling 1024
```
