#include <iostream>
 #include <vector> 
 #include <cmath> 
 using namespace std;
int jumpSearch(vector<int> &arr, int key, int &comparisons){ int n = arr.size();
int step = sqrt(n); int prev = 0;
while (arr[min(step, n) - 1] < key){ comparisons++;
prev = step; step += sqrt(n); if (prev >= n)
return -1;
}
while (arr[prev] < key){ comparisons++; prev++;
if (prev == min(step, n)) return -1;
}
comparisons++;
if (arr[prev] == key) return prev;
return -1;
}

int main(){ int t;
cin >> t; while (t--){
int n, key; cin >> n;
vector<int> arr(n);
for (int i = 0; i < n; i++) cin >> arr[i];
cin >> key;
int comparisons = 0;
int result = jumpSearch(arr, key, comparisons); if (result != -1)
cout << "Element found\n"; else
cout << "Element not found\n";
cout << "Total comparisons: " << comparisons << "\n";
}
return 0;
}
