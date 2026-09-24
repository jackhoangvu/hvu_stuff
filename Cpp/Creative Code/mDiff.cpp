#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    ll maxP = llabs(2 * b - 3 * c);
    ll minP = llabs(2 * a - 3 * d);
    ll res = max(maxP, minP);
    cout << res << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--)
    {
        solve();
    }

    return 0;
}
