#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  string s; cin>>s;
  vector<int> cnt(26,0);
  for(char &c:s){
    c=tolower(c);
  }
  // cout<<s<<"\n";
  for(char c:s){
    cnt[c-'a']++;
  }
  for (int i=0; i<26; i++){
    // cout<<cnt[i]<<" ";
    if(cnt[i]<1){cout<<"NO"<<"\n"; return 0;}
  }
  cout<<"YES"<<"\n";
  return 0;
}
