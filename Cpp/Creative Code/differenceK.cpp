#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    vector<ll> sumB;
    sumB.reserve(m - k + 1);
    ll curB = 0;
    for (int i = 0; i < k; i++) curB += b[i];
    sumB.push_back(curB);
    for (int i = k; i < m; i++) {
        curB += b[i] - b[i - k];
        sumB.push_back(curB);
    }
    sort(sumB.begin(), sumB.end());
    ll ans = LLONG_MAX;
    ll curA = 0;
    for (int i = 0; i < k; i++) curA += a[i];
    auto update = [&](ll x) {
        auto it = lower_bound(sumB.begin(), sumB.end(), x);
        if (it != sumB.end())
            ans = min(ans, llabs(x - *it));
        if (it != sumB.begin())
            ans = min(ans, llabs(x - *prev(it)));
    };
    update(curA);
    for (int i = k; i < n && ans != 0; i++) {
        curA += a[i] - a[i - k];
        update(curA);
    }
    cout << ans << '\n';
    return 0;
}
