#include <iostream> 
#include <vector> 
#include <ALGORITHM>
 using namespace std;
bool hasDuplicate(vector<int> &arr){ sort(arr.begin(), arr.end());
for (int i = 1; i < arr.size(); i++){ if (arr[i] == arr[i - 1])
return true;
}
return false;
}

int main(){ int n, t; cin >> t;
while (t--){ cin >> n;
vector<int> arr(n);
for (int i = 0; i < n; i++){ cin >> arr[i];
}
if (hasDuplicate(arr)) cout << "YES\n";
else
cout << "No\n";
}
return 0;
}
