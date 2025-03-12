#include <iostream>
using namespace std;

// Write a function to print sum of Fibonacci numbers
int fib(int n)
{
  if (n <= 1)
  {
    return n;
  }

  return fib(n - 1) + fib(n - 2);
}

int main()
{
  int n;
  cin >> n;
  cout << fib(n);

  return 0;
}