#include<bits/stdc++.h>
using namespace std;
long long dem(long long n){
  long long ans=0;
  for(long long p=5; p<=n; p*=5){
    ans+=n/p;
  }
  return ans;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t; cin>>t;
  while(t--){
    long long x; cin>>x;
    if(x==0){
      cout<<0<<"\n";
      continue;
    }
    long long l=0,r=5*x+5;
    long long ans=-LLONG_MAX;
    while(l<=r){
      long long mid=l+(r-l)/2;
      if(dem(mid)>=x){
        ans=mid;
        r=mid-1;
      }else{
        l=mid+1;
      }
    }
    if(ans!=1 and dem(ans)==x) cout<<ans<<"\n";
    else cout<<-1<<"\n";
  }
  return 0;
}
