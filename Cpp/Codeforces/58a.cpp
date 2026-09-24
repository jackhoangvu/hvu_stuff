#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s; cin>>s;
  int tar=0;
  string w="hello";
  for(char c:s){
    if(c==w[tar]) tar++;
    if(tar==w.length()) break;
  }
  if(tar==w.length()) {cout<<"YES"<<"\n"; return 0;}
  cout<<"NO";
  return 0;
}
