#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s; cin>>s;
  int cnt=1,mx=-200;
  for(int i=0; i<s.length()-1; i++){
    if(s[i]==s[i+1]) {cnt++;mx=max(mx,cnt);}
    else cnt=1;
  }
  cout<<(mx>=7?"YES":"NO");
  return 0;
}
