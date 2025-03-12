#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits> //for INT_MIN and max
using namespace std;

//Maximum frequency number
int maxFrequency(vector<int> &arr, int n) {

    unordered_map<int, int> m; //first is key and second is the number of occurance

    int maxFreq = 0; //variable to store occurance
    int maxAns = 0;

    for(int i=0; i<arr.size(); i++) {
        m[arr[i]]++;
        maxFreq = max(maxFreq, m[arr[i]]);
    }

    for(int i=0; i<arr.size(); i++) {
        if(maxFreq == m[arr[i]]) {
            maxAns = arr[i];
            break;
        }
    }

    return maxAns;
}

int main() {
    cout<<endl;

    vector<int> arr = {1, 2, 3, 3, 5, 9, 9, 3};
    int n = arr.size();

    int ans = maxFrequency(arr, n);
    cout<<"Maximum Frequency Number: "<< ans <<endl;
    return 0;
}