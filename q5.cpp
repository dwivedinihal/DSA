#include <iostream> 
#include<vector> 
using namespace std;

int binarySearch(vector<int> &arr, int left, int right, int key){ while (left <= right){
int mid = left + (right - left) / 2; if (arr[mid] == key)
return mid;
else if (arr[mid] < key) left = mid + 1;
else
right = mid - 1;
}
return -1;
}

void Search(vector<int> &arr){ int n = arr.size();
for (int i = 0; i < n - 1; i++){ for (int j = i + 1; j < n; j++){
int sum = arr[i] + arr[j];
int k = binarySearch(arr, j + 1, n - 1, sum); if (k != -1){
cout << "Indices: " << i << " " << j << " " << k << "\n"; return;
}
}
}
cout << "Not found\n";
}

int main()
{
int t;
cin >> t; while(t--){
int n; cin >> n;
vector<int> arr(n);
for (int i = 0; i < n; i++) cin >> arr[i];
Search(arr);
}
return 0;
}
