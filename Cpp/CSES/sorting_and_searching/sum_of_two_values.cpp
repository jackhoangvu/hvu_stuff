#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,x,a[200005]; cin>>n>>x;
  vector<pair<long long,int>> vp;
  for (int i=1; i<=n; i++){
    cin>>a[i];
    vp.push_back({a[i],i});
  }
  sort(vp.begin(),vp.end());
  bool ok=false;
  int l=0, r=n-1;
  while(l<r){
    if(vp[l].first+vp[r].first==x) {ok=true; cout<<vp[l].second<<" "<<vp[r].second<<"\n"; return 0;}
    else if(vp[l].first+vp[r].first>x) r--;
    else l++;
  }
  if(!ok) cout<<"IMPOSSIBLE";
  return 0;
}
