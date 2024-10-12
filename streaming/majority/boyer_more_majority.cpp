#include <iostream>
#include <sstream>
#include <random>
#include <vector>

class BoyerMoreMajority {
public:
    BoyerMoreMajority() : m_candidate(-1), m_count(0) {}

    void processElement(int element) {
        if (m_count == 0) {
            m_candidate = element;
            m_count = 1;
        } else if (m_candidate == element) {
            m_count++;
        } else {
            m_count--;
        }
    }

    int getMajority() {
        return m_candidate;
    }

    bool validateMajority(const std::vector<int>& stream) {
        int count = 0;
        for (int num : stream) {
            if (num == m_candidate) {
                count++;
            }
        }
        return count > stream.size() / 2;
    }

private:
    int m_candidate;
    int m_count;
};

int main() {
    BoyerMoreMajority boyerMoreMajority;

    const int num_elements = 20;
    std::vector<int> stream; 


    std::random_device rd;
    std::mt19937 gen(rd());

    // Generate a stream of random elements 
    std::uniform_int_distribution<> dis(0, 1); 

    for (int i = 0; i < num_elements; i++) {
        int element = dis(gen); 
        boyerMoreMajority.processElement(element);
        stream.push_back(element); 
    }

    // Output the generated stream of elements
    std::cout << "Stream of elements: ";
    for (int num : stream) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Validate and print the majority element
    if (boyerMoreMajority.validateMajority(stream)) {
        std::cout << "Majority element: " << boyerMoreMajority.getMajority() << std::endl;
    } else {
        std::cout << "No majority element found." << std::endl;
    }

    return 0;
}
