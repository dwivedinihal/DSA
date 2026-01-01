#include <iostream>
 #include <vector>
  using namespace std;
int comparisons = 0, inversions = 0;
void merge(vector<int> &v, int low, int mid, int high){ vector<int> temp;
int i = low, j = mid + 1;
while (i <= mid && j <= high){ comparisons++;
if (v[i] <= v[j]) temp.push_back(v[i++]);
else{
temp.push_back(v[j++]); inversions += (mid - i + 1);
}
}
while (i <= mid) temp.push_back(v[i++]);
while (j <= high) temp.push_back(v[j++]);
for (int k = low; k <= high; k++){ v[k] = temp[k - low];
}
}
void mergesort(vector<int> &v, int low, int high){ if (low < high){
int mid = low + (high - low) / 2; mergesort(v, low, mid); mergesort(v, mid + 1, high); merge(v, low, mid, high);
}
}
int main(){ int n, t; cin >> t; while(t--){
cin >> n; vector<int> v(n);
for (int i = 0; i < n; i++) cin >> v[i];
mergesort(v, 0, n - 1); for (int i = 0; i < n; i++)
cout << v[i] << " ";
cout << "\nComparisons:" << comparisons << "\nInversions:" << inversions << "\n";
}
return 0;
}
