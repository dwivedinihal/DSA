#include <bits/stdc++.h>
using namespace std;
int firstOccurrence(vector<int> &arr, int key){ 
     int left = 0, right = arr.size() - 1, result = -1; 
     while (left <= right){
         int mid = left + (right - left) / 2; 
         if (arr[mid] == key){
         result = mid; right = mid - 1;
     }
     else if (arr[mid] < key) left = mid + 1;
     else right = mid - 1;
}
     return result; }
int lastOccurrence(vector<int> &arr, int key){ 
     int left = 0, right = arr.size() - 1, result = -1; 
     while (left <= right){
         int mid = left + (right - left) / 2; 
         if (arr[mid] == key){ result = mid; left = mid + 1;}
         else if (arr[mid] < key) left = mid + 1;
         else right = mid - 1;
     }
     return result; }
int main(){ 
     int t;
     cin >> t; 
     while (t--){
     int n, key;  
     cin >> n;
      vector<int> arr(n);
     for (int i = 0; i < n; i++) cin >> arr[i];
     cin >> key;
     int comparisons = 0;
     int first = firstOccurrence(arr, key);  
     if (first == -1) cout << "Element not found\n";
     else{
     int last = lastOccurrence(arr, key); cout << "Element found\n";
     cout << "Total occurrences: " << (last - first + 1) << "\n";
}
}
return 0;
}
