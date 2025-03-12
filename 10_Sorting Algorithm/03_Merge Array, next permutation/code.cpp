#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int> & A, int m, vector<int> & B, int n)
{
    int index = m+n-1, i = m-1, j = n-1;
    
    while(i >= 0 && j >= 0) {
        if (A[i] >= B[j])
        {
            A[index--] = A[i--];
        }else {
            A[index--] = B[j--];
        }
    }

    while(j >= 0) {
        A[index--] = B[j--];
    }

    return 0;
}

int main() {
    vector<int> A = {1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> B = {2, 5, 6};
    int n = 3;

    merge(A, m, B, n);

    for (int i = 0; i < m + n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
    
}