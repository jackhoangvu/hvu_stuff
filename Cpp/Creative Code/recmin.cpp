#include <bits/stdc++.h>

using namespace std;
int a[202][1002];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int m,n,k; cin>>m>>n>>k;

  for (int i=0; i<m; i++){
    for (int j=0; j<n; j++){
      cin>>a[i][j];
    }
  }

  long long ans=1e9;
  for(int i=0; i<n; i++){
    vector<long long> c(m,0);
    for(int j=i; j<n; j++){
      for(int u=0; u<m; u++){
        c[u]+=a[u][j];
      }
      long long l=0,sum=0;
      for(int r=0; r<m; r++){
        sum+=c[r];
        while(l<=r and sum>k){
          sum-=c[l];
          l++;
        }
        if(sum==k) ans=min(ans,(j-i+1)*(r-l+1));
      }
    }
  }
  if(ans!=1e9) cout<<ans;
  else cout<<-1<<"\n";
  return 0;
}
