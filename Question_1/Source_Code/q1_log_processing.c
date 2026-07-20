/**
 * ============================================================================
 * Application: Multi-Source Log Processing System
 * File: q1_log_processing.c
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
 *      T(1) = 1.0                        for n = 1 (Base Case)
 * 
 * Asymptotic Time Complexity:
 *      Theta(n) or O(n)
 *      Derived using the Substitution Method where exact cost for power of 2 is:
 *      T(n) = 3n - log_2(n) - 2
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * Structure to hold the simulation results of the recurrence.
 */
typedef struct {
    double cost;                // Accumulated simulated cost T(n)
    unsigned long long calls;   // Total number of recursive function calls
} SimulationResult;

/**
 * Recursively simulates the log processing recurrence:
 * T(n) = 2 * T(n / 2) + log_2(n)
 * 
 * @param n Input size (number of log entries to process)
 * @return SimulationResult containing total cost and call count
 */
SimulationResult simulate_recurrence(long long n) {
    SimulationResult result;
    
    // Base Case: T(1) = 1.0 (constant base cost for processing a single log entry)
    if (n <= 1) {
        result.cost = 1.0;
        result.calls = 1;
        return result;
    }
    
    // Recursive Step: Divide problem into two halves of size n / 2
    SimulationResult half_result = simulate_recurrence(n / 2);
    
    // Total recursive calls = current call (1) + calls from both recursive sub-branches
    result.calls = 1 + 2 * half_result.calls;
    
    // Cost calculation: 2 * T(n / 2) + log_2(n)
    result.cost = 2 * half_result.cost + log2((double)n);
    
    return result;
}

/**
 * Displays formatted simulation results for a given input size.
 * 
 * @param n Input size to simulate and display
 */
void display_results(long long n) {
    SimulationResult res = simulate_recurrence(n);
    
    printf("==============================================================================\n");
    printf("                  MULTI-SOURCE LOG PROCESSING SIMULATION                      \n");
    printf("==============================================================================\n");
    printf("  %-28s : %lld\n", "Input Size (n)", n);
    printf("  %-28s : %llu\n", "Recursive Calls Count", res.calls);
    printf("  %-28s : %.4f\n", "Simulated Cost T(n)", res.cost);
    printf("  %-28s : T(n) = 2T(n/2) + log_2(n)\n", "Recurrence Used");
    printf("  %-28s : O(n) [or Theta(n)]\n", "Time Complexity");
    printf("==============================================================================\n\n");
}

/**
 * Displays a benchmark table across multiple power-of-two log volumes.
 */
void run_benchmark_table(void) {
    printf("==============================================================================\n");
    printf("             SCALABILITY BENCHMARK: LOG PROCESSING RECURRENCE                 \n");
    printf("==============================================================================\n");
    printf(" %-12s | %-18s | %-20s | %-16s \n", "Input Size", "Recursive Calls", "Simulated Cost T(n)", "Exact Formula*");
    printf("------------------------------------------------------------------------------\n");
    
    long long sizes[] = {2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 4096, 16384, 65536, 1048576};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
    
    for (int i = 0; i < num_sizes; i++) {
        long long n = sizes[i];
        SimulationResult res = simulate_recurrence(n);
        double exact = 3.0 * n - log2((double)n) - 2.0; // Formula for T(1)=1.0
        printf(" %-12lld | %-18llu | %-20.4f | %-16.4f \n", n, res.calls, res.cost, exact);
    }
    printf("==============================================================================\n");
    printf(" *Exact formula for power-of-2 sizes with T(1)=1: T(n) = 3n - log_2(n) - 2\n\n");
}

/**
 * Main execution entry point.
 */
int main(int argc, char *argv[]) {
    printf("\n");
    // If input size is passed as command line argument
    if (argc > 1) {
        long long n = atoll(argv[1]);
        if (n < 1) {
            fprintf(stderr, "[Error] Input size n must be >= 1.\n");
            return EXIT_FAILURE;
        }
        display_results(n);
        return EXIT_SUCCESS;
    }
    
    // Otherwise run standard benchmark table and prompt user
    run_benchmark_table();
    
    printf("Enter custom input size n (or press Ctrl+C / EOF to exit): ");
    long long custom_n;
    if (scanf("%lld", &custom_n) == 1) {
        if (custom_n < 1) {
            printf("[Warning] Input size must be >= 1. Using default n = 1024.\n");
            custom_n = 1024;
        }
        printf("\n");
        display_results(custom_n);
    } else {
        printf("\n[Info] No custom input provided. Exiting successfully.\n");
    }
    
    return EXIT_SUCCESS;
}
