#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s,t; cin>>s>>t;
  for(int i=0; i<s.length(); i++){
    cout<<(s[i]^t[i]);
  }
  cout<<"\n";
  return 0;
}
