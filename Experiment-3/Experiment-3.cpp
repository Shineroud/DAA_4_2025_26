#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int findMaxStableWindow(int n, vector<char>& records) {
    unordered_map<int, int> mp;
    int sum = 0;
    int maxLen = 0;

    mp[0] = -1;

    for (int i = 0; i < n; i++) {
  
        sum += (records[i] == 'P') ? 1 : -1;

        if (mp.find(sum) != mp.end()) {
       
            maxLen = max(maxLen, i - mp[sum]);
        } else {
           
            mp[sum] = i;
        }
    }

    return maxLen;
}

int main() {
    int n;
    cin >> n;
    vector<char> records(n);
    for (int i = 0; i < n; i++) {
        cin >> records[i];
    }

    cout << findMaxStableWindow(n, records) << endl;
    return 0;
}