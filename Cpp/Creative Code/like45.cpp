#include <iostream>
#include <algorithm>

using namespace std;
long long n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    long long x_min = (-n % 5 + 5) % 5;
    if (n / 4 < x_min)
    {
        cout << 0;
        return 0;
    }
    long long x_max = n / 4 - ((n / 4 - x_min) % 5);
    long long ans = (x_max - x_min) / 5 + 1;
    cout << ans;
    return 0;
}
