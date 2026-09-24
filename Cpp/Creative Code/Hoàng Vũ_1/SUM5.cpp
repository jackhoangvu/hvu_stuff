#include <bits/stdc++.h>

using namespace std;

int main()
{

    ifstream fin("SUM5.INP");
    ofstream fout("SUM5.OUT");

    long long n;
    if (!(fin >> n))
    {
        return 0;
    }
    long long c[5] = {0};
    c[0] = 1;
    long long t = 0;
    long long ans = 0;
    for (long long i = 0; i < n; i++)
    {
        long long x;
        fin >> x;
        t = (t + x) % 5;
        if (t < 0)
        {
            t += 5;
        }
        ans += c[t];
        c[t]++;
    }

    fout << ans;

    fin.close();
    fout.close();

    return 0;
}