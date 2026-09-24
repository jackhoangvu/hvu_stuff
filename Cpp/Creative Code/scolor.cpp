#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  map<int,vector<int>> mp;
  vector<long long> ans;
  for (int i=0; i<n; i++){
    long long x,c; cin>>x>>c;
    mp[c].push_back(x);
  }
  for(auto &it:mp){
    auto &c =it.second;
    sort(c.begin(),c.end());
    long long sum=0;
    for (int i=0; i<c.size(); i++){
      sum+=c[i]*(2*i -c.size()+1);
    }
    ans.push_back(sum);
  }
  sort(ans.begin(),ans.end());
  for (int i=0; i<ans.size(); i++){
    cout<<ans[i]<<"\n";
  }
  return 0;
}
