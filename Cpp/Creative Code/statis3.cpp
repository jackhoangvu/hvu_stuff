#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;cin>>n;
  vector<int> a(n+5);
  for (int i=0; i<n; i++){
    cin>>a[i];
  }
  map<long long,int> mp;
  for (int i=0; i<n; i++){
    mp[a[i]]++;
  }
  long long a1=0, a2=0;
  for(auto [u,v]:mp){
    if(v>a2){
      a2=v;
      a1=u;
    }
  }
  cout<<a1<<"\n"<<a2;
  return 0;
}
