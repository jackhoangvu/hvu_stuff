#include <bits/stdc++.h>
using namespace std;

long long n, k;
long long a[1000005];
long long s, ans, chan = 0, le = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (n < k)
        return 0;
    for (int i = 0; i < k; i++) {
        s += a[i];
        if (a[i] % 2 == 0) chan++;
        else le++;
    }
    if (chan > 0 && le > 0) {
        ans = s;
    }
    for (int i = k; i < n; i++)
    {
        s += a[i];
        if (a[i] % 2 == 0) chan++;
        else le++;
        if (a[i - k] % 2 == 0) chan--;
        else le--;
        s -= a[i - k];

        if (chan > 0 && le > 0) {
            if (s < ans) {
                ans = s;
            }
        }
    }
    cout << ans;
    return 0;
}
