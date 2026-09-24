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
  for (int i=0; i<n; i++){
    long long need=x-vp[i].first;
    //two pointer
    int l=i+1, r=n-1;
    while(l<r){
      if(vp[l].first+vp[r].first==need){cout<<vp[i].second<<" "<<vp[l].second<<" "<<vp[r].second; return 0;}
      else if(vp[l].first+vp[r].first>need) r--;
      else l++;
    }
  }
  cout<<"IMPOSSIBLE";
  return 0;
}
