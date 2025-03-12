#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//Problem: Merge k sorted list
// Define a structure to represent a node in the Min Heap
struct Node {
    int value; // The value of the current element
    int listIndex; // The index of the list this element belongs to
    int elementIndex; // The index of this element within its list

    Node(int val, int lIdx, int eIdx) : value(val), listIndex(lIdx), elementIndex(eIdx) {}
};

// Comparison operator for the Min Heap
struct Compare {
    bool operator()(const Node& a, const Node& b) {
        return a.value > b.value; // Min Heap: smallest value has the highest priority
    }
};

// Function to merge k sorted lists
vector<int> mergeKSortedLists(vector<vector<int>>& lists) {
    priority_queue<Node, vector<Node>, Compare> minHeap; // Min Heap for merging
    vector<int> mergedList; // To store the merged result

    // Initialize the Min Heap with the first element of each list
    for (int i = 0; i < lists.size(); i++) {
        if (!lists[i].empty()) {
            minHeap.emplace(lists[i][0], i, 0);
        }
    }

    // Process the Min Heap
    while (!minHeap.empty()) {
        Node current = minHeap.top();
        minHeap.pop();

        // Add the smallest element to the merged list
        mergedList.push_back(current.value);

        // If there is a next element in the same list, insert it into the Min Heap
        int nextElementIndex = current.elementIndex + 1;
        if (nextElementIndex < lists[current.listIndex].size()) {
            minHeap.emplace(lists[current.listIndex][nextElementIndex], current.listIndex, nextElementIndex);
        }
    }

    return mergedList;
}

int main() {
    cout<<endl;

    // Input: k sorted lists
    vector<vector<int>> lists = {
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9}
    };

    // Merge k sorted lists
    vector<int> mergedList = mergeKSortedLists(lists);

    // Output the result
    cout << "Merged k sorted List: ";
    for (int val : mergedList) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
