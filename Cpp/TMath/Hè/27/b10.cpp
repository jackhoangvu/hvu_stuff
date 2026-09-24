#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  string t; cin>>t;
  long long a,b,c; cin>>a>>b>>c;
  long long x,y,z; cin>>x>>y>>z;
  long long m; cin>>m;
  long long nb=0,ns=0,nc=0;
  for(char c:t){
    if(c=='B') nb++;
    else if(c=='S') ns++;
    else nc++;
  }
  long long l=0,r=2e12;
  long long ans=0;
  while(l<=r){
    long long abc=0;
    long long mid=l+(r-l)/2;
    if(mid*nb>a) abc+=(mid*nb-a)*x;
    if(mid*ns>b) abc+=(mid*ns-b)*y;
    if(mid*nc>c) abc+=(mid*nc-c)*z;
    if(abc<=m){
      ans=mid;
      l=mid+1;
    }
    else{
      r=mid-1;
    }
  }
  cout<<ans<<"\n";
  return 0;
}
