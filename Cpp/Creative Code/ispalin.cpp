#include <bits/stdc++.h>

using namespace std;
bool pal(string s,int l,int r){
  if(l>=r) return true;
  if(s[l]!=s[r]) return false;
  return pal(s,l+1,r-1);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  vector<string> vt(n+1);
  for (int i=0; i<n; i++){
    cin>>vt[i];
    if(pal(vt[i],0,vt[i].length()-1)) cout<<1<<"\n";
    else cout<<0<<"\n";
  }
  return 0;
}
