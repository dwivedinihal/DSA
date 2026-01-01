#include <iostream>
 #include <vector>
  using namespace std;

int countPairsWithDifference(vector<int> &arr, int k)
{
int count = 0, n = arr.size(); for (int i = 0; i < n; i++)
{
for (int j = i + 1; j < n; j++)
{
if (abs(arr[i] - arr[j]) == k) count++;
}
}
return count;
}

int main()
{
int n, k, t; cin >> t; while (t--)
{
cin >> n; vector<int> arr(n);
for (int i = 0; i < n; i++) cin >> arr[i];
cin >> k;
cout << "Number of pairs with difference: " << countPairsWithDifference(arr, k) << "\n";
}
return 0;
}
