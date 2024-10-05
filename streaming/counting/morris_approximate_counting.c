/**
 * Morris' algorithm for approximate counting.
 * 
 * The algorithm is used to estimate the number of elements in a stream, without storing the entire stream.
 * The algorithm works by randomly sampling elements from the stream and updating a counter based on the sampled elements.
 * The final count is an approximation of the true count of elements in the stream.
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Function to simulate a random event increment
int should_increment(double probability) {
    return (rand() / (RAND_MAX + 1.0)) < probability;
}

// Morris' approximate counting algorithm
void morris_algorithm(int elements) {

    // Initialize counter X
    int X = 0; 

    for (int i = 0; i < elements; i++) {
        // Compute the probability to increment
        double probability = 1.0 / (pow(2, X));
        
        // Check if we should increment the counter
        if (should_increment(probability)) {
            X++;
        }
        
        printf("Element %d -> X: %d, Estimated Count: %.2f\n", i + 1, X, pow(2, X) - 1);
    }
}

int main() {
    srand(time(0));

    int num_elements;
    printf("Enter number of elements: ");
    scanf("%d", &num_elements);

    // Run Morris' algorithm
    morris_algorithm(num_elements);

    return 0;
}
