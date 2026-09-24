#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int s,n; cin>>s>>n;
  vector<pair<int,int>> d;
  for (int i=0; i<n; i++){
    cin>>d[i].first>>d[i].second;
  }
  sort(d.begin(),d.end());
  long long cur=s;
  for (int i=0; i<n; i++){
    if(cur<d[i].first){cout<<"NO"; return 0;}
    else cur+=d[i].second;
  }
  cout<<"YES";
  return 0;
}
