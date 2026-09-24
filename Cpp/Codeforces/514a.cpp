#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s; cin>>s;
  for(int i=0; i<s.length(); i++){
    char c=s[i];
    char inv='9'-c+'0';
    if(inv<c){
      if(i==0&&inv=='0') continue;
      s[i]=inv;
    }
  }
  cout<<s<<"\n";
  return 0;
}
