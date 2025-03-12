#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>
using namespace std;

//Problem: Minimum Costs For Tickets(Leetcode-983) or Ninja's Trip

//Recursion
int minCost(vector<int> &days, vector<int> &costs, int index) { //index=0 starting with
    int n = days.size();
    //base case
    if(index >= n) return 0;

    //1 day pass
    int option1 = costs[0] + minCost(days, costs, index+1); //index+1 means move forward

    //7 day pass: going from index till 7 days and then recursive call for further
    int i;
    for(int i=index; i<n && days[i] < days[index] + 7; i++);
    int option2 = costs[1] + minCost(days, costs, i);

    //30 day pass: going from 7days till 30 days and then recursive call for further
    for(int i=index; i<n && days[i] < days[index] + 30; i++);
    int option3 = costs[2] + minCost(days, costs, i);

    return min(option1, min(option2, option3));
}

//Recursion: correct
int minCostBruteForce(vector<int>& days, vector<int>& costs, int index) {
    int n = days.size();

    // Base case: No more travel days
    if (index >= n) {
        return 0;
    }

    // 1-day pass
    int option1 = costs[0] + minCostBruteForce(days, costs, index + 1);

    // 7-day pass
    int i;
    for (i = index; i < n && days[i] < days[index] + 7; ++i);
    int option2 = costs[1] + minCostBruteForce(days, costs, i);

    // 30-day pass
    for (i = index; i < n && days[i] < days[index] + 30; ++i);
    int option3 = costs[2] + minCostBruteForce(days, costs, i);

    return min(option1, min(option2, option3));
}


//Memoization
int minCostMem(vector<int> &days, vector<int> &costs, int index) {
    int n = days.size();
    vector<int> dp(n, -1);
    //base case
    if(index >= n) return 0;
    if(dp[index] != -1) return dp[index];

    //1 day pass
    int option1 = costs[0] + minCostMem(days, costs, index+1);

    //7 day pass
    int i;
    for(int i=index; i<n && days[i] < days[index] + 7; i++);
    int option2 = costs[1] + minCostMem(days, costs, i);

    //30 day pass
    for(int i=index; i<n && days[i] < days[index] + 30; i++);
    int option3 = costs[2] + minCostMem(days, costs, i);

    dp[index] = min(option1, min(option2, option3));
    return dp[index];
}

//Memoization: correct
int minCostMemo1(vector<int>& days, vector<int>& costs, int index) {
    int n = days.size();
    vector<int> memo(n, -1);
    if (index >= n) return 0;

    if (memo[index] != -1) return memo[index];

    // 1-day pass
    int option1 = costs[0] + minCostMemo1(days, costs, index + 1); 

    // 7-day pass
    int i;
    for (i = index; i < n && days[i] < days[index] + 7; ++i);
    int option2 = costs[1] + minCostMemo1(days, costs, i);

    // 30-day pass
    for (i = index; i < n && days[i] < days[index] + 30; ++i);
    int option3 = costs[2] + minCostMemo1(days, costs, i);

    // Store the result in memo
    memo[index] = min(option1, min(option2, option3));
    return memo[index];
}


//Tabulation(Bootom-Up)
int minCostTab(vector<int> &days, vector<int> &costs) { 
    int n = days.size();
    vector<int> dp(n+1, 0);
    dp[n] = 0;

    for(int k=n-1; k>=0; k--) { //bottom-up
        //1 day pass
        int option1 = costs[0] + dp[k+1];

        //7 day pass
        int i;
        for(int i=k; i<n && days[i] < days[k] + 7; i++);
        int option2 = costs[1] + dp[i];

        //30 day pass:
        for(int i=k; i<n && days[i] < days[k] + 30; i++);
        int option3 = costs[2] + dp[i];

        dp[k] = min(option1, min(option2, option3));
    }
    return dp[0];
}

//Tabulatin: correct
int mincostTicketsTabulation(vector<int>& days, vector<int>& costs) {
    int n = days.size();
    vector<int> dp(n + 1, 0); // dp[i] represents the minimum cost to travel up to and including the i-th travel day

    for (int i = n - 1; i >= 0; --i) {
        dp[i] = costs[0] + dp[i + 1]; // 1-day pass

        int j;
        for (j = i; j < n && days[j] < days[i] + 7; ++j);
        dp[i] = min(dp[i], costs[1] + dp[j]); // 7-day pass

        for (j = i; j < n && days[j] < days[i] + 30; ++j);
        dp[i] = min(dp[i], costs[2] + dp[j]); // 30-day pass
    }
    return dp[0];
}


//Space Optimized Approach: using Queue
int minCostOptimized(vector<int> &days, vector<int> &costs) {
    int n = days.size();
    int ans = 0;

    queue<pair<int, int>> month;
    queue<pair<int, int>> week;

    for(int day : days) {
        //Remove expired days
        while(!month.empty() && month.front().first + 30 <= day) {
            month.pop();
        }
        while(!week.empty() && week.front().first + 7 <= day) {
            week.pop();
        }

        //Add cost for curr day
        week.push(make_pair(day, ans+costs[1]));
        month.push(make_pair(day, ans+costs[2]));

        //Ans Update
        ans = min(ans+costs[0], min(week.front().second, month.front().second));
    }
    return ans;
}

//using find algorithm
int mincostTicketsSpaceOptimized(vector<int>& days, vector<int>& costs) {
    int n = days.size();
    int lastDay = days[n - 1]; 
    vector<int> dp(lastDay + 1, 0); 

    for (int i = 1; i <= lastDay; ++i) {
        if (find(days.begin(), days.end(), i) == days.end()) { // No travel on day 'i'
            dp[i] = dp[i - 1];
        } else { // Travel on day 'i'
            dp[i] = min({
                dp[i - 1] + costs[0], // 1-day pass
                dp[max(0, i - 7)] + costs[1], // 7-day pass
                dp[max(0, i - 30)] + costs[2] // 30-day pass
            });
        }
    }
    return dp[lastDay];
}

int main() {
    cout<<endl;

    vector<int> days = {1, 4, 6, 7, 8, 20};
    vector<int> costs = {2, 7, 15}; //Given: single day cost = 2, 7-days cost = 7 and 30-days cost = 15
    //to cover whole days, the minCost/output = 11

    cout<<"Min Cost-Rec: "<< minCost(days, costs, 0) <<endl; //index=0 starting with
    cout<<"Min Cost-Rec: "<< minCostBruteForce(days, costs, 0) <<endl;

    cout<<"Min Cost-Mem: "<< minCostMem(days, costs, 0) <<endl;
    cout<<"Min Cost-Mem: "<< minCostMemo1(days, costs, 0) <<endl;

    //cout<<"Min Cost-Tab: "<< minCostTab(days, costs) <<endl;
    cout<<"Min Cost-Tab: "<< mincostTicketsTabulation(days, costs) <<endl;

    cout<<"Min Cost-S.O: "<< mincostTicketsSpaceOptimized(days, costs) <<endl;
    cout<<"Min Cost-S.O: "<< minCostOptimized(days, costs) <<endl;
    return 0;
}