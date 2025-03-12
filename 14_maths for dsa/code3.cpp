#include <iostream>
using namespace std;

//Modular Exponentiation : using fast expontiation method
int modExp(int x, int n, int m) {
    int res = 1;

    while(n>0) {

        if(n&1) {
            res = (1LL * res * x % m) % m; //1LL means typecast in long long
        }
        x = (1LL * (x%m) * (x%m))%m;
        n = n>>1; //right shift
    }
    return res;
}

int main() {

    int a, b, m;
    cin>>a>>b;

    int ans = modExp(a,b,m);

    cout<<ans;

}