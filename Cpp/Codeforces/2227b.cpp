#include <bits/stdc++.h>

using namespace std;
void solve(){
  int n; cin>>n;
  string s; cin>>s;
  int cnt=0;
  for(char c:s){
    if(c=='(') cnt++;
    else if(c==')') cnt--;
  }
  if(cnt==0) cout<<"YES"<<"\n";
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
