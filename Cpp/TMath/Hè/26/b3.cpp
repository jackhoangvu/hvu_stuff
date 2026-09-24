#include<bits/stdc++.h>
using namespace std;
long long f(long long x,long long a,long long b,long long cm){
  return x/a+x/b-x/cm;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t; cin>>t;
  while(t--){
    long long a,b,n; cin>>a>>b>>n;
    long long cm=lcm(a,b);
    long long l=1,r=1e15,ans=1e15;
    while(l<=r){
      long long mid=l+(r-l)/2;
      if(f(mid,a,b,cm)>=n){
        ans=mid;
        r=mid-1;
      }
      else{
        l=mid+1;
      }
    }
    cout<<ans<<"\n";
  }
  return 0;
}
