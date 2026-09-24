#include <bits/stdc++.h>

using namespace std;
bool cnt[100005];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  getline(cin,s);
  int cnt[11]={0};
  for(char c:s){
    if(0<=(c-'0')&&(c-'0')<=9) cnt[c-'0']++;
  }
  for (int i=0; i<10; i++){
    cout<<cnt[i]<<" ";
  }
  return 0;
}
