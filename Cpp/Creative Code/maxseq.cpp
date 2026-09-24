#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  vector<long long> a(n);
  for (int i=0; i<n; i++){
    cin>>a[i];
  }
  long long cur=0; long long ans=-LLONG_MAX;
  for (int i=0; i<n; i++){
    cur=max(a[i],a[i]+cur);
    ans=max(ans,cur);
  }
  cout<<ans;
  return 0;
}
