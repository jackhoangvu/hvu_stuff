#include <bits/stdc++.h>

using namespace std;
const int mxn=5005;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  int a[mxn];
  long long s=0;
  for (int i=1; i<=n; i++){
    cin>>a[i];
    s+=a[i];
  }
  vector<vector<long long>> dp(n+2,vector<long long>(n+2,0));
  for (int i=1; i<=n; i++){
    dp[i][i]=a[i];
  }
  for(int l=n; l>=1; l--){
    for(int r=l+1; r<=n; r++){
      dp[l][r]=max(a[l]-dp[l+1][r],a[r]-dp[l][r-1]);
    }
  }
  cout<<(s+dp[1][n])/2<<"\n";
  return 0;
}
