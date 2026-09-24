#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  string s; cin>>s;
  int cnt=0;
  for(int i=1; i<n; i++){
    if(s[i-1]==s[i]) {cnt++; s[i]='#';}
  }
  cout<<cnt;
  return 0;
}
