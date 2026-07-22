# Assessment Report: Intelligent Warehouse Automation System

## 1. Title
**Application:** Intelligent Warehouse Automation System  
**Recurrence Relation:** \(T(n) = 4T(n/2) + n\)  
**Assessment:** CO1 Assessment Tool 1 — Question 2

---

## 2. Aim
To mathematically evaluate, algorithmically model, and programmatically simulate the time complexity of a recursive task scheduling engine for an autonomous warehouse automation system. Specifically, this report aims to apply the **Master Theorem** to solve the recurrence relation \(T(n) = 4T(n/2) + n\), verify the theoretical derivation against a modular C simulation, and analyze how robotic scheduling performance scales across expanding physical warehouse grid dimensions.

---

## 3. Problem Statement
Modern automated fulfillment centers utilize autonomous mobile robots (AMRs) and robotic sorting arms across large physical grids. When scheduling coordinated tasks across a warehouse grid of size \(n\) (where \(n\) represents spatial scheduling zones or task parcels), the central orchestration engine divides the workspace into **4 spatial sub-quadrants of size \(n/2\)**, schedules robotic paths within each sub-quadrant recursively, and incurs a linear overhead \(f(n) = n\) at each hierarchy level for global collision checking and path synchronization.

The total computational overhead required to schedule tasks across a warehouse of size \(n\) is governed by the recurrence relation:

\[
T(n) = \begin{cases} 
c_0 & \text{if } n = 1 \\
4T(n/2) + n & \text{if } n > 1 
\end{cases}
\]

Where \(c_0 = 1\) represents the constant base scheduling cost for a single unit cell. We must apply the **Master Theorem** to classify the recurrence, compute the critical exponent, derive the exact asymptotic complexity, and analyze system scalability.

---

## 4. Algorithm
The simulation algorithm implements a recursive spatial decomposition strategy that tracks both total scheduling operational cost and recursive call metrics across the four quadrant sub-branches.

### Step-by-Step Procedure:
1. **Input Validation:** Read the warehouse grid size \(n\) from user input or command parameters. Ensure \(n \ge 1\).
2. **Base Case Check:** If \(n \le 1\), return the base cell cost \(T(1) = 1.0\) and increment the function call counter by \(1\).
3. **Quadrant Subdivision:** Divide the warehouse grid into \(4\) sub-quadrants, each operating on problem size \(\lfloor n/2 \rfloor\).
4. **Recursive Execution Loop:** Iterate \(i = 0\) to \(3\):
   - Recursively invoke `simulate_recurrence(n / 2)` to compute the cost and call count for quadrant \(i\).
   - Accumulate the returned calls into the global call tracking pointer.
5. **Non-Recursive Overhead Addition:** Compute the linear synchronization overhead across the current grid level:  
   `non_recursive_work = n`
6. **Cost Aggregation:** Sum the costs from all \(4\) quadrants and add the linear overhead:  
   `total_cost = branch_costs[0] + branch_costs[1] + branch_costs[2] + branch_costs[3] + n`
7. **Return & Display:** Return the aggregated cost and display formatted analytical tables comparing simulated results against theoretical derivations.

---

## 5. Pseudo Code
```pascal
STRUCTURE SimulationResult:
    DOUBLE total_cost
    INTEGER total_calls

FUNCTION SimulateWarehouseScheduling(INTEGER n, POINTER TO INTEGER call_counter):
    // Increment global invocation counter upon entry
    call_counter^ <- call_counter^ + 1
    
    // Base Case: scheduling a single warehouse cell takes constant time
    IF n <= 1 THEN
        RETURN 1.0
    END IF
    
    // Divide phase: split grid into 4 sub-quadrants of size n / 2
    INTEGER branch_calls[4] <- {0, 0, 0, 0}
    DOUBLE branch_costs[4] <- {0.0, 0.0, 0.0, 0.0}
    
    FOR i FROM 0 TO 3 DO
        branch_costs[i] <- SimulateWarehouseScheduling(n / 2, ADDRESS OF branch_calls[i])
        call_counter^ <- call_counter^ + branch_calls[i]
    END FOR
    
    // Combine phase: linear collision synchronization overhead f(n) = n
    DOUBLE non_recursive_work <- n
    
    // Recurrence combination: T(n) = 4T(n/2) + n
    DOUBLE total_cost <- non_recursive_work
    FOR i FROM 0 TO 3 DO
        total_cost <- total_cost + branch_costs[i]
    END FOR
    
    RETURN total_cost
END FUNCTION

PROCEDURE Main():
    INTEGER n <- ReadUserInput("Enter warehouse size n: ")
    INTEGER total_calls <- 0
    DOUBLE cost <- SimulateWarehouseScheduling(n, ADDRESS OF total_calls)
    
    PRINT "Warehouse Size (n): ", n
    PRINT "Recursive Calls: ", total_calls
    PRINT "Simulated Cost: ", cost
    PRINT "Recurrence: T(n) = 4T(n/2) + n"
    PRINT "Time Complexity: O(n^2) or Theta(n^2)"
END PROCEDURE
```

