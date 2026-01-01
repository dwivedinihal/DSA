#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Comparator: sort by end time
bool cmp(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
}

int main() {
    int n;
    cin >> n;
    vector<int> start(n), end(n);
    for (int i = 0; i < n; i++) cin >> start[i];
    for (int i = 0; i < n; i++) cin >> end[i];

    vector<vector<int>> activities;
    for (int i = 0; i < n; i++) {
        // Each activity = {start time, end time, index (1-based)}
        activities.push_back({start[i], end[i], i + 1});
    }

    // Sort by finish times (greedy step)
    sort(activities.begin(), activities.end(), cmp);
    vector<int> selectedIndices;
    int lastEndTime = 0;
    for (int i = 0; i < n; i++) {
        if (activities[i][0] >= lastEndTime) {
            selectedIndices.push_back(activities[i][2]); // store original index
            lastEndTime = activities[i][1];
        }
    }
    cout << "No. of non-conflicting activities: " << selectedIndices.size() << endl;
    cout << "List of selected activities: ";
    for (int i = 0; i < selectedIndices.size(); i++) {
        cout << selectedIndices[i];
        if (i < selectedIndices.size() - 1) cout << ", ";
    }
    cout << endl;

    return 0;
}
