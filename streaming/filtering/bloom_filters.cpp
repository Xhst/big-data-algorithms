#include <iostream>
#include <vector>
#include <string>
#include <functional>

class BloomFilter {
public:
    BloomFilter(int size, int numHashes) : m_bits(size), m_numHashes(numHashes) {}

    template <typename T>
    void addElement(const T& element) {
        for (int i = 0; i < m_numHashes; i++) {
            int hash = hashElement(element, i);

            m_bits[hash % m_bits.size()] = true;
        }
    }

    template <typename T>
    bool possiblyContains(const T& element) const {
        for (int i = 0; i < m_numHashes; i++) {
            int hash = hashElement(element, i);

            if (!m_bits[hash % m_bits.size()]) {
                return false;
            }
        }
        return true;
    }

private:
    std::vector<bool> m_bits;
    int m_numHashes;

    template <typename T>
    int hashElement(T element, int i) const {
        std::hash<typename std::decay<T>::type> hash;
        return static_cast<int>(hash(element) ^ (i * 0x9e3779b9)); 
    }
};

class CountingBloomFilter {
public:
    CountingBloomFilter(int size, int numHashes) : m_counts(size, 0), m_numHashes(numHashes) {}

    template <typename T>
    void addElement(const T& element) {
        for (int i = 0; i < m_numHashes; i++) {
            int hash = hashElement(element, i);

            m_counts[hash % m_counts.size()]++;
        }
    }

    template <typename T>
    bool possiblyContains(const T& element) const {
        for (int i = 0; i < m_numHashes; i++) {
            int hash = hashElement(element, i);

            if (m_counts[hash % m_counts.size()] == 0) {
                return false;
            }
        }
        return true;
    }

    template <typename T>
    void removeElement(const T& element) {
        for (int i = 0; i < m_numHashes; i++) {
            int hash = hashElement(element, i);

            if (m_counts[hash % m_counts.size()] > 0) {
                m_counts[hash % m_counts.size()]--;
            }
        }
    }

private:
    std::vector<int> m_counts;
    int m_numHashes;

    template <typename T>
    int hashElement(T element, int i) const {
        std::hash<typename std::decay<T>::type> hash;
        return static_cast<int>(hash(element) ^ (i * 0x9e3779b9));
    }
};

int main() {
    std::vector<std::string> good_elements = { "apple", "banana", "pomegranate" };

    BloomFilter bloomFilter(32, 3);
    CountingBloomFilter countingBloomFilter(32, 3);

    for (const std::string& element : good_elements) {
        bloomFilter.addElement(element);
        countingBloomFilter.addElement(element);
    }

    std::vector<std::string> test_elements = { "apple", "banana", "pomegranate", "cherry", "date", "berry", "fig", "grape", "orange" };

    for (const std::string& element : test_elements) {
        std::cout << "Bloom filter possibly contains " << element << ": " << bloomFilter.possiblyContains(element) << std::endl;
        std::cout << "Counting bloom filter possibly contains " << element << ": " << countingBloomFilter.possiblyContains(element) << std::endl;
    }

    countingBloomFilter.removeElement("pomegranate");

    std::cout << "Testing pomegranate after removal: " << countingBloomFilter.possiblyContains("pomegranate") << std::endl;

    return 0;
}
