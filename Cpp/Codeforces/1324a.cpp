#include <bits/stdc++.h>

using namespace std;
void solve(){
  int n; cin>>n;
  int a[105];
  bool ok=true;
  for (int i=0; i<n; i++){
    cin>>a[i];
  }
  for (int i=0; i<n-1; i++){
    if(a[i]%2!=a[i+1]%2) ok=false;
  }
  if(ok) cout<<"YES"<<"\n";
  else cout<<"NO"<<"\n";
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
