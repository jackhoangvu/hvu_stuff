#include <iostream>
#include <algorithm>

using namespace std;
int n, a[100005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    long long max = 0;
    for (int i = 0; i < n; i++)
    {
        long long t = a[i] * (n - i);
        if (t > max)
        {
            max = t;
        }
    }
    cout << max;
    return 0;
}
