#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;  // Number of test cases
    
    while (t--) {
        int n;
        cin >> n;  // Number of elements in the array
        vector<int> a(n);
        
        int oddCount = 0, evenCount = 0, sum = 0;
        
        // Reading the array and counting odd/even numbers
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
            if (a[i] % 2 == 0) {
                evenCount++;
            } else {
                oddCount++;
            }
        }
        
        // Checking conditions
        if (sum % 2 == 1) {
            // If the sum is already odd, print YES
            cout << "YES" << endl;
        } else {
            // Otherwise, check if there's at least one odd and one even
            if (oddCount > 0 && evenCount > 0) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    
    return 0;
}
