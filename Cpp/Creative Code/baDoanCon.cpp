#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,k; cin>>n>>k;
  vector<int> a(n);
  vector<long long> pref(n);
  vector<long long> sum(n),l(n),r(n);
  for (int i=1; i<=n; i++){
    cin>>a[i];
    pref[i]=pref[i-1]+a[i];
  }
  int m=n-k+1;
  for (int i=1; i<=m; i++){
    sum[i]=pref[i+k-1]-pref[i-1];
  }
  l[1]=sum[1],r[m]=sum[m];
  for (int i=2; i<=m; i++){
    l[i]=max(l[i-1],sum[i]);
  }
  for (int i=m-1; i>=1; i--){
    r[i]=max(r[i+1],sum[i]);
  }
  long long ans=0;
  for (int i=k+1; i<=m-k; i++){
    ans=max(ans,(long long)l[i-k]+sum[i]+r[i+k]);
  }
  cout<<ans<<"\n";
  return 0;
}
