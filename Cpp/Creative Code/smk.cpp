#include <bits/stdc++.h>
using namespace std;

long long n, k;
long long a[1000005];
long long s, ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    if (n < k) return 0;
    s = 0;
    for (int i = 0; i < k; i++) {
        s += a[i];
    }
    ans = s;
    for (int i = k; i < n; i++) {
        s = s + a[i] - a[i - k];
        if (s < ans) ans = s;
    }
    cout << ans;
    return 0;
}
