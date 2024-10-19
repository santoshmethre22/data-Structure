#include <iostream>
#include <vector>

using namespace std;

const int MAX = 5000000;
vector<int> primes;
bool is_prime[MAX + 1];

// Function to perform the Sieve of Eratosthenes
void sieve() {
    fill(is_prime, is_prime + MAX + 1, true); // Initialize the sieve array
    is_prime[0] = is_prime[1] = false; // 0 and 1 are not primes

    for (int i = 2; i * i <= MAX; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= MAX; j += i) {
                is_prime[j] = false;
            }
        }
    }

    // Collect all the primes in the 'primes' vector
    for (int i = 2; i <= MAX; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
}

int main() {
    // Step 1: Precompute all primes up to 5,000,000
    sieve();

    // Step 2: Read the number of queries
    int Q;
    cin >> Q;

    // Step 3: For each query, return the Kth prime number
    while (Q--) {
        int K;
        cin >> K;
        cout << primes[K - 1] << endl; // K-1 because primes are 0-indexed in the vector
    }

    return 0;
}
