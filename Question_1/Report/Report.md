# Assessment Report: Multi-Source Log Processing System

## 1. Title
**Application:** Multi-Source Log Processing System  
**Recurrence Relation:** \(T(n) = 2T(n/2) + \log_2 n\)  
**Assessment:** CO1 Assessment Tool 1 — Question 1

---

## 2. Aim
To mathematically solve, algorithmically model, and programmatically simulate the time complexity of a divide-and-conquer distributed log processing platform. Specifically, this report aims to apply the **Substitution Method** to derive the asymptotic and exact closed-form time complexity of the recurrence \(T(n) = 2T(n/2) + \log_2 n\), verify the mathematical derivation through a modular C simulation, and analyze the system's performance across large-scale log volumes.

---

## 3. Problem Statement
In modern distributed computing environments, log monitoring platforms ingest massive streams of diagnostic events from diverse server clusters. When processing an input log dataset of size \(n\), the processing engine divides the dataset into **two equal partitions** of size \(n/2\), processes each partition recursively, and merges the results.

During the merging phase, the engine performs **logarithmic synchronization and binary search operations** across indexed log timestamps, incurring a merge overhead of \(\log_2 n\). The total computational time required to process \(n\) log entries is governed by the recurrence relation:

\[
T(n) = \begin{cases} 
c_0 & \text{if } n = 1 \\
2T(n/2) + \log_2 n & \text{if } n > 1 
\end{cases}
\]

Where \(c_0 = 1\) represents the constant base cost to process a single log entry. We must solve this recurrence using the **Substitution Method**, expand it step-by-step down to the base case, derive the asymptotic runtime complexity, and evaluate scalability.

---

## 4. Algorithm
The simulation algorithm implements a recursive divide-and-conquer strategy that mirrors the structural execution of the log processing recurrence while tracking both total operational cost and recursive call metrics.

### Step-by-Step Procedure:
1. **Input Validation:** Accept the total log volume size \(n\) from the user or command-line parameters. Verify that \(n \ge 1\).
2. **Base Case Check:** If \(n \le 1\), return the base operational cost \(T(1) = 1.0\) and increment the function invocation counter by \(1\).
3. **Recursive Partitioning:** Divide the problem into two subproblems of size \(\lfloor n/2 \rfloor\).
4. **Left Sub-branch Execution:** Recursively invoke `simulate_recurrence(n / 2)` to compute the cost and calls for the left log partition.
5. **Right Sub-branch Execution:** Recursively invoke `simulate_recurrence(n / 2)` to compute the cost and calls for the right log partition.
6. **Merge Cost Computation:** Calculate the logarithmic overhead \(\log_2(n)\) for merging and synchronizing the partitions.
7. **Cost Aggregation:** Compute the total simulated cost as:  
   `total_cost = left_cost + right_cost + log2(n)`
8. **Call Counter Aggregation:** Sum the invocation counts across current and child branches:  
   `total_calls = 1 + left_calls + right_calls`
9. **Return & Display:** Return the aggregated simulation metrics and format them into an analytical summary table.

---

## 5. Pseudo Code
```pascal
STRUCTURE SimulationResult:
    DOUBLE total_cost
    INTEGER total_calls

FUNCTION SimulateLogProcessing(INTEGER n, POINTER TO INTEGER call_counter):
    // Increment global invocation counter
    call_counter^ <- call_counter^ + 1
    
    // Base Case: processing a single log entry takes constant time
    IF n <= 1 THEN
        RETURN 1.0
    END IF
    
    // Divide phase: split into left and right halves
    INTEGER left_calls <- 0
    INTEGER right_calls <- 0
    
    DOUBLE left_cost <- SimulateLogProcessing(n / 2, ADDRESS OF left_calls)
    DOUBLE right_cost <- SimulateLogProcessing(n / 2, ADDRESS OF right_calls)
    
    // Aggregate recursive calls across subtrees
    call_counter^ <- call_counter^ + left_calls + right_calls
    
    // Merge phase: logarithmic search and synchronization work
    DOUBLE merge_work <- LOG_BASE_2(n)
    
    // Recurrence combination
    DOUBLE total_cost <- left_cost + right_cost + merge_work
    RETURN total_cost
END FUNCTION

PROCEDURE Main():
    INTEGER n <- ReadUserInput("Enter log volume size n: ")
    INTEGER total_calls <- 0
    DOUBLE cost <- SimulateLogProcessing(n, ADDRESS OF total_calls)
    
    PRINT "Input Size (n): ", n
    PRINT "Recursive Calls: ", total_calls
    PRINT "Simulated Cost: ", cost
    PRINT "Recurrence: T(n) = 2T(n/2) + log_2(n)"
    PRINT "Time Complexity: O(n) or Theta(n)"
END PROCEDURE
```

