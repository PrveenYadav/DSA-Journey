#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

//Chocolate distribution problem

int findMinDiff(vector<int>& a, int m) {
    sort(a.begin(), a.end());
    int i = 0;
    int j = m-1;

    int mini = INT_MAX;
    while(j < a.size()) {
        int diff = a[j] - a[i];
        mini = min(mini, diff);
        i++;
        j++;
    }
    return mini;
}

int main() {
    cout<<endl;
    vector<int> arr = {3, 4, 1, 9, 56, 7, 9, 12};
    int m = 5; //output = 6

    cout<<"Min difference: "<< findMinDiff(arr, m) <<endl;
    return 0;
}