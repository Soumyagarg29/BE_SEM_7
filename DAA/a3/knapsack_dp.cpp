#include <iostream>
#include <vector>
using namespace std;

int knapsack(int idx, int curr_wt, int n, vector<int> weights, vector<int> values, const int &maxCapacity, vector<vector<int>> &dp)
{
    if (idx >= n)
        return 0;
    if (dp[idx][curr_wt] != -1)
        return dp[idx][curr_wt];
    int notPick = knapsack(idx + 1, curr_wt, n, weights, values, maxCapacity, dp);
    int pick = 0;
    if (maxCapacity >= weights[idx] + curr_wt)
        pick = values[idx] + knapsack(idx + 1, curr_wt + weights[idx], n, weights, values, maxCapacity, dp);

    return dp[idx][curr_wt] = max(pick, notPick);
}

int main()
{
    vector<int> weights = {95, 4, 60, 32, 23};
    vector<int> values = {55, 10, 47, 5, 4};
    int n = 5;
    int capacity = 100;

    vector<vector<int>> dp(n, vector<int>(capacity, -1));

    cout << "Max Profit " << knapsack(0, 0, n, weights, values, capacity, dp) << endl;
    for (auto i : dp)
    {
        for (auto ele : i)
            cout << ele << " ";
        cout << endl;
    }
}