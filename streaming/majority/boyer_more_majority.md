# Boyer-Moore Algorithm for Finding Majority Elements

The Boyer-Moore Voting Algorithm is an efficient algorithm for finding the majority element in a sequence of elements. A majority element is defined as the element that appears more than $⌊n/2⌋$ times in the sequence, where n is the total number of elements. The algorithm was introduced by Robert Boyer and J Strother Moore in 1981 and is particularly valued for its linear time complexity and constant space usage.

## Problem
Given a sequence of objects, we want to identify the majority element efficiently, particularly when the sequence is large and memory is constrained.

## Limitations of the Boyer-Moore Algorithm
The algorithm only works correctly if there is an element that appears more than $⌊n/2⌋$ times in the input sequence. If no such element exists, the algorithm may return a candidate that is not actually a majority element.
### Validation
The algorithm processes the elements in one pass to find a candidate. 

However, a second validation pass is necessary to confirm whether the candidate is indeed the majority element.

Since we have to scan twice the stream it's semi-streaming.


## Algorithm
- Initialize a candidate variable candidate and a counter variable count to 0.
- For each element in the sequence:
    - If count is 0, assign the current element to candidate and set count to 1.
    - If the current element is equal to candidate, increment count.
    - If the current element is not equal to candidate, decrement count.

After processing all elements, validate the candidate by counting its occurrences in the sequence.