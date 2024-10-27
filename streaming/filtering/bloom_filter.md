# Bloom Filters
A *Bloom Filter* is a probabilistic data structure that efficiently tests whether an element is a member of a set. It is used when a certain degree of error in membership testing is acceptable, allowing it to use significantly less memory than traditional methods.

## Problem
For large datasets, determining if an element belongs to a set can require substantial memory. A Bloom Filter addresses this by offering approximate membership testing with controlled false positive rates.

## Algorithm
- Initialize a bit array $B$ of size $m$ with all bits set to $0$.
- Choose $k$ independent hash functions, each producing a number in the range $[0, m-1]$.
- For each element $x$ added to the filter:
    - Compute $k$ hash values for $x$, mapping it to $k$ positions in $B$.
    - Set the bits at these $k$ positions in $B$ to $1$.

- To test if an element $y$ is in the set:
    - Compute k hash values for $y$.
    - Check if all bits at these k positions are set to $1$ in $B$.
    - If yes, then $y$ is likely in the set (with a probability of a false positive).
    - If any bit is $0$, then $y$ is not in the set.

## Analisys
**Define:**
- $n$ as the number of elements inserted in the Bloom Filter.
- $k$ as the number of hash functions.
- $m$ as the size of the bit array.

**False Positive Probability:**
For each hash function, the probability that a particular bit remains $0$ is approximately:

$$
\left(1 - \frac{1}{m}\right)^{k}
$$

Since $m$ is usally large, we can consider:

$$
\lim_{m \to \infty} \left(1 - \frac{1}{m}\right)^{k} = \lim_{m \to \infty} \left(\left(1 - \frac{1}{m}\right)^{m}\right)^{k/m} = e^{-k/m}
$$

If we insert $n$ elements the probability that a bit is $1$ is approximately:

$$
1 - e^{-kn/m}
$$

If we test the membership of an element that is
not in the set, to get a wrong answer we need
to have all $k$ tested bits to be $1$, so the probability
of this event is approximately:

$$
\left(1 - e^{-kn/m}\right)^{k}
$$

By tuning $k$ and $m$ appropriately, we can achieve a desired trade-off between memory usage and the false positive rate.

## Limitations
While Bloom Filters are space-efficient and effective for approximate membership testing, they come with some limitations:

1. **False Positives**: Bloom Filters can incorrectly report that an element is in the set when it is not. The probability of a false positive depends on the size of the filter $m$, the number of hash functions $k$, and the number of elements $n$. False positives can be reduced by increasing $m$ or adjusting $k$, but they can never be completely eliminated.

2. **No Deletion**: In a standard Bloom Filter, once an element is added, it cannot be removed. This is because multiple elements may map to the same bit positions due to hashing. Clearing a bit could inadvertently remove information about other elements.

3. **Sensitivity to Hash Functions**: The performance and accuracy of a Bloom Filter rely on the choice of hash functions. Poorly chosen hash functions can lead to an uneven distribution of bits being set, increasing the false positive rate.

4. **Non-deterministic Memory Usage for Fixed Error Rate**: A Bloom Filter may require more memory than expected for a low false positive rate as the set size grows, and there’s no built-in mechanism to adjust $m$ dynamically.

### Counting Bloom Filters
To address the deletion problem *Counting Bloom Filters* can be used.

- Each entry is not a single bit but rather a small counter
- When an item is inserted, the corresponding
counters are incremented
- When an item is deleted, the corresponding
counters are decremented
