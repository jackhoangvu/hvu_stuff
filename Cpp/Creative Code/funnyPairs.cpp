#include <bits/stdc++.h>
using namespace std;
int t, n;
long long x, y;
long long dem(vector<long long> &a, long long val)
{
  long long cnt = 0;
  int i = 0, j = n - 1;
  while (i < j)
  {
    if (a[i] + a[j] <= val)
    {
      cnt += (j - i);
      i++;
    }
    else
      j--;
  }
  return cnt;
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> t;
  while (t--)
  {
    cin >> n >> x >> y;
    vector<long long> a(n);
    long long S = 0;
    for (int i = 0; i < n; i++)
    {
      cin>>a[i];
      S += a[i];
    }
    sort(a.begin(), a.end());
    long long l= S-y;
    long long r= S-x;
    cout << dem(a,r) - dem(a, l- 1) << '\n';
  }
  return 0;
}
