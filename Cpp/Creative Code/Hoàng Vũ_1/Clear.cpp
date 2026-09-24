#include <bits/stdc++.h>

using namespace std;

int t(int n)
{
    int s = 0;
    while (n > 0)
    {
        int d = n % 10;
        s += d * d;
        n /= 10;
    }
    return s;
}

bool c(int n)
{
    set<int> l;
    while (n != 1 && l.find(n) == l.end())
    {
        l.insert(n);
        n = t(n);
    }
    return n == 1;
}

int main()
{
    ifstream fin("CLEAR.INP");
    ofstream fout("CLEAR.OUT");

    int A, B;
    fin >> A >> B;

    int ans = 0;
    for (int i = A; i <= B; i++)
    {
        if (c(i))
        {
            ans++;
        }
    }
    fout << ans;
    return 0;
}