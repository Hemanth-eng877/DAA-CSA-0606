# CO1 Assessment Tool 1 — Design and Analysis of Algorithms

[![Language: C](https://img.shields.io/badge/Language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Compiler: GCC](https://img.shields.io/badge/Compiler-GCC-orange.svg)](https://gcc.gnu.org/)
[![Status: GitHub-Ready](https://img.shields.io/badge/Status-GitHub--Ready-brightgreen.svg)]()

## Project Overview
This repository contains the complete academic assessment project for **Course Outcome 1 (CO1) Assessment Tool 1**. It models, mathematically derives, and programmatically simulates two core divide-and-conquer algorithmic recurrences encountered in real-world engineering systems:

1. **Question 1: Multi-Source Log Processing System** — Solved using the **Substitution Method** (`T(n) = 2T(n/2) + log_2 n`).
2. **Question 2: Intelligent Warehouse Automation System** — Solved using the **Master Theorem** (`T(n) = 4T(n/2) + n`).

Each question includes modular C source code, analytical simulation verification, comprehensive engineering reports, asymptotic complexity derivations, and placeholder structures for screenshot documentation.

---

## Repository Structure

```text
CO1_AT1/
│
├── Question_1/
│   ├── Source_Code/
│   │   ├── main.c              # Modular C simulation for Log Processing recurrence
│   │   ├── README.md           # Instructions specific to Question 1 source code
│   │   └── sample_output.txt   # Realistic execution output & benchmark tables
│   │
│   └── Report/
│       ├── Report.md           # Comprehensive academic report & Substitution Method proof
│       └── Screenshots/        # Placeholder directory for verification screenshots
│           ├── README.md
│           └── .gitkeep
│
├── Question_2/
│   ├── Source_Code/
│   │   ├── main.c              # Modular C simulation for Warehouse Scheduling recurrence
│   │   ├── README.md           # Instructions specific to Question 2 source code
│   │   └── sample_output.txt   # Realistic execution output & benchmark tables
│   │
│   └── Report/
│       ├── Report.md           # Comprehensive academic report & Master Theorem proof
│       └── Screenshots/        # Placeholder directory for verification screenshots
│           ├── README.md
│           └── .gitkeep
│
└── README.md                   # Top-level project overview (this file)
```

---

## How to Compile

Both programs are written in clean, modular C (C99/C11 compliant) and can be compiled using `GCC` without warnings:

### Compiling Question 1 (Log Processing System)
```bash
gcc -Wall -Wextra -O2 Question_1/Source_Code/main.c -o q1_log_processing -lm
```
*(Note: `-lm` links the C math library required for `log2()` calculations).*

### Compiling Question 2 (Warehouse Automation System)
```bash
gcc -Wall -Wextra -O2 Question_2/Source_Code/main.c -o q2_warehouse_scheduling
```

---

## How to Run

After compilation, execute the binaries either in **interactive mode** or via **command-line arguments**:

### Running Question 1
```bash
# Interactive mode (displays power-of-2 benchmark table, then prompts for input n)
./q1_log_processing

# Command-line mode (directly simulates input size n = 1024)
./q1_log_processing 1024
```

### Running Question 2
```bash
# Interactive mode (displays quad-tree benchmark table, then prompts for input n)
./q2_warehouse_scheduling

# Command-line mode (directly simulates warehouse grid size n = 1024)
./q2_warehouse_scheduling 1024
```

---

## Question 1 Description: Multi-Source Log Processing System

- **Recurrence Relation:** \(T(n) = 2T(n/2) + \log_2 n\)
- **System Application:** Models a distributed log aggregation engine where incoming server logs are divided equally into two processing pipelines, followed by a logarithmic binary search and timestamp synchronization step during the merge phase.
- **Analytical Solution Method:** **Substitution Method (Iteration / Expansion)**
- **Asymptotic Time Complexity:** **\(\Theta(n)\)** or **\(O(n)\)**
- **Exact Closed-Form (for \(n=2^k, T(1)=1\)):** \(T(n) = 3n - \log_2 n - 2\)
- **Space Complexity:** **\(\Theta(\log n)\)** auxiliary stack memory

---

## Question 2 Description: Intelligent Warehouse Automation System

- **Recurrence Relation:** \(T(n) = 4T(n/2) + n\)
- **System Application:** Models an autonomous warehouse scheduling engine that partitions a 2D physical grid into 4 spatial sub-quadrants, recursively assigning robotic paths while incurring a linear global collision-synchronization overhead per division level.
- **Analytical Solution Method:** **Master Theorem for Divide-and-Conquer**
  - Parameters: \(a = 4\), \(b = 2\), \(f(n) = n\)
  - Critical Exponent: \(n^{\log_b a} = n^{\log_2 4} = n^2\)
  - Classification: **Case 1** (\(f(n) = n = O(n^{2-\epsilon})\) for \(\epsilon = 1 > 0\))
- **Asymptotic Time Complexity:** **\(\Theta(n^2)\)** or **\(O(n^2)\)**
- **Exact Closed-Form (for \(n=2^k, T(1)=1\)):** \(T(n) = 2n^2 - n\)
- **Space Complexity:** **\(\Theta(\log n)\)** auxiliary stack memory

---

## Expected Output

### Question 1 Sample Output Summary (`n = 1024`)
```text
==============================================================================
                  MULTI-SOURCE LOG PROCESSING SIMULATION                      
==============================================================================
  Input Size (n)               : 1024
  Recursive Calls              : 2047
  Simulated Cost               : 3060.0000
  Recurrence                   : T(n) = 2T(n/2) + log_2(n)
  Time Complexity              : O(n) [or Theta(n)]
==============================================================================
  Exact Closed-Form            : T(n) = 3n - log_2(n) - 2 (for n = 2^k)
==============================================================================
```

### Question 2 Sample Output Summary (`n = 1024`)
```text
==============================================================================
              INTELLIGENT WAREHOUSE TASK SCHEDULING SIMULATION                
==============================================================================
  Warehouse Size (n)           : 1024
  Recursive Calls              : 1398101
  Simulated Cost               : 2096128.0000
  Recurrence                   : T(n) = 4T(n/2) + n
  Time Complexity              : O(n^2) [or Theta(n^2)]
==============================================================================
  Exact Closed-Form            : T(n) = 2n^2 - n (for n = 2^k)
==============================================================================
```

---

## Technologies Used
- **Programming Language:** C (Standard C99/C11)
- **Mathematical Analysis:** Asymptotic Notation (Big-O, Theta, Omega), Substitution Method, Master Theorem
- **Documentation:** GitHub Flavored Markdown (GFM), LaTeX Mathematical Expressions
- **Version Control:** Git / GitHub

---

## Author Section
**Assessment:** CO1 Assessment Tool 1 — Design and Analysis of Algorithms  
**Course Outcome:** CO1 (Analyze the asymptotic performance of algorithms and derive time complexity using recurrence solving techniques)  
**Status:** Complete, verified, and GitHub-ready submission.
