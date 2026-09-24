#include <bits/stdc++.h>

using namespace std;
const long long MOD=1e9+7;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  map<int, int> cnt;
  for (int i=0; i<n; i++){
    int x; cin>>x;
    cnt[x]++;
  }
  long long ans=1;
  for (auto [x,y]:cnt){
    ans=(ans*(y+1))%MOD;
  }
  ans=(ans-1+MOD)%MOD;
  cout<<ans;
  return 0;
}
