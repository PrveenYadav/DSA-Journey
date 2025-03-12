#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <deque>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <climits> //for using: INT_MIN and INT_MAX

#include <algorithm> // For using: min, max, sort, reverse, binary search etc Algorithms

using namespace std;

int main() {

    vector<int> vec = {1, 2, 3, 4, 5};

    // How to create iterator
    vector<int>::iterator it;

    for (it = vec.begin(); it != vec.end(); it++) {
        cout << *(it) << " "; 
    }
    cout<<endl;

    //And for backword = In Reverse order
    for (auto it = vec.rbegin(); it != vec.rend(); it++) {
        cout << *(it) << " "; 
    }

    cout << endl;
    return 0;
}
