#include <bits/stdc++.h>

using namespace std;
long long x1, x2, x3, Y1, Y2, Y3;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> x1 >> x2 >> x3 >> Y1 >> Y2 >> Y3;
    if (x1 > Y1)
    {
        swap(x1, Y1);
    }
    if (x2 > Y2)
    {
        swap(x2, Y2);
    }
    if (x3 > Y3)
    {
        swap(x3, Y3);
    }
    long long L = max(max(x1, x2), x3);
    long long R = min(min(Y1, Y2), Y3);
    if (L < 1) {
        L = 1;
    }
    if (L > R)
    {
        cout << 0;
    }
    else
    {
        cout << R - L + 1;
    }
    return 0;
}
