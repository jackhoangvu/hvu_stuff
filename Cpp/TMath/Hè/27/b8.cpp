#include<bits/stdc++.h>
using namespace std;
long long sum1(long long k){
  if(k%2==1) k--;
  return (k+1)*((k+1)/2)/2;
}
long long sum2(long long x,long long y){
  if(x%2==1) x++;
  if(y%2==1) y--;
  return (x+y)*((y-x)/2+1)/2;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n; cin>>n;
  long long l=1,r=1e9,ans=1;
  while(l<=r){
    long long mid=l+(r-l)/2;
    long long s=sum1(mid);
    long long e=sum2(mid+1,n);
    if(s>e){
      ans=mid;
      r=mid-1;
    }
    else{
      l=mid+1;
    }
  }
  cout<<ans<<"\n";
  return 0;
}
