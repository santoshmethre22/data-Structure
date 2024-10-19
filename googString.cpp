#include <iostream>
#include <set>
#include <string>
using namespace std;

// Function to hash substrings
string hashSubstring(const string &s, int start, int end) {
    return s.substr(start, end - start + 1);
}

int main() {
    string s;
    cin >> s;

    string goodBad;
    cin >> goodBad;

    int k;
    cin >> k;

    int n = s.size();
    
    // Array to mark good (1) or bad (0) characters based on the input goodBad string
    bool isGood[26];
    for (int i = 0; i < 26; i++) {
        isGood[i] = (goodBad[i] == '1');
    }

    set<string> goodSubstrings; // To store distinct good substrings

    // Iterate through every starting position of substring
    for (int start = 0; start < n; start++) {
        int badCount = 0;  // Counter for bad characters in the current substring
        
        // Expand the substring from the starting position
        for (int end = start; end < n; end++) {
            char c = s[end];
            
            // Check if the current character is bad
            if (!isGood[c - 'a']) {
                badCount++;
            }
            
            // If bad characters exceed the allowed limit k, stop expanding
            if (badCount > k) {
                break;
            }
            
            // Hash and insert the current valid substring into the set
            goodSubstrings.insert(hashSubstring(s, start, end));
        }
    }

    // The size of the set gives the number of distinct good substrings
    cout << goodSubstrings.size() << endl;

    return 0;
}
