#include <bits/stdc++.h>

using namespace std;
long long a, b, c, d;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> c >> d;
    long long res = min(b, d) - max(a, c) + 1;
    cout << res << endl;

    return 0;
}