---

## 6. Flow Explanation
The execution flow progresses through distinct phases:
1. **Initialization Phase:** The program parses input parameters. If no command-line arguments are provided, it generates an automated benchmark table across powers of two (\(n = 2, 4, 8, \dots, 1048576\)) before prompting the user for interactive evaluation.
2. **Recursive Decomposition Phase:** When `simulate_recurrence(n)` is called, the function immediately increments the call counter. For \(n > 1\), it creates two recursive activation records on the system call stack, passing \(n/2\) to each branch.
3. **Execution Tree Expansion:** This branching process creates a complete binary tree of recursive calls. At depth \(i\), there are exactly \(2^i\) active subproblems, each operating on a log partition of size \(n / 2^i\).
4. **Base Case Termination:** The recursion terminates at depth \(k = \log_2 n\), where \(2^k = n\) subproblems each receive an input size of \(n / 2^k = 1\). Each leaf returns the base cost \(T(1) = 1.0\).
5. **Bottom-Up Aggregation Phase:** As the recursion unwinds, each parent node receives `left_cost` and `right_cost`, adds the local logarithmic overhead \(\log_2(n_{current})\), and propagates the combined total upward.
6. **Final Verification:** The root call returns the exact numerical value of \(T(n)\) along with the total count of recursive nodes visited (\(2n - 1\)), which is presented alongside analytical asymptotic complexity bounds.

---

## 7. Substitution Method

We apply the **Substitution Method (Iteration/Expansion Technique)** to solve the recurrence relation:
\[
T(n) = 2T\left(\frac{n}{2}\right) + \log_2 n
\]

### Step-by-Step Expansion:
Without loss of generality, assume \(n\) is a power of 2 (\(n = 2^k\)), so \(k = \log_2 n\).

**Iteration 1 (Initial Equation):**
\[
T(n) = 2T\left(\frac{n}{2}\right) + \log_2 n
\]

**Iteration 2 (Substitute \(T(n/2) = 2T(n/4) + \log_2(n/2)\)):**
\[
T(n) = 2 \left[ 2T\left(\frac{n}{4}\right) + \log_2\left(\frac{n}{2}\right) \right] + \log_2 n
\]
\[
T(n) = 4T\left(\frac{n}{4}\right) + 2\log_2\left(\frac{n}{2}\right) + \log_2 n
\]

**Iteration 3 (Substitute \(T(n/4) = 2T(n/8) + \log_2(n/4)\)):**
\[
T(n) = 4 \left[ 2T\left(\frac{n}{8}\right) + \log_2\left(\frac{n}{4}\right) \right] + 2\log_2\left(\frac{n}{2}\right) + \log_2 n
\]
\[
T(n) = 8T\left(\frac{n}{8}\right) + 4\log_2\left(\frac{n}{4}\right) + 2\log_2\left(\frac{n}{2}\right) + \log_2 n
\]

**General Form after \(i\) Iterations:**
\[
T(n) = 2^i T\left(\frac{n}{2^i}\right) + \sum_{j=0}^{i-1} 2^j \log_2\left(\frac{n}{2^j}\right)
\]

### Reaching the Base Case:
The recursion terminates when the subproblem size reaches 1:
\[
\frac{n}{2^i} = 1 \implies 2^i = n \implies i = k = \log_2 n
\]

Substituting \(i = \log_2 n\) and \(2^i = n\) into the general form:
\[
T(n) = n T(1) + \sum_{j=0}^{k-1} 2^j \log_2\left(\frac{n}{2^j}\right)
\]

Since \(n = 2^k\), we can simplify the logarithm inside the summation:
\[
\log_2\left(\frac{n}{2^j}\right) = \log_2(2^{k-j}) = k - j
\]

Thus, the summation becomes:
\[
T(n) = n T(1) + \sum_{j=0}^{k-1} 2^j (k - j)
\]

### Evaluating the Summation:
Let \(S = \sum_{j=0}^{k-1} (k - j) 2^j\). Writing out the terms:
\[
S = k(2^0) + (k-1)(2^1) + (k-2)(2^2) + \dots + 1(2^{k-1})
\]

Multiply both sides by 2:
\[
2S = k(2^1) + (k-1)(2^2) + (k-2)(2^3) + \dots + 1(2^k)
\]

