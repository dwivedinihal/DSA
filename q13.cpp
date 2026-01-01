#include <iostream>
 #include <bits/stdc++.h> 
 using namespace std;
char findMaxOccurrence(const char arr[], int n, int &maxFreq){ vector<int> freq(26, 0);
for (int i = 0; i < n; i++){
if (arr[i] >= 'a' && arr[i] <= 'z'){
freq[arr[i] - 'a']++;
}
}
int maxIndex = 0; maxFreq = 0;
for (int i = 0; i < 26; i++){ if (freq[i] > maxFreq){
maxFreq = freq[i]; maxIndex = i;
}
}
return 'a' + maxIndex;
}
int main(){ int n, t; cin >> t;
while (t--){
cout << "Enter the number of alphabets: "; cin >> n;
char arr[n];
cout << "Enter the alphabets: "; for (int i = 0; i < n; i++){
cin >> arr[i];
}
int maxFreq = 0;
char result = findMaxOccurrence(arr, n, maxFreq);
cout << "The alphabet with maximum occurrences is: " << result << " and it appears " << maxFreq
<< " times." << endl;
}
return 0;
}
