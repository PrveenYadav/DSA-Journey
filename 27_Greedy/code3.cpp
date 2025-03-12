#include <iostream>
#include <vector>
using namespace std;

//Problem: Check if it is possible to survive on Island
/*
Geekina got stuck on an island. There is only one shop on this island and it is open on all days of the week except for Sunday. Consider following constraints:

N – The maximum unit of food you can buy each day.
S – Number of days you are required to survive.
M – Unit of food required each day to survive.
Currently, it’s Monday, and she needs to survive for the next S days.
Find the minimum number of days on which you need to buy food from the shop so that she can survive the next S days, or determine that it isn’t possible to survive.
*/

int minimumDays(int S, int N, int M) {
    int sunday = S/7;

    int buyingDays = S - sunday;
    int totalFood = S*M;
    int ans = 0;

    if(totalFood % N == 0) {
        ans = totalFood/N;
    }else {
        ans = totalFood/N + 1;
    }

    if(ans <= buyingDays)
        return ans;
    else 
        return -1; 
}

//All test cases passed : this problem i wrong almost 10 times on gfg using chatgpt, so don't trust on chatgpt
int minimumDaysCorrect(int S, int N, int M) {
        
    if(M > N) return -1;
    if((S >= 7) && (((N-M)*6) < M)) return -1;

    int toatalFood = S*M;
        
    if(toatalFood%N == 0){
        return (toatalFood/N);
    }
    else{
        return ((toatalFood/N)+1);
    }
}

int main() {
    cout<<endl;
    int s = 10, n = 16, m = 2; //output = 2

    cout<<"Minimum Days: "<< minimumDays(s, n, m) <<endl;
    cout<<"Minimim days: "<< minimumDaysCorrect(s, n, m) <<endl;
    return 0;
}