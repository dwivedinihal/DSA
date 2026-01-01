#include <iostream>
#include <map>
using namespace std;
int main() {
    int n;
    cin >> n;
    map<char, int> freq;  // keeps keys sorted automatically
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        freq[c]++;
    }
    for (auto &p : freq) {
        cout << p.first << " " << p.second << "\n";
    }
    return 0;
}



