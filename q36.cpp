#include <iostream>
#include <unordered_set>
#include <algorithm>
using namespace std;

void permutations(string &str, int i) {
    if (i == str.size() - 1) {
        cout << str << endl;
        return;
    }
    unordered_set<char> s;  // track chars already swapped at this recursion level
    for (int idx = i; idx < str.size(); idx++) {
        if (s.count(str[idx])) continue;  // skip duplicates
        s.insert(str[idx]);
        swap(str[idx], str[i]);
        permutations(str, i + 1);
        swap(str[idx], str[i]);  // backtrack
    }
}
int main() {
    string str;
    cin >> str;
    sort(str.begin(), str.end());  // sort to get lex order
    permutations(str, 0);
    return 0;
}

