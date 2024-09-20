#include <iostream>
using namespace std;

// Write a function to print nth Fibonacci
void FibN(int n)
{
    int t1 = 0;
    int t2 = 1;
    int nextTerm = 0;

    cout << t1 << " " << t2 << " ";

    for (int i = 3; i <= n; i++)
    {
        nextTerm = t1 + t2;
        cout << nextTerm << " ";

        t1 = t2;
        t2 = nextTerm;
    }
}

int main()
{
    int n;
    cin >> n;
    FibN(n);

    return 0;
}