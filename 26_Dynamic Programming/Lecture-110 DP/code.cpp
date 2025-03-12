#include <iostream>
#include <vector>
using namespace std;

//Prve was all 1D-DP, And now starting 2D-DP
//Problem: 0/1 KnapSack Problem : given weight & value & how much a robber can carry weight
//suppose: w = 1 2 4 5 , v = 5 4 8 6 and maxWeight can carry = 5 then ans = w{1, 4} = v{5, 8}, max weight can carry 5+8 = 13

//Recursion
int knapsack(vector<int> weight, vector<int> value, int index, int capacity) { //capacity = maxWeight(a knaSpack(bag) can carry)
    //base case: moving right(n-1) to left(0)
    //if only one item to steal, then just compare its weight with the knasSpack(Bag) capacity
    if(weight[0] <= capacity) {
        return value[0];
    }else {
        return 0;
    }

    int include = 0;
    if(weight[index] <= capacity) {
        include = value[index] + knapsack(weight, value, index-1, capacity - weight[index]);
    }
    int exclude = 0 + knapsack(weight, value, index-1, capacity); //moving forward(n to 0) or right to left so, index-1

    int ans = max(include, exclude);
    return ans;
}

//Memoization
int knapSack1(vector<int> weight, vector<int> value, int index, int capacity) {
    //2D DP : because 2 parameters values is changing(index(n) & maxWeight(capacity))
    vector<vector<int>> dp(index, vector<int> (capacity+1, -1)); //row, col, -1(intializing with)
    
    if(weight[0] <= capacity) {
        return value[0];
    }else {
        return 0;
    }

    if(dp[index][capacity] != -1) return dp[index][capacity];

    int include = 0;
    if(weight[index] <= capacity) {
        include = value[index] + knapSack1(weight, value, index-1, capacity - weight[index]);
    }
    int exclude = 0 + knapSack1(weight, value, index-1, capacity);

    dp[index][capacity] = max(include, exclude);
    return dp[index][capacity];
}


//corrected version: Recursion
int knapSackRec(vector<int> weight, vector<int> value, int n, int maxWeight) {
    // Base case
    if (n == 0 || maxWeight == 0) {
        return 0;
    }

    int include = 0;
    if (weight[n-1] <= maxWeight) { 
        include = value[n - 1] + knapSackRec(weight, value, n - 1, maxWeight - weight[n - 1]);
    }
    int exclude = 0 + knapSackRec(weight, value, n - 1, maxWeight);
    int ans = max(exclude, include);
    return ans;
}

//corrected version: Memooization
int knapSackMem(vector<int> weight, vector<int> value, int n, int maxWeight) {
    //2D dp array created
    vector<vector<int>> dp(n, vector<int>(maxWeight+1, -1));
    //base case
    if(n == 0 || maxWeight == 0) return 0;

    if(dp[n-1][maxWeight] != -1) return dp[n-1][maxWeight];

    int include = 0;
    if(weight[n-1] <= maxWeight) {
        include = value[n-1] + knapSackMem(weight, value, n-1, maxWeight - weight[n-1]);
    }
    int exclude = 0 + knapSackMem(weight, value, n-1, maxWeight);

    dp[n-1][maxWeight] = max(include, exclude);
    return dp[n-1][maxWeight];
}

//Tabulation
int knapSackTab(vector<int> weight, vector<int> value, int n, int capacity) {

    vector<vector<int>> dp(n, vector<int> (capacity+1, -1));

    //Analyze base case
    for(int w=weight[0]; w<=capacity; w++) {
        if(weight[0] <= capacity) {
            dp[0][w] = value[0];
        }else { 
            dp[0][w] = 0;
        }
    }

    //take care of remaining recursive calls
    for(int index=1; index<n; index++) {
        for(int w=0; w<=capacity; w++) {
            int include = 0;

            if(weight[index] <= w) {
                include = value[index] + dp[index-1][w - weight[index]];
            }

            int exclude = 0 + dp[index-1][w];

            dp[index][w] = max(include, exclude);
        }
    }

    return dp[n-1][capacity];
}

//Space Optimized
int knapSackOptimized(vector<int> weight, vector<int> value, int n, int capacity) {

    vector<int> prev(capacity+1, 0);
    vector<int> curr(capacity+1, 0);

    //Analyze base case
    for(int w=weight[0]; w<=capacity; w++) {
        if(weight[0] <= capacity) {
            prev[w] = value[0];
        }else { 
            prev[w] = 0;
        }
    }

    //take care of remaining recursive calls
    for(int index=1; index<n; index++) {
        for(int w=0; w<=capacity; w++) {
            int include = 0;

            if(weight[index] <= w) {
                include = value[index] + prev[w - weight[index]];
            }

            int exclude = 0 + prev[w];

            curr[w] = max(include, exclude);
        }
        prev = curr;
    }

    return prev[capacity];
}

//More Optimized
int knapSackOptimizedMore(vector<int> &weight, vector<int> &value, int n, int capacity) {
    //Addition we're doing with only one arry (curr array) and revering loop
    vector<int> curr(capacity+1, 0);

    //Analyze base case
    for(int w=weight[0]; w<=capacity; w++) {
        if(weight[0] <= capacity) {
            curr[w] = value[0];
        }else { 
            curr[w] = 0;
        }
    }

    //take care of remaining recursive calls
    for(int index=1; index<n; index++) {
        for(int w=capacity; w>=0; w--) { //change here: loop reversing
            int include = 0; 
            if(weight[index] <= w) {
                include = value[index] + curr[w - weight[index]];
            }
            int exclude = 0 + curr[w];

            curr[w] = max(include, exclude);
        }
    }
    return curr[capacity];
}


int main() {
    cout<<endl;

    vector<int> weight = {1, 2, 4, 5};
    vector<int> value = {5, 4, 8, 6};
    int n = 4;
    int maxWeight = 5;

    cout<<"KnapSack maxWeight-R: "<< knapSackRec(weight, value, n-1, maxWeight) <<endl;
    cout<<"KnapSack maxWeight-M: "<< knapSackMem(weight, value, n-1, maxWeight) <<endl;
    cout<<"KnapSack maxWeight-T: "<< knapSackTab(weight, value, n, maxWeight) <<endl;
    cout<<"KnapSack maxWeight-S.O: "<< knapSackOptimized(weight, value, n, maxWeight) <<endl;
    cout<<"KnapSack maxWeight-More: "<< knapSackOptimizedMore(weight, value, n, maxWeight) <<endl;
    return 0;
}