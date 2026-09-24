#include <bits/stdc++.h>
using namespace std;

int n, l[1000002], d[4005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    int mlen = 0;
    for (int i = 0; i < n; i++) {
        cin >> l[i];
        d[l[i]]++;
        mlen = max(mlen, l[i]);
    }

    int ans1 = 0, ans2 = 0;

    for (int h = 2; h <= 2 * mlen; h++) {
        int lo = max(1, h - mlen);
        int hi = min(mlen, h - 1);

        int s = 0;
        int x = lo, y = h - x;

        while (x < y) {
            if (d[x] && d[y])
                s += min(d[x], d[y]);
            x++, y--;
        }
        if (x == y)
            s += d[x] / 2;

        if (s > ans1) {
            ans1 = s;
            ans2 = 1;
        } else if (s == ans1) {
            ans2++;
        }
    }

    cout << ans1 << " " << ans2;
    return 0;
}
