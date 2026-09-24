#include<bits/stdc++.h>
using namespace std;
const long long mx=1e18+5;
long long C(long long n,long long r) {
  if(r<0||r>n) return 0;
  if(r>n-r) r=n-r;
  long long ans=1;
  for(long long i=1; i<=r; i++){
    ans=ans*(n-r+i)/i;
    if(ans>mx) ans=mx;
  }
  return (long long)ans;
}
int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  long long k;
  cin>>k;
  for(long long L=1;; L++){
    long long cnt=C(L+8,L-1)-1;
    if(cnt>=k){
      long long sum=10;
      string s;
      for(long long i=0; i<L; i++){
        long long lo=i? 0:1,hi=9;
        for(long long d=lo; d<=hi; d++){
          long long clai=L-i-1;
          long long t=sum-d;
          long long cach=clai? C(clai+t-1,clai-1):(t==0);
          if(cach>=k){
            s.push_back(char('0'+d));
            sum=t;
            break;
          }
          k-=cach;
        }
      }
      cout<<s<<"\n";
      return 0;
    }
    k-=cnt;
  }
}
