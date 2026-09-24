#include<bits/stdc++.h>
using namespace std;
int n,x[102],y[102];
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(int i=0; i<=n; i++){
    cin>>x[i];
    cin>>y[i];
  }
  long long ans=0,s=0;
  for(int i=0; i<=n; i++){
    s+=(x[i]-y[i]);
    ans=max(ans,s);
  }
  cout<<ans;
  return 0;
}
