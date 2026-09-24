#include <bits/stdc++.h>
using namespace std;
int t;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin>>a[i];
    long long ans= 0;
    int max_ = a[n-1];
    for (int k = 2; k < n; k++)
    {
      int i= 0,j = k-1;
      int mt = max(a[k], max_ - a[k]);
      while (i < j)
      {
        if (a[i] + a[j] > mt)
        {
          ans += (j-i);
          j--;
        }
        else
          i++;
      }
    }
    cout<< ans << '\n';
  }
  return 0;
}
