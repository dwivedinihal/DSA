#include <iostream> 
#include <vector> 
using namespace std;

void InsertionSort(vector<int> &arr, int &comparisons, int &shifts){ int n = arr.size();
comparisons = 0;
shifts = 0;
for (int i = 1; i < n; i++){ int key = arr[i];
int j = i - 1;
while (j >= 0 && arr[j] > key){ comparisons++;
arr[j + 1] = arr[j]; j--;
shifts++;
}
if (j >= 0) comparisons++;
arr[j + 1] = key; shifts++;
}
}
int main(){
int n, t, comparisons, shifts; cin >> t;
while (t--){ cin >> n;
vector<int> arr(n);
for (int i = 0; i < n; i++){ cin >> arr[i];
}
InsertionSort(arr, comparisons, shifts); for (int i = 0; i < n; i++){
cout << arr[i] << " ";
}
cout << "\nComparisons: " << comparisons << "\nShifts: " << shifts << "\n";
}
return 0;
}
