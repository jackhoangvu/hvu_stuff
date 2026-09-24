#include <bits/stdc++.h>
using namespace std;

int n, a[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    unordered_map<int,int> freq;
    for (int i = 0; i < n; i++)
        freq[a[i]]++;
    vector<int> val;
    for (auto it : freq)
        val.push_back(it.first);
    sort(val.begin(), val.end(), greater<int>());
    cout << val.size() << '\n';
    for (int x : val)
        cout << x << " " << freq[x] << '\n';
    return 0;
}
