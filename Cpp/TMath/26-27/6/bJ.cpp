#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int m,n,p; cin>>m>>n>>p;
  vector<vector<vector<long long>>> a(m+1,vector<vector<long long>>(n+1,vector<long long>(p+1)));
  for(int k=1; k<=p; k++){
    for(int j=1; j<=n; j++){
      for(int i=1; i<=m; i++){
        cin>>a[i][j][k];
      }
    }
  }
  vector<vector<vector<long long>>> pref(m+1,vector<vector<long long>>(n+1,vector<long long>(p+1)));
  for(int k=1; k<=p; k++){
    for(int j=1; j<=n; j++){
      for(int i=1; i<=m; i++){
        pref[i][j][k]=pref[i-1][j][k]+pref[i][j-1][k]+pref[i][j][k-1]-pref[i-1][j-1][k]-pref[i-1][j][k-1]-pref[i][j-1][k-1]+pref[i-1][j-1][k-1]+a[i][j][k];
      }
    }
  }
  int t; cin>>t;
  while(t--){
    int x1,y1,z1,x2,y2,z2; cin>>x1>>y1>>z1>>x2>>y2>>z2;
    long long ans=pref[x2][y2][z2]-pref[x1-1][y2][z2]-pref[x2][y1-1][z2]-pref[x2][y2][z1-1]+pref[x1-1][y1-1][z2]+pref[x1-1][y2][z1-1]+pref[x2][y1-1][z1-1]-pref[x1-1][y1-1][z1-1];
    cout<<ans<<"\n";
  }
  return 0;
}
