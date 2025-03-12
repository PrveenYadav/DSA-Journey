#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip> // For setprecision
using namespace std;

//fractional knapsack

// Structure to represent an item with value, weight, and value/weight ratio
struct Item {
    int value;
    int weight;
    double ratio; // Value/weight ratio

    Item(int v, int w) : value(v), weight(w) {
        ratio = (double)value / weight;
    }

    // Comparison function for sorting items based on their value/weight ratio in descending order
    bool operator>(const Item& other) const {
        return ratio > other.ratio;
    }
};

// Function to get the maximum total value in the knapsack.
double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
    int n = val.size();
    vector<Item> items;

    // Create Item objects and store them in a vector
    for (int i = 0; i < n; i++) {
        items.push_back(Item(val[i], wt[i]));
    }

    // Sort items based on their value/weight ratio in descending order
    sort(items.begin(), items.end(), greater<Item>());

    double totalValue = 0;
    int remainingCapacity = capacity;

    for (const auto& item : items) {
        if (remainingCapacity == 0) {
            break; // Knapsack is full
        }

        if (item.weight <= remainingCapacity) {
            // Take the whole item
            totalValue += item.value;
            remainingCapacity -= item.weight;
        } else {
            // Take a fraction of the item
            totalValue += item.ratio * remainingCapacity;
            remainingCapacity = 0; // Knapsack is now full
            break;
        }
    }

    return totalValue;
}

int main() {
    cout<<endl;
    
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int capacity = 50;

    double maxValue = fractionalKnapsack(val, wt, capacity);

    cout << "Maximum value in Knapsack = " << fixed << setprecision(2) << maxValue << endl; // Use setprecision to format the output

    return 0;
}