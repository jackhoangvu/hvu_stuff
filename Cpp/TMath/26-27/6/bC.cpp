#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int m,n; cin>>m>>n;
  vector<vector<long long>> a(m+1,vector<long long>(n+1,0));
  for(int i=1; i<=m; i++){
    for(int j=1; j<=n; j++){
      cin>>a[i][j];
    }
  }
  vector<vector<long long>> pref(m+1,vector<long long>(n+1,0));
  for(int i=1; i<=m; i++){
    for(int j=1; j<=n; j++){
      pref[i][j]=pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1]+a[i][j];
    }
  }
  int t; cin>>t;
  while(t--){
    int x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;
    long long ans=pref[x2][y2]-pref[x1-1][y2]-pref[x2][y1-1]+pref[x1-1][y1-1];
    cout<<ans<<"\n";
  }
  return 0;
}
