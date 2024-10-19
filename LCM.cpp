#include<iostream>
using namespace std;



int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to calculate LCM
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}



int main(){

 
    int t;
    cin >> t; // number of test cases
    
    while (t--) {
        int l, r;
        cin >> l >> r;
        
        // Check if 2 * l is within the range [l, r]
        if (2 * l <= r) {
            cout << l << " " << 2 * l << endl;
        } else {
            cout << -1 << " " << -1 << endl;
        }
    }
    
    return 0;


}