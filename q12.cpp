#include <iostream>
 #include <bits/stdc++.h>
  using namespace std;
int partition(vector<int> &arr, int low, int high){ int pivot = arr[high];
int i = low - 1;
for (int j = low; j < high; j++){ if (arr[j] < pivot){
i++;
swap(arr[i], arr[j]);
}
}
swap(arr[i + 1], arr[high]); return i + 1;
}
int quickSelect(vector<int> &arr, int low, int high, int k){ if (low <= high){
int pivotIndex = partition(arr, low, high); if (pivotIndex == k){
return arr[pivotIndex];
}
else if (pivotIndex > k){
return quickSelect(arr, low, pivotIndex - 1, k);
}
else{
return quickSelect(arr, pivotIndex + 1, high, k);
}
}
return -1;
}
int main(){ int n, k, t; cin >> t; while (t--){
cin >> n; vector<int> arr(n);
for (int i = 0; i < n; i++){ cin >> arr[i];
}
cout << "Enter the value of k: "; cin >> k;
int kthSmallest = quickSelect(arr, 0, n - 1, k - 1);
cout << "The " << k << "th smallest element is: " << kthSmallest << endl;
}
return 0;
}
