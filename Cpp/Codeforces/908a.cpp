#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s; cin>>s;
  int cnt=0;
  for(char c:s){
    if(c=='e'||c=='a'||c=='i'||c=='o'||c=='u') cnt++;
    else if(c=='1'||c=='3'||c=='5'||c=='7'||c=='9') cnt++;
  }
  cout<<cnt;
  return 0;
}
