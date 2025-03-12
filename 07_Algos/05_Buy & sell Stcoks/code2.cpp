#include <iostream>
#include <vector>
using namespace std;

// Buy and Sell stocks
// Time Complexity O(n)

int maxProfit(vector<int> &prices)
{
    int n = prices.size();

    if (n == 0) return 0; 

    int buy = prices[0];
    int maxProfit = 0;   

    for (int i = 1; i < n; i++)
    {
        if (prices[i] < buy)
        {
            buy = prices[i];
        }
        else
        {
            maxProfit = max(maxProfit, prices[i] - buy);
        }
    }
    return maxProfit;
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    cout << "Maximum Profit: " << maxProfit(prices) << endl;
    return 0;
}
