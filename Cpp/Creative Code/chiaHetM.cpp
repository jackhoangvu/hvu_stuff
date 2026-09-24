#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; long long m; cin>>n;
  vector<long long> a(n+5);
  for (int i=0; i<n; ++i){
    cin>>a[i];
  }
  cin>>m;
  map<long long, long long> cnt;
  long long ans=0;
  for (int i=0; i<n; ++i){
    long long r= a[i]%m;
    if (r<0) r+= m;
    ans += cnt[(m-r)% m];
    cnt[r]++;
  }
  cout<<ans;
  return 0;
}
