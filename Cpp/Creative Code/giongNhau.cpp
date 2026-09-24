#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin>>n;
  vector<string> a(n);
  long long ans=0;
  for (int i=0; i< n; i++) cin>>a[i];
  for (int pos=0; pos<10; pos++)
  {
    int cnt[10]={0};
    for (int i=0; i<n; i++)
    {
      int len=a[i].size();
      if (pos<len)
      {
        int d=a[i][len- 1 -pos]-'0';
        cnt[d]++;
      }
    }
    for (int d=0; d<10; d++)
    {
      long long c= cnt[d];
      ans += c*(c-1)/2;
    }
  }
  cout << ans;
  return 0;
}
