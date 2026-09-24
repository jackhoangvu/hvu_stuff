#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s; cin>>s;
  string ans="";
  int cnt[26]={0};
  for(char c:s){
    cnt[c-'A']++;
  }
  int odd=0, idx=-1;
  for(int i=0; i<26; i++){
    if(cnt[i]%2!=0) {odd++; idx=i;}
  }
  if(odd>1) {cout<<"NO SOLUTION"; return 0;}
  ans.reserve(s.length()/2);
  for(int i=0; i<26; i++){
    ans+=string(cnt[i]/2,'A'+i);
  }
  string rans=ans;
  reverse(rans.begin(),rans.end());
  if(idx!=-1){
    ans+=string(1,'A'+idx);
  }
  ans+=rans;
  cout<<ans;
  return 0;
}
