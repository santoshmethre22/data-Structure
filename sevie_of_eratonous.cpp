/*To generate all prime numbers between two given numbers 
𝐿
L and 
𝑅
R, we can use the Sieve of Eratosthenes. However, for large ranges, we can optimize it using a technique called Segmented Sieve. Here’s how you can implement it:

Steps:
Generate all prime numbers up to 
𝑅
R
  using the simple Sieve of Eratosthenes.
Use these primes to mark non-prime numbers in the range 
[
𝐿
,
𝑅
]
[L,R].*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Helper function to generate primes up to sqrt(R) using Simple Sieve

//---------this is the sieve of eratonous theorem
vector<int> simpleSieve(int limit) {
    vector<bool> sieve(limit + 1, true);
    sieve[0] = sieve[1] = false;
    vector<int> primes;

    for (int num = 2; num <= limit; ++num) {
        if (sieve[num]) {
            primes.push_back(num);
            for (int multiple = num * num; multiple <= limit; multiple += num) {
                sieve[multiple] = false;
            }
        }
    }

    return primes;
}

vector<int> seive_of_(int t){
    vector<bool>isprime(t+1,true);
    for(int i=2;i<sqrt(t);i++){
        
        for(int j=i*i;j<=t;j++){
            if(isprime[i]) isprime[i]=false;
        }

    }

    vector<int>ans;
    for(int i=2;i<=t;i++){
        if(isprime[i]){
            ans.push_back(i);
        }
    }
return ans;


}

// Function to generate all primes in the range [L, R]
vector<int> segmentedSieve(int L, int R) {
    int limit = sqrt(R) + 1;
    
    // Step 1: Get all primes up to sqrt(R)
    vector<int> primes = simpleSieve(limit);

    // Step 2: Create a boolean array for range [L, R] initialized as true
    vector<bool> isPrime(R - L + 1, true);

    // Step 3: Mark multiples of each prime in the range [L, R]
    for (int prime : primes) {
        // Find the minimum number in [L, R] that is a multiple of prime
        int start = max(prime * prime, (L + prime - 1) / prime * prime);

        for (int j = start; j <= R; j += prime) {
            isPrime[j - L] = false;
        }
    }

    // Special case: If L is 1, mark it as non-prime
    if (L == 1) {
        isPrime[0] = false;
    }

    // Step 4: Collect all primes from the range [L, R]
    vector<int> primesInRange;
    for (int i = 0; i <= R - L; ++i) {
        if (isPrime[i]) {
            primesInRange.push_back(i + L);
        }
    }

    return primesInRange;
}

// Main function
int main() {
    int L, R;
    cout << "Enter the range [L, R]: ";
    cin >> L >> R;

    // Get all prime numbers in the range [L, R]
    vector<int> primes = segmentedSieve(L, R);

    // Output the primes
    cout << "Prime numbers between " << L << " and " << R << ": ";
    for (int prime : primes) {
        cout << prime << " ";
    }
    cout << endl;

    return 0;
}
