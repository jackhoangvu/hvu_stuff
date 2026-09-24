#include <bits/stdc++.h>
using namespace std;
int n,m,k,a[300005],q[300005];
void solve(){
  cin>>n>>m>>k;
  for (int i=0; i<m; i++){
    cin>>a[i];
  }
  for (int i=0; i<k; i++){
    cin>>q[i];
  }
  if(k<n-1){
    for(int i=0; i<m; ++i){
      cout<<"0";
    }
    cout<<"\n";
  }
  else if(k==(n-1)){
    long long s=1LL*n*(n+1)/2;
    for (int i=0; i<k; i++){
      s-=q[i];
    }
    for (int i=0; i<m; i++){
      if(a[i]==s) cout<<"1";
      else cout<<"0";
    }
    cout<<"\n";
  }
  else if(k==n){
    for (int i=0; i<m; i++){
      cout<<"1";
    }
    cout<<"\n";
  }
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
