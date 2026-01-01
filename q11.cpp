#include <iostream>
 #include <vector> 
 using namespace std;
void swap(int &a, int &b){ int temp = a;
a = b;
b = temp;
}
int partition(vector<int> &arr, int low, int high, int &comparisons, int &swaps){ int pivot = arr[high];
int i = low - 1;
for (int j = low; j < high; j++){ comparisons++;
if (arr[j] <= pivot){ i++;
swap(arr[i], arr[j]); swaps++;
}
}
swap(arr[i + 1], arr[high]); swaps++;
return i + 1;
}
void quickSort(vector<int> &arr, int low, int high, int &comparisons, int &swaps){ if (low < high){
comparisons++;
int pi = partition(arr, low, high, comparisons, swaps); quickSort(arr, low, pi - 1, comparisons, swaps); quickSort(arr, pi + 1, high, comparisons, swaps);
}
}
int main(){ int n, t; cin >> t;
while (t--){ cin >> n;
vector<int> arr(n);
for (int i = 0; i < n; i++){ cin >> arr[i];
}
int comparisons = 0, swaps = 0; quickSort(arr, 0, n - 1, comparisons, swaps); cout << "Sorted array: ";
for (int num : arr){ cout << num << " ";
}
cout << endl;
cout << "Comparisons = " << comparisons << endl; cout << "Swaps = " << swaps << endl;
}
return 0;}
