#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  vector<pair<int,int>> m(n);
  for (int i=0; i<n; i++){
    cin>>m[i].second>>m[i].first;
  }
  sort(m.begin(),m.end());
  int prev=0,cnt=0;
  for(int i=0; i<n; i++){
    if(m[i].second>=prev){
      cnt++;
      prev=m[i].first;
    }
  }
  cout<<cnt;
  return 0;
}
