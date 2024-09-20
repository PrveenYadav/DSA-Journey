#include <iostream>
using namespace std;

// Solving the Patterns to play with Loops.

void print1(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void print2(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void print3(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void print4(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

void print5(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j<n-i+1; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void print6(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n-i+1; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void print7(int n)
{
    for (int i = 0; i < n; i++)
    {
        //space 
        for(int j = 0; j<n-i-1; j++)
        {
            cout << " ";
        }
        //star
        for(int j = 0; j < 2*i+1; j++)
        {
            cout << "*";
        }

        //space
        for(int j = 0; j<n-i-1; j++)
        {
          cout << " ";  
        }

        cout << endl;
    }
}

void print8(int n) 
{
    for (int i = 0; i < n; i++)
    {
        // For Space
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }

        // For Stars
        for (int j = 0; j < 2*n-(2*i+1); j++)
        {
            cout << "*";
        }

        // For Space
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }

        cout << endl;
    }
}

// for 9th Pattern combinned 7th and 8th Pattern and print 7th & 8th together.

void print10(int n)
{
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        int stars = i;
        if (i > n)
        {
            stars = 2 * n - i;
        }
        for (int j = 1; j <= stars; j++)
        {
            cout << "*";
        }

        cout << endl;
    }
}

void print11(int n)
{
    int start = 1;
    for(int i = 0; i<n; i++)
    {
        if(i % 2 == 0) start = 1;
        else start = 0;
        for(int j = 0; j<=i; j++)
        {
            cout << start;
            start = 1 - start;
        }
        cout << endl;
    }
}

void print12(int n)
{
    int space = 2* (n-1);
    for(int i = 1; i<=n; i++)
    {
        //Numbers
        for(int j = 1; j<=i; j++){
            cout << j ;
        }

        //Spaces
        for(int j = 1; j<=space; j++){
            cout << " ";
        }

        //Numbers
        for(int j = i; j>=1; j--){
            cout << j ;
        }

        cout << endl;
        space -= 2;
    }
}


int main()
{
    int t;
    cin >> t; // test cases, means how many times print the patterns
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        print12(n); // we can call fuction which one we want to print
    }
}