---

## 6. Flow Explanation
The runtime execution flow progresses through systematic spatial division:
1. **Benchmark Initialization:** When launched without arguments, the program executes an automated power-of-two scalability suite (\(n = 2, 4, \dots, 4096\)) to illustrate quadratic growth before transitioning to interactive input mode.
2. **Quad-Tree Execution Structure:** Every recursive invocation on grid size \(n > 1\) spawns exactly \(4\) child function calls of size \(n/2\). This forms a complete **Quad-Tree (4-ary tree)** rather than a standard binary tree.
3. **Explosive Branching Growth:** At depth \(i\) in the recursion tree, the number of active nodes multiplies by \(4^i\). At the same time, the problem size at depth \(i\) shrinks by \(2^i\).
4. **Base Case Leaf Evaluation:** At tree depth \(k = \log_2 n\), the number of leaf nodes reaches \(4^{\log_2 n} = (2^2)^{\log_2 n} = (2^{\log_2 n})^2 = n^2\). Each of these \(n^2\) leaf nodes evaluates a single unit cell (\(n=1\)) in constant time \(T(1) = 1.0\).
5. **Unwinding and Aggregation:** As the recursion returns upward from the leaves, each parent node aggregates the 4 child costs and adds the local linear synchronization cost \(n_{current}\).
6. **Final Output Verification:** The root function call returns the total cost (\(2n^2 - n\)) and the exact count of nodes visited (\(\frac{4n^2 - 1}{3}\)), confirming the quadratic asymptotic behavior predicted by the Master Theorem.

---

## 7. Master Theorem Analysis

We apply the **Master Theorem for Divide-and-Conquer Recurrences** to solve the warehouse scheduling recurrence:
\[
T(n) = aT\left(\frac{n}{b}\right) + f(n)
\]

### Step 1: Identify Parameters
Comparing our recurrence \(T(n) = 4T(n/2) + n\) with the canonical Master Theorem form:
- **\(a = 4\)** : The number of subproblems (branching factor into 4 sub-quadrants).
- **\(b = 2\)** : The factor by which the input size is divided (each sub-quadrant has half the width/length of the parent grid).
- **\(f(n) = n\)** : The cost of the work done outside the recursive calls (linear collision synchronization overhead).

### Step 2: Compute the Critical Exponent \(n^{\log_b a}\)
We determine the watershed function that represents the total cost of the base cases at the bottom of the recursion tree:
\[
n^{\log_b a} = n^{\log_2 4}
\]
Since \(4 = 2^2\), we have \(\log_2 4 = 2\). Therefore:
\[
n^{\log_b a} = n^2
\]

### Step 3: Identify the Correct Master Theorem Case
We compare the non-recursive overhead \(f(n) = n\) with the critical exponent function \(n^{\log_b a} = n^2\):

According to the Master Theorem:
- **Case 1:** If \(f(n) = O(n^{\log_b a - \epsilon})\) for some constant \(\epsilon > 0\), then \(T(n) = \Theta(n^{\log_b a})\).
- **Case 2:** If \(f(n) = \Theta(n^{\log_b a} \log^k n)\) for \(k \ge 0\), then \(T(n) = \Theta(n^{\log_b a} \log^{k+1} n)\).
- **Case 3:** If \(f(n) = \Omega(n^{\log_b a + \epsilon})\) for some constant \(\epsilon > 0\) and the regularity condition holds, then \(T(n) = \Theta(f(n))\).

Let us check **Case 1**:
We need to determine if \(f(n) = n\) is polynomially smaller than \(n^2\). Setting \(\epsilon = 1 > 0\):
\[
n^{\log_b a - \epsilon} = n^{2 - 1} = n^1 = n
\]
Since \(f(n) = n = O(n^{2 - 1})\), we confirm that \(f(n)\) grows **polynomially slower** than the leaf count \(n^2\) by a factor of \(n^\epsilon = n^1\).

