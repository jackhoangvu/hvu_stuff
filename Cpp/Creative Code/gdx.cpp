#include <bits/stdc++.h>

using namespace std;
bool ch(string s,int l,int r){
  long long cnt=0;
  while(l<r){
    if(s[l]!=s[r]) cnt++;
    if(cnt>2) return false;
    l++;
    r--;
  }
  return true;
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t; cin>>t;
  while(t--){
    string s; cin>>s;
    bool ok=false;
    for(int i=1; i<s.size(); i++){
      //s[1]..s[i] + s[i+1]..s[s.size()-1]
      if(ch(s,0,i-1)&&ch(s,i,s.size()-1)){ok=true; break;}
    }
    cout<<ok<<"\n";
  }
  return 0;
}
