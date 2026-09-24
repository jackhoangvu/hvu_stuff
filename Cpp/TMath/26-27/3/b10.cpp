#include<bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n; long long k; cin>>n>>k;
  vector<long long> a(n+1),b(n+1,0);
  for(int i=1; i<=n; i++) cin>>a[i];
  for(int i=1; i<n; i++) cin>>b[i];
  vector<long long>dp(n+1,0LL);
  vector<int>cnt(n+1,0);
  dp[0]=0;
  cnt[0]=0;
  if(n>=1){
    dp[1]=a[1]+k;
    cnt[1]=1;
  }
  for(int i=2; i<=n; ++i){
    long long t1=dp[i-1]+a[i]+k;
    long long t2=dp[i-2]+b[i-1]+k;
    int c1=cnt[i-1]+1;
    int c2=cnt[i-2]+1;
    if(t1<t2){
      dp[i]=t1;
      cnt[i]=c1;
    }
    else if(t2<t1){
      dp[i]=t2;
      cnt[i]=c2;
    }
    else{
      dp[i]=t1;
      cnt[i]=min(c1,c2);
    }
  }
  cout<<dp[n]<<" "<<cnt[n]<<"\n";
  return 0;
}
