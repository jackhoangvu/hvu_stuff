#include <bits/stdc++.h>

using namespace std;
long long F(long long x,long long a,long long b){
  return x-x/a-x/b+x/(a/__gcd(a,b)*b);
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long a,b,n;
  cin>>a>>b>>n;
  long long l=1,r=5*n;
  while(l<r){
    long long m=l+(r-l)/2;
    if(F(m,a,b)>=n)
      r=m;
    else
      l=m+1;
  }
  cout<<l;
}
