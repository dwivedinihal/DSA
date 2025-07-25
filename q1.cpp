#include <iostream> 
#include <vector> 
using namespace std;

void LinearSearch(vector<int> &arr, int key)
{
int comparisons = 0;
for (int i = 0; i < arr.size(); i++)
{
comparisons++; if (arr[i] == key)
{
cout << "Element found\n";
cout << "Total comparisons: " << comparisons << "\n"; return;
}
}
cout << "Element not found\n";
cout << "Total comparisons: " << comparisons << "\n";
}

int main()
{
int t;
cin >> t; while (t--)
{
int n, key; cin >> n;
vector<int> arr(n);
for (int i = 0; i < n; i++) cin >> arr[i];
cin >> key; LinearSearch(arr, key);
}

return 0;
}
