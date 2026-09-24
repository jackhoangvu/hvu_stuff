#include <bits/stdc++.h>

using namespace std;
bool pr(long long n){
  if(n<=1) return false;
  for(int i=2; i*i<=n; i++){
    if(n%i==0) return false;
  }
  return true;
}
bool ch(long long n){
  //
  long long nn=n;
  while(nn>0){
    if(!pr(nn)) return false;
    nn/=10;
  }
  for (int i=1; i<10; i++){
    if(pr(n*10+i)) return true;
  }
  return false;
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  vector<int> a(n+2);
  vector<int> pref(n+2,0);
  for (int i=1; i<=n; i++){
    cin>>a[i];
    pref[i]=pref[i-1]+(ch(a[i])?1:0);
  }
  int m; cin>>m;
  for (int i=0; i<m; i++){
    int u,v; cin>>u>>v;
    cout<<pref[v]-pref[u-1]<<"\n";
  }
  return 0;
}
