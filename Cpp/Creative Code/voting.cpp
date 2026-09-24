#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  map<string,int> mp;
  int ma=0;
  for (int i=0; i<n; i++){
    string s; cin>>s;
    mp[s]++;
    ma=max(ma, mp[s]);
  }
  for(auto it:mp){
    if(it.second==ma){
      cout<<it.first<<"\n";
    }
  }
  return 0;
}
