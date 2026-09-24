#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin>>s;
  int ans=1;
  int ma=1;
  for(int i=0; i<s.length()-1; ++i){
    if(s[i]==s[i+1]){
      ans++;
    }
    else{
      ans=1;
    }
    ma=max(ma,ans);
  }
  cout<<ma;
  return 0;
}
