#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> sieve(int limit) {
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

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    int maxN = INT_MIN;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        maxN = max(maxN, nums[i]);
    }

    // Generate primes up to the maximum number in the input array
    vector<int> ans = sieve(maxN);

    // Calculate the maximum length of consecutive increasing primes
    int l = 1;
    int maxL = 1;
    int m = ans.size();
    
    for (int i = 1; i < m; i++) {
        if (ans[i] == ans[i-1] + 1) {
            l++;
        } else {
            maxL = max(maxL, l);
            l = 1;
        }
    }
    
    // Check one last time at the end of the loop
    maxL = max(maxL, l);

    cout << maxL << endl;

    return 0;
}
