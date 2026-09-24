#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  string s[105];
  for (int i=0; i<n; i++){
    cin>>s[i];
    if(s[i].size()>10)
      cout<<s[i].substr(0,1)<<s[i].size()-2<<s[i].substr(s[i].size()-1, s[i].size())<<"\n";
    else
      cout<<s[i]<<"\n";
  }
  return 0;
}
