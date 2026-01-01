#include <iostream> 
#include <vector> 
using namespace std;
void twoSum(vector<int> &arr, int targetSum, int n){

int i = 0, j = n - 1; bool found = false; while (i < j){
int sum = arr[i] + arr[j]; if (sum == targetSum){
found = true;
cout << "Found a pair : " << endl;
cout << arr[i] << " + " << arr[j] << " = " << targetSum << endl;
i++; j--;
}
else if (sum < targetSum){ i++;
}
else
j--;
}
if (!found){
cout << "No pair exists !!" << endl;
}
}
int findPivot(vector<int> &arr, int low, int high){ int pivotIndx = rand() % (high - low + 1) + low; swap(arr[pivotIndx], arr[high]);
int pivot = arr[high]; int i = low - 1;
int j = low; while (j < high){
if (arr[j] <= pivot){ i++;
swap(arr[i], arr[j]);
} j++;
}
swap(arr[i + 1], arr[high]); return i + 1;
}
void quickSort(vector<int> &arr, int low, int high){ if (low >= high)
return;
int pivot = findPivot(arr, low, high); quickSort(arr, low, pivot - 1); quickSort(arr, pivot + 1, high);
}
 
int main(){ int t;
cin >> t; while (t--){
int n;
cin >> n; vector<int> arr(n);
for (int i = 0; i < n; i++){ cin >> arr[i];
}
int targetSum = 0;
cout << "Enter the target Sum : " << endl; cin >> targetSum;
quickSort(arr, 0, n - 1);
cout << "The sorted array is : " << endl; for (auto num : arr)
cout << num << " "; cout << endl;
twoSum(arr, targetSum, n);
}
return 0;
}
