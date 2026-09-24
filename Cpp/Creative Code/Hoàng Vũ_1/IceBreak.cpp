#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<long long> d(n + 1), w(n + 1), h(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i] >> w[i];
        h[i] = d[i];
    }

    using P = pair<long long, int>;
    priority_queue<P, vector<P>, greater<P>> q;
    for (int i = 1; i <= n; i++) q.push({h[i], i});
    
    vector<bool> c(n + 1, false);
    long long ans = 0;
    while (!q.empty())
    {
        auto t = q.top();
        q.pop();
        long long v = t.first;
        int i = t.second;

        if (c[i]) continue;
        if (v != h[i]) continue;
        if (h[i] <= 0) { c[i] = true;continue; }

        ans += h[i];
        h[i] = 0;
        c[i] = true;

        if (i > 1 && !c[i - 1]) { h[i - 1] -= w[i];q.push({h[i - 1], i - 1}); }
        if (i < n && !c[i + 1]) { h[i + 1] -= w[i];q.push({h[i + 1], i + 1}); }
    }
    cout << ans;
    return 0;
}
