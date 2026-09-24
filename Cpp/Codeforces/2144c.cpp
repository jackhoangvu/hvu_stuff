#include <bits/stdc++.h>

using namespace std;
void solve(){
  int n; cin>>n;
  vector<int> a(n+1);
  for (int i=0; i<n; i++){
    cin>>a[i];
  }
  int last=-1,ans=0;
  for (int i=0; i<n; i++){
    if(a[i]>last+1) {ans++; last=a[i];}
  }
  cout<<ans<<"\n";
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
