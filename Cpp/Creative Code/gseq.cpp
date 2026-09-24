#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,a[200005];
  cin>>n;
  for (int i=0; i<n; i++){
    cin>>a[i];
  }
  int ans=n;
  map<int,int> mp;
  for (int i=0; i<n; i++){
    mp[a[i]]++;
  }
  for(auto it:mp){
    if(it.second>= it.first){
      ans-= it.first;
    }
  }
  cout<<ans;
  return 0;
}
