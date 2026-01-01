
#include <iostream> 
#include <vector> 
#include <ALGORITHM> 
using namespace std;
int binarySearch(vector<int> &arr, int key, int &comparisons)
{
int left = 0, right = arr.size() - 1; while (left <= right)
{
comparisons++;
int mid = left + (right - left) / 2; if (arr[mid] == key)
return mid;
else if (arr[mid] < key) left = mid + 1;
else
right = mid - 1;
}
return -1;
}
int main()
{
int n, key, t; cin >> t; while (t--)
{
cin >> n; vector<int> arr(n);
for (int i = 0; i < n; i++)
{
cin >> arr[i];
}
sort(arr.begin(), arr.end()); cin >> key;
int comparisons = 0;
int result = binarySearch(arr, key, comparisons); if (result != -1)
cout << "Element found\n"; else
cout << "Element not found\n";
cout << "Total comparisons: " << comparisons << "\n";
}
return 0;
}
