#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Job sequencing problem

struct Job {
    int id;
    int deadline;
    int profit;
};

vector<int> JobSequencing(vector<int> &id, vector<int> &deadline, vector<int> &profit) {
    int n = id.size();
    vector<Job> jobs(n);

    for (int i = 0; i < n; i++) {
        jobs[i].id = id[i];
        jobs[i].deadline = deadline[i];
        jobs[i].profit = profit[i];
    }

    // Sort jobs in descending order of profit
    sort(jobs.begin(), jobs.end(), [](Job a, Job b) {
        return a.profit > b.profit;
    });

    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        maxDeadline = max(maxDeadline, jobs[i].deadline);
    }

    vector<int> schedule(maxDeadline, -1); // Initialize schedule with -1 (no job assigned)
    vector<int> result;

    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (schedule[j] == -1) {
                schedule[j] = jobs[i].id;
                result.push_back(jobs[i].id);
                break; // Job assigned, move to the next job
            }
        }
    }

    return result;
}

int main() {
    vector<int> id = {1, 2, 3, 4, 5};
    vector<int> deadline = {2, 1, 2, 1, 3};
    vector<int> profit = {100, 19, 27, 25, 15};

    vector<int> result = JobSequencing(id, deadline, profit);

    cout << "Job Sequence: ";
    for (int job_id : result) {
        cout << job_id << " ";
    }
    cout << endl;

    return 0;
}