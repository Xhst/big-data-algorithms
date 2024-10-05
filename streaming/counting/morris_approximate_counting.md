# Morris' algorithm for approximate counting

Morris' algorithm is a space-efficient method for approximate counting. It was developed by Robert Morris in 1977, and its main goal is to maintain a count (or estimate the number of occurrences of an element) using logarithmic space rather than the linear space required by traditional counters.

## Problem
A huge sequence of objects arrives and a small memory is available, we want to count the occurrences.

## Algorithm
- Start the counter $X$ with value 0.
- When an element arrives increase $X$ by $1$ with probability $\frac{1}{2^X}$

## Analysis

$\color{lightgreen}\text{Define:}$ $X_n$ as the value of $X$ after $n$ elements.

##

$\color{lightblue}\text{Claim:}$ $E[2^{X_n}] = n + 1$

##

$\color{orange}\text{Proof:}$

$\small\color{gray}\text{Basis of the induction:}$

With $n = 0$ we have $X = 0$

$E[2^{X_0}] = 1 = n + 1$

$\small\color{gray}\text{By definition of Expected value:}$

$E[2^{X_n}] = \sum_i 2^i \cdot Pr[X_n = i]$ 

$\small\color{gray}\text{Probability of } Pr[X_n = i]: $


$Pr[X_n = i] = Pr[𝑋 \text{ is incremented } \land X_{n-1} = i - 1] + Pr[𝑋 \text{ is not incremented } \land X_{n-1} = i] = \frac{1}{2^{i-1}}Pr[X_{n-1} = i - 1] + (1 - \frac{1}{2^i})Pr[X_{n-1}=i] $

$\small\color{gray}\text{Then we have:}$

$E[2^{X_n}] = \sum_i 2^i \cdot \left( \frac{1}{2^{i-1}}Pr[X_{n-1} = i - 1] + (1 - \frac{1}{2^i})Pr[X_{n-1}=i] \right)$

$\small\color{gray}\text{By splitting the sum:}$

$E[2^{X_n}] = \sum_i 2 \cdot Pr[X_{n-1} = i - 1] + \sum_i 2^i \cdot Pr[X_{n-1} = i] - \sum_i Pr[X_{n-1} = i] $

$\small\color{gray}\text{The sum of all probabilities is 1, so we have:}$

$E[2^{X_n}] = 2 + \sum_i 2^i \cdot Pr[X_{n-1} = i] - 1 =  + E[2^{X_n-1}]+1$

$\small\color{gray}\text{By applying the inductive hypothesis:}$

$E[2^{X_n}] = ((n-1)+1)+1 = n+1$

