#include <bits/stdc++.h>

using namespace std;

void solve(){
  int n;cin>>n;
  int a[100001],b[100001],ma=0,mb=0;
  for (int i=0; i<n; i++){
    cin>>a[i];
    ma=max(a[i],ma);
  }
  for (int i=0; i<n; i++){
    cin>>b[i];
    mb=max(b[i],mb);
  }
  int mx=max(ma,mb);
  long long s=0;
  for (int i=0; i<n; i++){
    if(a[i]>b[i]) swap(a[i],b[i]);
    mx=max(mx,a[i]);
    s+=b[i];
  }
  cout<<s+mx<<"\n";
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t; cin>>t;
  while(t--){
    solve();
  }
  return 0;
}
