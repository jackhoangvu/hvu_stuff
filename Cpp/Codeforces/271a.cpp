#include <bits/stdc++.h>

using namespace std;
bool valid(int n){
  //convert to string and check if all characters are distinct
  bool ok=true;
  string s=to_string(n);
  int cnt[10]={0};
  for (int i=0; i<s.size(); i++){
    cnt[s[i]-'0']++;
    if(cnt[s[i]-'0']>1){return false; break;}
  }
  return ok;
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  for(int i=n+1; i<=10000; i++){
    if(valid(i)) {cout<<i<<"\n"; break;}
  }
  return 0;
}
