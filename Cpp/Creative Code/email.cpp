#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  map<string,int> mp;
  for (int i=0; i<n; i++){
    string s;
    cin>>s;
    if(mp[s]==0) {cout<<"OK"<<"\n"; mp[s]=1;}
    else{
      string t = s+to_string(mp[s]);
      cout<<t<<"\n";
      mp[t]=1;
      mp[s]++;
    }
  }
  return 0;
}
