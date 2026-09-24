#include <bits/stdc++.h>

using namespace std;
void solve(){
  int n; cin>>n;
  string s; cin>>s;
  int best=0, cnt=0;
  vector<int> r;
  for(int i=0; i<n; i++){
    if(s[i]=='#'){
      cnt++;
    } else {
      if(cnt>0) r.push_back(cnt);
      cnt=0;
    }
  }
  if(cnt>0) r.push_back(cnt);
  for(auto i:r){
    best=max(best,(i+1)/2);
  }
  cout<<best<<"\n";
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
