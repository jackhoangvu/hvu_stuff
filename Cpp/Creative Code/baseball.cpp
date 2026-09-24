#include <bits/stdc++.h>
using namespace std;
int n, a[100002], b[100002];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    };
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    long long sa = 0, sb = 0, k = 0;
    for (int i = 0; i < n; i++)
    {
        sa += a[i];
        sb += b[i];
        if (sa == sb)
            k = i + 1;
    }
    cout << k;
    return 0;
}
