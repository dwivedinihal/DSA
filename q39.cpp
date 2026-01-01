#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n; 
    cin >> n;
    vector<int> arr(n);
    for (int &x : arr) cin >> x;

    unordered_map<int, pair<int, int>> productMap;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int prod = arr[i] * arr[j];

            if (productMap.find(prod) == productMap.end()) {
                productMap[prod] = {arr[i], arr[j]};
            } else {
                auto p = productMap[prod];
                // Check distinctness of elements
                if (p.first != arr[i] && p.first != arr[j] && p.second != arr[i] && p.second != arr[j]) {
                    cout << p.first << " " << p.second << "\n";
                    cout << arr[i] << " " << arr[j] << "\n";
                    return 0;
                }
            }
        }
    }
    // If no pairs found
    cout << "No such pairs found\n";
    return 0;
}


