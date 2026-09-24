#include <bits/stdc++.h>

using namespace std;
int pref[500005][41];
const int mod=1e9+7;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,m,q; cin>>n>>m>>q;
  // vector<vector<int>> pref(42,vector<int>(n+1,0));
  // vector<int> a(n+3);
  for (int i=1; i<=n; i++){
    int x; cin>>x;
    for (int c=1; c<=m; c++) pref[i][c]=pref[i-1][c];
    pref[i][x]++;
  }
  while(q--){
    long long ans=1;
    int l,r; cin>>l>>r;
    for (int c=1; c<=m; c++){
      long long cnt=pref[r][c]-pref[l-1][c];
      if(cnt>0) ans=(ans*cnt)%mod;
    }
    cout<<ans<<"\n";
  }
  return 0;
}