Subtract \(S\) from \(2S\):
\[
2S - S = -k(2^0) + \left[ (k - (k-1))2^1 + ((k-1) - (k-2))2^2 + \dots + (2-1)2^{k-1} \right] + 1(2^k)
\]
\[
S = -k + \left( 2^1 + 2^2 + 2^3 + \dots + 2^{k-1} \right) + 2^k
\]
\[
S = -k + \sum_{j=1}^{k} 2^j
\]

Using the geometric series sum \(\sum_{j=1}^{k} 2^j = 2^{k+1} - 2\):
\[
S = -k + (2^{k+1} - 2) = 2 \cdot 2^k - k - 2 = 2n - \log_2 n - 2
\]

### Deriving the Exact Closed-Form and Asymptotic Complexity:
Substituting \(S\) back into \(T(n)\) with base cost \(T(1) = 1\):
\[
T(n) = n(1) + 2n - \log_2 n - 2
\]
\[
T(n) = 3n - \log_2 n - 2
\]

**Asymptotic Interpretation:**
As \(n \to \infty\), the linear term \(3n\) strictly dominates the logarithmic term \(-\log_2 n\) and constant term \(-2\). Therefore:
\[
T(n) = \Theta(n) \quad \text{and} \quad T(n) = O(n)
\]

Even though logarithmic work is performed at each level during the merge step, the total cost remains **linear** because the work per subproblem diminishes rapidly as we descend the recursion tree, dominating total cost at the leaf nodes.

---

## 8. Complexity Analysis

| Metric | Asymptotic Bound | Exact Mathematical Formula (for \(n=2^k\)) | Explanation |
| :--- | :--- | :--- | :--- |
| **Time Complexity** | \(\Theta(n)\) or \(O(n)\) | \(T(n) = 3n - \log_2 n - 2\) | Total operations scale linearly with log volume. Leaf evaluations (\(n\)) plus internal merge overhead (\(2n - \log_2 n - 2\)) yield linear cost. |
| **Space Complexity** | \(\Theta(\log n)\) or \(O(\log n)\) | \(S(n) = \log_2 n + 1\) stack frames | Auxiliary memory is consumed entirely by the recursive call stack. Maximum recursion depth equals \(\log_2 n\). |
| **Recursive Calls Count**| \(\Theta(n)\) | \(C(n) = 2n - 1\) | A complete binary tree with \(n\) leaves has exactly \(n - 1\) internal nodes, totaling \(2n - 1\) function calls. |

---

## 9. Application Analysis

### Domain Relevance:
In distributed systems (e.g., Apache Kafka clusters, Elasticsearch ingestion pipelines, distributed syslogs), processing gigabytes of raw log data requires parallel partitioning. When logs are split across \(2^k\) nodes, each node filters or indexes local chunks in constant/linear time, after which hierarchical aggregation nodes perform binary search synchronizations (\(\log_2 n\) work) to merge sorted timestamp indices.

### Advantages:
1. **Highly Scalable Linear Performance:** Achieving \(\Theta(n)\) total time means doubling the log volume only doubles processing time, avoiding exponential or quadratic bottlenecking during merge phases.
2. **Minimal Stack Memory Footprint:** With a space complexity of \(O(\log n)\), processing \(1,000,000\) log entries requires fewer than 21 stack frames, preventing stack overflow errors even under heavy loads.
3. **Parallelization Friendly:** Because the two recursive subproblems \(2T(n/2)\) are completely independent, they can be distributed across multi-core CPUs or worker nodes with zero race conditions.

### Limitations:
1. **Recursion Overhead:** For very small log volumes (\(n < 64\)), the constant-factor overhead of function call stack frame allocation can exceed the cost of simple iterative processing.
2. **Assumes Equal Partitioning:** If the log data partition is skewed (e.g., \(T(n) = T(n-1) + T(1) + \log n\)), the runtime degrades from \(O(n)\) to \(O(n^2)\).

---

## 10. Sample Input
```text
1024
```

---

## 11. Sample Output
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

---

## 12. Conclusion
The rigorous application of the **Substitution Method** proves that the recurrence \(T(n) = 2T(n/2) + \log_2 n\) converges to a linear asymptotic time complexity of **\(\Theta(n)\)**. The exact closed-form expression \(T(n) = 3n - \log_2 n - 2\) was successfully validated through C simulation across all powers of two up to \(n = 1,048,576\). This analysis confirms that distributed log processing architectures utilizing logarithmic merge synchronization scale efficiently across massive enterprise log streams.
