/**
 * ============================================================================
 * Application: Intelligent Warehouse Automation System
 * File: q2_warehouse_scheduling.c
 * Assessment: CO1 Assessment Tool 1 - Question 2
 * ============================================================================
 * 
 * Problem Statement:
 * A warehouse automation system schedules robotic tasks using the recurrence:
 * 
 * Recurrence Relation:
 *      T(n) = 4 * T(n / 2) + n           for n > 1
 *      T(1) = 1.0                        for n = 1 (Base Case)
 * 
 * Master Theorem Parameters:
 *      a = 4 (Branching factor: each task is split into 4 sub-tasks)
 *      b = 2 (Division factor: each sub-task operates on half the grid/warehouse)
 *      f(n) = n (Non-recursive scheduling overhead per level)
 * 
 * Master Theorem Analysis:
 *      Compare f(n) = n with n^(log_b(a)) = n^(log_2(4)) = n^2.
 *      Since f(n) = n = O(n^(2 - epsilon)) for epsilon = 1 > 0,
 *      Case 1 of the Master Theorem applies.
 * 
 * Asymptotic Time Complexity:
 *      Theta(n^2) or O(n^2)
 *      Exact formula for power-of-2 sizes with T(1)=1: T(n) = 2n^2 - n
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
 * Recursively simulates the warehouse automation task scheduling recurrence:
 * T(n) = 4 * T(n / 2) + n
 * 
 * @param n Warehouse size / number of scheduling units
 * @return SimulationResult containing total cost and call count
 */
SimulationResult simulate_recurrence(long long n) {
    SimulationResult result;
    
    // Base Case: T(1) = 1.0 (constant base cost for scheduling a single unit task)
    if (n <= 1) {
        result.cost = 1.0;
        result.calls = 1;
        return result;
    }
    
    // Recursive Step: Divide scheduling problem into 4 sub-problems of size n / 2
    SimulationResult half_result = simulate_recurrence(n / 2);
    
    // Total recursive calls = current call (1) + calls from all 4 recursive sub-branches
    result.calls = 1 + 4 * half_result.calls;
    
    // Cost calculation: 4 * T(n / 2) + n
    result.cost = 4 * half_result.cost + (double)n;
    
    return result;
}

/**
 * Displays formatted simulation results for a given warehouse size.
 * 
 * @param n Warehouse size to simulate and display
 */
void display_results(long long n) {
    SimulationResult res = simulate_recurrence(n);
    
    printf("==============================================================================\n");
    printf("              INTELLIGENT WAREHOUSE TASK SCHEDULING SIMULATION                \n");
    printf("==============================================================================\n");
    printf("  %-28s : %lld\n", "Warehouse Size (n)", n);
    printf("  %-28s : %llu\n", "Recursive Calls Count", res.calls);
    printf("  %-28s : %.4f\n", "Simulated Cost T(n)", res.cost);
    printf("  %-28s : T(n) = 4T(n/2) + n\n", "Recurrence Used");
    printf("  %-28s : O(n^2) [or Theta(n^2)]\n", "Time Complexity");
    printf("==============================================================================\n\n");
}

/**
 * Displays a benchmark table across multiple power-of-two warehouse sizes.
 */
void run_benchmark_table(void) {
    printf("==============================================================================\n");
    printf("          SCALABILITY BENCHMARK: WAREHOUSE SCHEDULING RECURRENCE              \n");
    printf("==============================================================================\n");
    printf(" %-12s | %-18s | %-20s | %-16s \n", "Warehouse Sz", "Recursive Calls", "Simulated Cost T(n)", "Exact Formula*");
    printf("------------------------------------------------------------------------------\n");
    
    long long sizes[] = {2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
    
    for (int i = 0; i < num_sizes; i++) {
        long long n = sizes[i];
        SimulationResult res = simulate_recurrence(n);
        double exact = 2.0 * n * n - n; // Formula for T(1)=1.0
        printf(" %-12lld | %-18llu | %-20.4f | %-16.4f \n", n, res.calls, res.cost, exact);
    }
    printf("==============================================================================\n");
    printf(" *Exact formula for power-of-2 sizes with T(1)=1: T(n) = 2n^2 - n\n\n");
}

/**
 * Main execution entry point.
 */
int main(int argc, char *argv[]) {
    printf("\n");
    // If warehouse size is passed as command line argument
    if (argc > 1) {
        long long n = atoll(argv[1]);
        if (n < 1) {
            fprintf(stderr, "[Error] Warehouse size n must be >= 1.\n");
            return EXIT_FAILURE;
        }
        display_results(n);
        return EXIT_SUCCESS;
    }
    
    // Otherwise run standard benchmark table and prompt user
    run_benchmark_table();
    
    printf("Enter custom warehouse size n (or press Ctrl+C / EOF to exit): ");
    long long custom_n;
    if (scanf("%lld", &custom_n) == 1) {
        if (custom_n < 1) {
            printf("[Warning] Warehouse size must be >= 1. Using default n = 1024.\n");
            custom_n = 1024;
        }
        printf("\n");
        display_results(custom_n);
    } else {
        printf("\n[Info] No custom input provided. Exiting successfully.\n");
    }
    
    return EXIT_SUCCESS;
}
