#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//first negative interger in every window of size k

vector<long long> firstNegInteger(long long int A[], long long int N, long long int K) {

    deque<long long int> dq;
    vector<long long> ans;

    //process first window of k size
    for(int i=0; i<K; i++) {
        if(A[i] < 0) {
            dq.push_back(i);
        }
    }

    //store answer of first k size of window
    if(dq.size() > 0) {
        ans.push_back(A[dq.front()]);
    }else {
        ans.push_back(0);
    }

    //process for remaining window
    for(int i=K; i<N; i++) {
        //removel

        if(!dq.empty() && i - dq.front() >= K) {
            dq.pop_front();
        }

        //addition
        if(A[i] < 0) {
            dq.push_back(i);
        }

        //ans store
        if(dq.size() > 0) {
            ans.push_back(A[dq.front()]);
        }else {
            ans.push_back(0);
        }
    }
    return ans;
}

int main() {
    cout<<endl;

    long long int arr[] = {-8, 2, 3, -6, 10};
    long long int n = 6;
    long long int k = 2;

    firstNegInteger(arr, n, k);
    for(int i=0; i<n; i++) {
        cout<< arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}