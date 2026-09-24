#include<bits/stdc++.h>
using namespace std;
long long sum1(long long k){
  return k*(k+1)/2;
}
long long sum2(long long k,long long n){
  long long a=k+1;
  long long c=n;
  if((c%2)!=(a%2)) c--;
  if(c<a||a>n) return 0;
  return (a+c)*((c-a)/2+1)/2;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n; cin>>n;
  long long l=1,r=n,ans=1;
  while(l<=r){
    long long mid=l+(r-l)/2;
    long long s=sum1(mid);
    long long e=sum2(mid,n);
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