Thus, **Case 1 of the Master Theorem applies strictly.**

### Step 4: Derive the Final Complexity
By Case 1 of the Master Theorem, the time complexity is dominated by the cost of the leaf nodes:
\[
T(n) = \Theta(n^{\log_b a}) = \Theta(n^2)
\]
In standard asymptotic notation:
\[
T(n) = \Theta(n^2) \quad \text{and} \quad T(n) = O(n^2)
\]

**Exact Closed-Form Verification:**
For powers of two (\(n = 2^k\)) with base cost \(T(1) = 1\), summing across all \(k\) levels yields:
\[
T(n) = 4^k T(1) + \sum_{j=0}^{k-1} 4^j \left(\frac{n}{2^j}\right) = n^2(1) + n \sum_{j=0}^{k-1} 2^j = n^2 + n(2^k - 1) = n^2 + n(n - 1) = 2n^2 - n
\]
This exact analytical derivation perfectly matches our simulation and verifies that \(T(n) = \Theta(n^2)\).

---

## 8. Complexity Analysis

| Metric | Asymptotic Bound | Exact Mathematical Formula (for \(n=2^k\)) | Explanation |
| :--- | :--- | :--- | :--- |
| **Time Complexity** | \(\Theta(n^2)\) or \(O(n^2)\) | \(T(n) = 2n^2 - n\) | The quad-tree branching factor (\(a=4\)) overwhelms the division rate (\(b=2\)), creating \(n^2\) leaf evaluations that dominate total runtime. |
| **Space Complexity** | \(\Theta(\log n)\) or \(O(\log n)\) | \(S(n) = \log_2 n + 1\) stack frames | Memory is bounded by the maximum depth of the quad-tree recursion stack, which equals \(\log_2 n\). |
| **Recursive Calls Count**| \(\Theta(n^2)\) | \(C(n) = \frac{4n^2 - 1}{3}\) | A complete 4-ary quad-tree of height \(k=\log_2 n\) has \(\sum_{i=0}^k 4^i = \frac{4^{k+1}-1}{3} = \frac{4n^2-1}{3}\) total calls. |

---

## 9. Application Analysis

### Domain Relevance:
In warehouse fulfillment automation (e.g., Amazon Robotics, automated storage and retrieval systems), scheduling physical robot trajectories across a 2D grid requires spatial partitioning. Splitting the grid into 4 quadrants allows localized optimization, but if every sub-quadrant spawns 4 recursive tasks (`4T(n/2)`), the computational cost explodes quadratically (\(\Theta(n^2)\)) due to the surface area of the grid cells (\(n \times n\)).

### Advantages:
1. **Comprehensive Spatial Coverage:** Quad-tree recursive partitioning guarantees that every spatial sub-region and intersection in the warehouse grid is evaluated for robotic path coordination.
2. **High Memory Efficiency:** Despite the quadratic runtime (\(O(n^2)\)), the auxiliary call stack remains extremely lightweight (\(O(\log n)\)), requiring negligible RAM even when scheduling millions of cells.
3. **Structured Divide-and-Conquer Hierarchy:** Quad-tree data structures naturally align with 2D spatial coordinates, simplifying localized pathfinding and robotic zone assignments.

### Limitations:
1. **Quadratic Scaling Bottleneck:** Because the runtime grows as \(O(n^2)\), doubling the warehouse grid dimensions increases scheduling computation time by **400% (a factor of 4)**. For large warehouses (\(n > 65,536\)), real-time scheduling becomes computationally prohibitive on single-core systems.
2. **High Call Stack Volume:** Generating \(\approx 1.33 n^2\) function invocations causes significant context-switch and stack allocation overhead compared to iterative bottom-up dynamic programming approaches.

---

## 10. Sample Input
```text
1024
```

---

## 11. Sample Output
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

## 12. Conclusion
The rigorous application of **Case 1 of the Master Theorem** proves that the warehouse task scheduling recurrence \(T(n) = 4T(n/2) + n\) converges to a quadratic asymptotic time complexity of **\(\Theta(n^2)\)**. The exact closed-form expression \(T(n) = 2n^2 - n\) and exact call count \(C(n) = \frac{4n^2-1}{3}\) were successfully verified through C simulation across all powers of two up to \(n = 4,096\). This analysis underscores that quad-tree spatial partitioning in 2D warehouse grids introduces a quadratic computational bottleneck that must be managed as physical warehouse dimensions expand.
