#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k;
long long C(long long n){
  if(n<2) return 0;
  return n*(n-1)/2;
}
long long cnt(long long s){
  return C(s-1)-3*C(s-n-1)+3*C(s-2*n-1)-C(s-3*n-1); //s-3+2(k),k=2
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>k;
  ll s=3;
  for(; s<=3*n; s++){
    ll ways=cnt(s);
    if(k<=ways) break;
    k-=ways;
  }
  ll i=1;
  for(; i<=n; i++){
    ll rem=s-i;
    ll lo=max(1LL,rem-n), hi=min(n,rem-1);
    ll ways=max(0LL,hi-lo+1);
    if(k<=ways) break;
    k-=ways;
  }
  ll rem=s-i, j=max(1LL,rem-n)+k-1,kk=rem-j;
  cout<<i<<" "<<j<<" "<<kk<<"\n";
  return 0;
}
