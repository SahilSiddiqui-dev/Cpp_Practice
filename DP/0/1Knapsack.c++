#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack(int W, vector<int>& wt, vector<int>& val, int n) {
    // Create a 2D table: (n+1) rows, (W+1) columns, all zeros
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Fill the table row by row
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            // Option 1: Skip this item
            dp[i][w] = dp[i-1][w];

            // Option 2: Take this item (only if it fits)
            if (wt[i-1] <= w) {
                int take = dp[i-1][w - wt[i-1]] + val[i-1];
                dp[i][w] = max(dp[i][w], take); // Pick better option
            }
        }
    }

    return dp[n][W]; // Answer is at bottom-right corner
}

int main() {
    int W = 7; // Bag capacity

    vector<int> weights = {4, 3, 3, 2};      // Laptop, Camera, Books, Shoes
    vector<int> values  = {50, 40, 30, 20};   // Their values

    int n = weights.size();

    cout << "Max value: " << knapsack(W, weights, values, n) << endl;
    return 0;
}