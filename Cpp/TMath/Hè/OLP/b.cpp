#include <bits/stdc++.h>

using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  vector<int> a(n);
  cin>>a[0];
  vector<int> mxd(n,0);
  vector<int> d(n+3,0);
  d[0]=a[0];
  mxd[0]=d[0];
  for (int i=1; i<n; i++){
    cin>>a[i];
    d[i]=a[i]-a[i-1];
    mxd[i]=max(d[i],mxd[i-1]);
  }
  // for (int i=0; i<n; i++){
  //   cout<<mxd[i]<<' ';
  // }
  cout<<"\n";
  int t; cin>>t;
  while(t--){
    long long x; cin>>x;
    auto it=upper_bound(mxd.begin(),mxd.end(),x);
    cout<<it-mxd.begin()<<"\n";
  }
  return 0;
}
