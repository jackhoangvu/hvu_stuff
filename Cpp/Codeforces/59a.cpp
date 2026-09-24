#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s; cin>>s;
  int up=0, lo=0;
  for(char c:s){
    if(isupper(c)) up++;
    else lo++;
  }
  if(up>lo){
    for(char &c:s) c=toupper(c);
  }
  else{
    for(char &c:s) c=tolower(c);
  }
  cout<<s;
  return 0;
}
