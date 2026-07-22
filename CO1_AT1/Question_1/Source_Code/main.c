/**
 * ============================================================================
 * Application: Multi-Source Log Processing System
 * File: main.c
 * Assessment: CO1 Assessment Tool 1 - Question 1
 * ============================================================================
 * 
 * Problem Statement:
 * A distributed log processing platform divides input into two equal parts 
 * and performs logarithmic work during the merging phase due to search and 
 * synchronization operations.
 * 
 * Recurrence Relation:
 *      T(n) = 2 * T(n / 2) + log_2(n)    for n > 1
 *      T(1) = 1.0                        for n <= 1 (Base Case)
 * 
 * Asymptotic Time Complexity:
 *      Theta(n) or O(n)
 *      Derived using the Substitution Method where exact cost for power-of-2:
 *      T(n) = 3n - log_2(n) - 2
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * Structure to encapsulate simulation metrics.
 */
typedef struct {
    double total_cost;          // Accumulated simulated time/work cost T(n)
    unsigned long long calls;   // Total count of recursive invocations
} SimulationResult;

/**
 * Calculates log base 2 of a positive integer safely.
 * 
 * @param value Positive integer input
 * @return Double precision logarithm base 2
 */
double calculate_log2(long long value) {
    if (value <= 0) {
        return 0.0;
    }
    return log2((double)value);
}

/**
 * Recursively simulates the log processing recurrence relation:
 * T(n) = 2 * T(n / 2) + log_2(n)
 * 
 * @param n Current log volume / input size
 * @param call_counter Pointer to track accumulated recursive calls across all branches
 * @return Accumulated double precision cost T(n)
 */
double simulate_recurrence(long long n, unsigned long long *call_counter) {
    // Increment function invocation counter
    (*call_counter)++;

    // Base Case: A single log entry requires constant processing overhead T(1) = 1.0
    if (n <= 1) {
        return 1.0;
    }

    // Divide phase: Split log volume into two equal halves of size n / 2
    unsigned long long left_calls = 0;
    unsigned long long right_calls = 0;

    double left_cost = simulate_recurrence(n / 2, &left_calls);
    double right_cost = simulate_recurrence(n / 2, &right_calls);

    // Accumulate total recursive calls from sub-branches
    *call_counter += (left_calls + right_calls);

    // Merge/Search phase work: log_2(n) synchronization cost
    double merge_work = calculate_log2(n);

    // Recurrence calculation: T(n) = T(n/2) + T(n/2) + log_2(n)
    return left_cost + right_cost + merge_work;
}

/**
 * Displays formatted analytical and simulation metrics for the given input size.
 * 
 * @param n Input size processed
 * @param total_calls Count of recursive function invocations
 * @param simulated_cost Resulting numerical cost from recurrence
 */
void display_results(long long n, unsigned long long total_calls, double simulated_cost) {
    printf("\n");
    printf("==============================================================================\n");
    printf("                  MULTI-SOURCE LOG PROCESSING SIMULATION                      \n");
    printf("==============================================================================\n");
    printf("  %-28s : %lld\n", "Input Size (n)", n);
    printf("  %-28s : %llu\n", "Recursive Calls", total_calls);
    printf("  %-28s : %.4f\n", "Simulated Cost", simulated_cost);
    printf("  %-28s : T(n) = 2T(n/2) + log_2(n)\n", "Recurrence");
    printf("  %-28s : O(n) [or Theta(n)]\n", "Time Complexity");
    printf("==============================================================================\n");
    printf("  %-28s : T(n) = 3n - log_2(n) - 2 (for n = 2^k)\n", "Exact Closed-Form");
    printf("==============================================================================\n\n");
}

/**
 * Displays a benchmark scalability analysis across multiple log volume sizes.
 */
void display_scalability_table(void) {
    printf("==============================================================================\n");
    printf("                     SCALABILITY BENCHMARK (POWERS OF 2)                      \n");
    printf("==============================================================================\n");
    printf(" %-12s | %-18s | %-20s | %-16s \n", "Input Size", "Recursive Calls", "Simulated Cost T(n)", "Exact Formula*");
    printf("------------------------------------------------------------------------------\n");

    long long sizes[] = {2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 4096, 16384, 65536, 1048576};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    for (int i = 0; i < num_sizes; i++) {
        long long n = sizes[i];
        unsigned long long calls = 0;
        double cost = simulate_recurrence(n, &calls);
        double exact = 3.0 * n - calculate_log2(n) - 2.0;
        printf(" %-12lld | %-18llu | %-20.4f | %-16.4f \n", n, calls, cost, exact);
    }
    printf("==============================================================================\n");
    printf(" *Exact closed-form for power-of-2 inputs with T(1)=1: T(n) = 3n - log_2(n) - 2\n\n");
}

/**
 * Main application entry point.
 */
int main(int argc, char *argv[]) {
    long long input_size = 0;

    // Check if input size was provided via command-line argument
    if (argc > 1) {
        input_size = atoll(argv[1]);
        if (input_size < 1) {
            fprintf(stderr, "[Error] Input size must be a positive integer (n >= 1).\n");
            return EXIT_FAILURE;
        }
    } else {
        // Run standard scalability benchmark first for visual insight
        display_scalability_table();

        // Prompt user for interactive input
        printf("Enter log volume size n (e.g., 1024): ");
        if (scanf("%lld", &input_size) != 1 || input_size < 1) {
            printf("[Notice] No valid interactive input provided. Using default n = 1024.\n");
            input_size = 1024;
        }
    }

    // Perform simulation on chosen input size
    unsigned long long total_calls = 0;
    double cost = simulate_recurrence(input_size, &total_calls);

    // Print final results
    display_results(input_size, total_calls, cost);

    return EXIT_SUCCESS;
}
