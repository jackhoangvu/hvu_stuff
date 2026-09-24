#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s,t; cin>>s>>t;
  for(char &c:s){
    c=tolower(c);
  }
  for(char &c:t){
    c=tolower(c);
  }
  if(s.compare(t)<0) cout<<-1<<"\n";
  else if(s.compare(t)==0) cout<<0<<"\n";
  else cout<<1<<"\n";
  return 0;
}
