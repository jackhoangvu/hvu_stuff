#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  vector<int> a(n);
  vector<pair<int,int>> vt(n);
  for (int i=0; i<n; i++){
    cin>>a[i];
    vt[i].first=a[i];
    vt[i].second=i;
  }
  sort(vt.begin(),vt.end());
  int q; cin>>q;
  while(q--){
    int x; cin>>x;
    auto it=equal_range(vt.begin(),vt.end(),make_pair(x,-1));
    if(it.first!=vt.end()&&it.first->first==x) cout<<it.first->second+1<<"\n";
    else cout<<0<<"\n";
  }
  return 0;
}
