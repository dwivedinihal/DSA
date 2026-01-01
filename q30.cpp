#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find majority element using Boyer-Moore Voting Algorithm
int findMajorityElement(vector<int>& arr, int n) {
    int candidate = -1, count = 0;

    // Phase 1: Find candidate
    for (int i = 0; i < n; i++) {
        if (count == 0) {
            candidate = arr[i];
            count = 1;
        } else if (arr[i] == candidate) {
            count++;
        } else {
            count--;
        }
    }

    // Phase 2: Verify candidate
    count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == candidate) count++;
    }

    if (count > n / 2) return candidate;
    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    // Check for majority element
    int majority = findMajorityElement(arr, n);
    if (majority != -1)
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    // Find median
    sort(arr.begin(), arr.end());
    double median;
    if (n % 2 == 0)
        median = (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
    else
        median = arr[n / 2];

    // Print median (no decimal if it's whole number)
    if (median == (int)median)
        cout << (int)median << endl;
    else
        cout << median << endl;

    return 0;
}
