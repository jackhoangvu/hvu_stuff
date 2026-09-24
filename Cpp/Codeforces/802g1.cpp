#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s; cin>>s;
  string target="heidi";
  int idx=0;
  for(char c:s){
    if(c==target[idx]) idx++;
    if(idx==target.length()) break;
  }
  if(idx==target.length()) cout<<"YES";
  else cout<<"NO";
  return 0;
}
