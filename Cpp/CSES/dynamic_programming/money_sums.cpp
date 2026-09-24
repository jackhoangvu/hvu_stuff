#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  int a[102];
  long long mx=0;
  for (int i=0; i<n; i++){
    cin>>a[i];
    mx+=a[i];
  }
  vector<bool> dp(mx+1,false);
  dp[0]=true;
  for(int c=0; c<n; c++){
    for(int x=mx; x>=a[c]; x--){
      if(dp[x-a[c]]) dp[x]=true;
    }
  }
  int cnt=0;
  vector<int> val;
  for(int i=1; i<=mx; i++){
    if(dp[i]) {
      cnt++;
      val.push_back(i);
    }
  }
  cout<<cnt<<"\n";
  for (int i=0; i<val.size(); i++){
    cout<<val[i]<<" ";
  }
  return 0;
}
