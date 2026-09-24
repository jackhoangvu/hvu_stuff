#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n;
    if (!(cin >> n))
    {
        return 0;
    }
    long long s = 0;
    for (long long i = 0, x; i < n - 1; i++)
    {
        cin >> x;
        s += x;
    }
    long long t = n * (n + 1) / 2;
    cout << (t - s) << '\n';
    return 0;
}
