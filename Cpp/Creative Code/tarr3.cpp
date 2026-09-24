#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  long long x,y,z, a[200005],l[200005],r[200005];
  cin >>n>>x>>y>>z;
  for (int i=0;i<n;++i) cin>>a[i];
  if (n<3) {cout<<0<<'\n';return 0; }
  l[0]=LLONG_MIN;
  for (int i=1;i<n; ++i) l[i]=max(l[i- 1],a[i-1]*x);
  r[n-1]=LLONG_MIN;
  for (int i=n-2; i>=0;--i) r[i]=max(r[i +1], a[i+1]* z);
  long long ans= LLONG_MIN;
  for (int j=1; j<n-1; ++j) ans=max(ans,l[j]+a[j] * y+r[j]);
  cout<< ans<<'\n';
  return 0;
}
