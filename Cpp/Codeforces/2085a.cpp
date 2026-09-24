#include <bits/stdc++.h>

using namespace std;
void solve(){
  int n,k; string s; cin>>n>>k;
  cin>>s;
  if(s.length()==1) cout<<"NO"<<"\n";
  else{
    bool ok=true;
    if(s.length()>0){}
    if(!ok) {cout<<"NO"<<"\n";}
    else{
      string tmp=s;
      reverse(s.begin(),s.end());
      if(s[0]>=tmp[0]) cout<<"YES"<<"\n";
    }
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
