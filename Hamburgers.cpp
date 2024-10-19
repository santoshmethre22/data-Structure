#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Helper function to calculate how much rubles are needed to buy more ingredients
long long calculate_cost(long long hamburgers, long long have, long long need, long long price) {
    return max(0LL, (need * hamburgers - have) * price);
}

int main() {
    string recipe;
    long long nb, ns, nc; // Available bread, sausage, and cheese
    long long pb, ps, pc; // Prices of bread, sausage, and cheese
    long long r;          // Rubles Polycarpus has

    cin >> recipe;
    cin >> nb >> ns >> nc;
    cin >> pb >> ps >> pc;
    cin >> r;

    // Count how many B, S, C are needed for one hamburger
    long long reqB = count(recipe.begin(), recipe.end(), 'B');
    long long reqS = count(recipe.begin(), recipe.end(), 'S');
    long long reqC = count(recipe.begin(), recipe.end(), 'C');

    // Binary search to find the maximum number of hamburgers Polycarpus can make
    long long low = 0, high = 1e13, mid;
    while (low <= high) {
        mid = (low + high) / 2;

        // Calculate the total cost to make `mid` hamburgers
        long long cost = calculate_cost(mid, nb, reqB, pb) +
                         calculate_cost(mid, ns, reqS, ps) +
                         calculate_cost(mid, nc, reqC, pc);

        if (cost <= r)
            low = mid + 1;  // Can make more hamburgers
        else
            high = mid - 1; // Too expensive, try making fewer
    }

    // Output the maximum number of hamburgers
    cout << high << endl;

    return 0;
}
