#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> time(n), deadline(n);
    for (int i = 0; i < n; ++i) cin >> time[i];
    for (int i = 0; i < n; ++i) cin >> deadline[i];

    // Pair: {deadline, {time, index}}
    vector<pair<int, pair<int, int>>> tasks;
    for (int i = 0; i < n; ++i) {
        tasks.push_back({deadline[i], {time[i], i + 1}});
    }

    // Sort tasks by deadline (greedy strategy)
    sort(tasks.begin(), tasks.end());

    int currentTime = 0;
    vector<int> selected;
    priority_queue<int> maxHeap; // optional: to replace longer task if needed

    for (auto &task : tasks) {
        int d = task.first;
        int t = task.second.first;
        int idx = task.second.second;

        if (currentTime + t <= d) {
            currentTime += t;
            selected.push_back(idx);
            maxHeap.push(t);
        } else if (!maxHeap.empty() && maxHeap.top() > t) {
            currentTime -= maxHeap.top();
            maxHeap.pop();
            currentTime += t;
            selected.push_back(idx);
            maxHeap.push(t);
        }
    }
    // Output
    sort(selected.begin(), selected.end()); // Optional: sort selected task numbers
    cout << "Max number of tasks = " << selected.size() << endl;
    cout << "Selected task numbers : ";
    for (int i = 0; i < selected.size(); ++i) {
        cout << selected[i];
        if (i < selected.size() - 1) cout << ", ";
    }
    cout << endl;
    return 0;
}

