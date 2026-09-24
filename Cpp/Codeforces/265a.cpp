#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s,t; cin>>s>>t;
  int pos=0;
  for(char c:t){
    if(c==s[pos]) pos++;
  }
  cout<<pos+1;
  return 0;
}
