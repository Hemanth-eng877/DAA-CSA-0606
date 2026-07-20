/**
 * ============================================================================
 * Application: Intelligent Warehouse Automation System
 * File: main.c
 * Assessment: CO1 Assessment Tool 1 - Question 2
 * ============================================================================
 * 
 * Problem Statement:
 * A warehouse automation system schedules robotic tasks using the recurrence:
 * 
 * Recurrence Relation:
 *      T(n) = 4 * T(n / 2) + n           for n > 1
 *      T(1) = 1.0                        for n <= 1 (Base Case)
 * 
 * Master Theorem Analysis:
 *      Parameters: a = 4, b = 2, f(n) = n
 *      Critical Exponent: n^(log_b(a)) = n^(log_2(4)) = n^2
 *      Since f(n) = O(n^(2 - epsilon)) for epsilon = 1 > 0,
 *      Case 1 of the Master Theorem applies.
 * 
 * Asymptotic Time Complexity:
 *      Theta(n^2) or O(n^2)
 *      Exact closed-form for power-of-2 sizes with T(1)=1: T(n) = 2n^2 - n
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Structure to encapsulate simulation metrics for warehouse scheduling.
 */
typedef struct {
    double total_cost;          // Accumulated simulated cost T(n)
    unsigned long long calls;   // Total count of recursive function invocations
} SimulationResult;

/**
 * Recursively simulates the warehouse automation task scheduling recurrence:
 * T(n) = 4 * T(n / 2) + n
 * 
 * @param n Warehouse grid size / scheduling units
 * @param call_counter Pointer to track accumulated recursive calls across all branches
 * @return Accumulated double precision cost T(n)
 */
double simulate_recurrence(long long n, unsigned long long *call_counter) {
    // Increment function invocation counter upon entry
    (*call_counter)++;

    // Base Case: A single scheduling cell requires constant processing cost T(1) = 1.0
    if (n <= 1) {
        return 1.0;
    }

    // Divide phase: Partition scheduling grid into 4 sub-regions of size n / 2
    unsigned long long branch_calls[4] = {0, 0, 0, 0};
    double branch_costs[4] = {0.0, 0.0, 0.0, 0.0};

    for (int i = 0; i < 4; i++) {
        branch_costs[i] = simulate_recurrence(n / 2, &branch_calls[i]);
        *call_counter += branch_calls[i];
    }

    // Combine phase: Non-recursive scheduling overhead per level f(n) = n
    double non_recursive_work = (double)n;

    // Recurrence calculation: T(n) = 4 * T(n/2) + n
    double total_cost = non_recursive_work;
    for (int i = 0; i < 4; i++) {
        total_cost += branch_costs[i];
    }

    return total_cost;
}

/**
 * Displays formatted analytical and simulation metrics for warehouse scheduling.
 * 
 * @param n Warehouse size processed
 * @param total_calls Count of recursive function invocations
 * @param simulated_cost Resulting numerical cost from recurrence
 */
void display_results(long long n, unsigned long long total_calls, double simulated_cost) {
    printf("\n");
    printf("==============================================================================\n");
    printf("              INTELLIGENT WAREHOUSE TASK SCHEDULING SIMULATION                \n");
    printf("==============================================================================\n");
    printf("  %-28s : %lld\n", "Warehouse Size (n)", n);
    printf("  %-28s : %llu\n", "Recursive Calls", total_calls);
    printf("  %-28s : %.4f\n", "Simulated Cost", simulated_cost);
    printf("  %-28s : T(n) = 4T(n/2) + n\n", "Recurrence");
    printf("  %-28s : O(n^2) [or Theta(n^2)]\n", "Time Complexity");
    printf("==============================================================================\n");
    printf("  %-28s : T(n) = 2n^2 - n (for n = 2^k)\n", "Exact Closed-Form");
    printf("==============================================================================\n\n");
}

/**
 * Displays a benchmark scalability analysis across multiple warehouse grid sizes.
 */
void display_scalability_table(void) {
    printf("==============================================================================\n");
    printf("                     SCALABILITY BENCHMARK (POWERS OF 2)                      \n");
    printf("==============================================================================\n");
    printf(" %-12s | %-18s | %-20s | %-16s \n", "Warehouse Sz", "Recursive Calls", "Simulated Cost T(n)", "Exact Formula*");
    printf("------------------------------------------------------------------------------\n");

    long long sizes[] = {2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    for (int i = 0; i < num_sizes; i++) {
        long long n = sizes[i];
        unsigned long long calls = 0;
        double cost = simulate_recurrence(n, &calls);
        double exact = 2.0 * n * n - n;
        printf(" %-12lld | %-18llu | %-20.4f | %-16.4f \n", n, calls, cost, exact);
    }
    printf("==============================================================================\n");
    printf(" *Exact closed-form for power-of-2 inputs with T(1)=1: T(n) = 2n^2 - n\n\n");
}

/**
 * Main application entry point.
 */
int main(int argc, char *argv[]) {
    long long warehouse_size = 0;

    // Check if warehouse size was provided via command-line argument
    if (argc > 1) {
        warehouse_size = atoll(argv[1]);
        if (warehouse_size < 1) {
            fprintf(stderr, "[Error] Warehouse size must be a positive integer (n >= 1).\n");
            return EXIT_FAILURE;
        }
    } else {
        // Run standard scalability benchmark first for visual insight
        display_scalability_table();

        // Prompt user for interactive input
        printf("Enter warehouse size n (e.g., 1024): ");
        if (scanf("%lld", &warehouse_size) != 1 || warehouse_size < 1) {
            printf("[Notice] No valid interactive input provided. Using default n = 1024.\n");
            warehouse_size = 1024;
        }
    }

    // Perform simulation on chosen warehouse size
    unsigned long long total_calls = 0;
    double cost = simulate_recurrence(warehouse_size, &total_calls);

    // Print final results
    display_results(warehouse_size, total_calls, cost);

    return EXIT_SUCCESS;
}
