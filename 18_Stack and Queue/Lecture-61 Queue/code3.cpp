#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
using namespace std;

//first non-repeating character in a string
string firstNonRepeating(string A) {

    unordered_map<char, int> count; //map to store count
    queue<int> q;
    string ans = "";

    for(int i=0; i<A.length(); i++) {
        char ch = A[i];

        //increase count
        count[ch]++;

        //push into queue
        q.push(ch);


        while(!q.empty()) {
            if(count[q.front()] > 1) {
                //Repeating character
                q.pop();
            }else {
                //non-repeating character
                ans.push_back(q.front());
                break;
            }
        }

        //if there is not any non-repeating character then returning '#'
        if(q.empty()) {
            ans.push_back('#');
        }
    }

    return ans;
}