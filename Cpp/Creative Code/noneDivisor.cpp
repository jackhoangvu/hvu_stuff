#include <bits/stdc++.h>
using namespace std;

int last_pos[100005],x,y;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        vector<int> d;
        // fint divisor
        for (int j = 1; j * j <= x; j++) {
            if (x % j == 0) {
                d.push_back(j);
                if (j * j != x) d.push_back(x / j);
            }
        }
        int ans = 0;
        int limit = i - y;
        for (int a:d) {
            if (last_pos[a] < limit) {
                ans++;
            }
        }
        cout << ans << "\n";
        for (int a : d) {
            last_pos[a] = i;
        }
    }

    return 0;
}
