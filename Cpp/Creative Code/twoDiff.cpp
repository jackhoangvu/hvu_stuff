#include <bits/stdc++.h>

using namespace std;
long long n_;

long long solve_k(int k, int n_, const vector<int> &a)
{
    map<int, int> freq;
    long long tong = 0;
    int dacbiet = 0;
    int L = 0;
    for (int R = 0; R < n_; ++R)
    {
        if (freq[a[R]] == 0)
        {
            dacbiet++;
        }
        freq[a[R]]++;
        while (dacbiet > k)
        {
            freq[a[L]]--;
            if (freq[a[L]] == 0)
            {
                dacbiet--;
            }
            L++;
        }
        tong += (R - L + 1);
    }
    return tong;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long long res = (long long)n * (n + 1) / 2 - solve_k(1, n, a);
    cout << res;
    return 0;
}
