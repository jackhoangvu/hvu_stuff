#include <bits/stdc++.h>

using namespace std;
void solve(){
  int n; cin>>n;
  vector<int> a(n+1);
  long long pref=0;
  bool ok=true;
  for (int i=0; i<n; i++){
    cin>>a[i];
    long long mi=(long long)(i+1)*(i+2)/2;
    pref+=a[i];
    if(pref<mi){
      ok=false;
    }
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
