#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Finally Last Greedy Algorithm - DSA Finish

//Problem: N meetings in one room | geeksforgeeks
//HomeWork: Maximum meetings in one room | geeksforgeeks

//custom comparator
static bool cmp(pair<int, int> a, pair<int,int> b) {
    return a.second < b.second;
}

int nMeetings(int start[], int end[], int n) {

    vector<pair<int,int>> v; //starting and ending time

    for(int i=0; i<n; i++) {
        pair<int, int> p = make_pair(start[i], end[i]);
        v.push_back(p);
    }
    sort(v.begin(), v.end(), cmp);

    int count = 1;
    int ansEnd = v[0].second;

    for(int i=1; i<n; i++) {
        if(v[i].first > ansEnd) {
            count++;
            ansEnd = v[i].second;
        }
    }
    return count;
}

int main() {
    cout<<endl;
    int start[] = {1, 3, 0, 5, 8, 5};
    int end[] = {2, 4, 6, 7, 9, 9}; //output = 4

    cout<<"N Meetings: "<< nMeetings(start, end, 6) <<endl;
    return 0;
}