#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//understand both problem most important
//HomeWork: Maximum meetings in one room | geeksforgeeks

// Struct to store meeting details
struct Meeting {
    int start;
    int end;
    int index;
};

// Comparator function to sort meetings by their end times
bool compare(Meeting a, Meeting b) {
    return a.end < b.end;
}

void maxMeetings(vector<int> &start, vector<int> &end) {
    int n = start.size();
    vector<Meeting> meetings(n);

    // Store meeting details
    for (int i = 0; i < n; i++) {
        meetings[i] = {start[i], end[i], i + 1}; // Store 1-based index
    }

    // Sort meetings by ending time
    sort(meetings.begin(), meetings.end(), compare);

    // Select meetings greedily
    vector<int> selectedMeetings;
    int lastEndTime = 0;

    for (auto &m : meetings) {
        if (m.start > lastEndTime) {
            selectedMeetings.push_back(m.index);
            lastEndTime = m.end;
        }
    }

    // Print the selected meeting indices
    cout << "Maximum number of meetings: " << selectedMeetings.size() << endl;
    cout << "Meetings that can be scheduled: ";
    for (int id : selectedMeetings) {
        cout << id << " ";
    }
    cout << endl;
}

int main() {
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};

    maxMeetings(start, end);

    return 0;
}