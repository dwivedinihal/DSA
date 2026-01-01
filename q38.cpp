#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
    int T; 
    cin >> T;
    while (T--) {
        int n; 
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        
        int k; 
        cin >> k;

        unordered_set<int> window;
        bool found = false;

        for (int i = 0; i < n; i++) {
            if (window.count(arr[i])) {
                found = true;
                break;
            }
            window.insert(arr[i]);

            // Remove element leaving the window
            if (window.size() > k) {
                window.erase(arr[i - k]);
            }
        }

        if (found) 
            cout << "Duplicate present in window " << k << ".\n";
        else 
            cout << "Duplicate not present in window " << k << ".\n";
    }

    return 0;
}

