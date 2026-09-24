#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int m,n; cin>>m>>n;
  vector<vector<int>> a(m,vector<int>(n));
  for (int i=0; i<m; i++){
    for (int j=0; j<n; j++){
      cin>>a[i][j];
    }
  }
  long long ans=-LLONG_MAX;
  for(int u=0; u<m; u++){
    vector<long long> c(n,0);
    long long cur=0;
    for(int v=u; v<m; v++){
      for(int j=0; j<n; j++){
        c[j]+=a[v][j];
      }
      cur=c[0];
      for(int j=1; j<n; j++){
        cur=max(c[j],cur+c[j]);
        ans=max(ans,cur);
      }
      ans=max(ans,c[0]);
    }
  }
  cout<<ans;
  return 0;
}
