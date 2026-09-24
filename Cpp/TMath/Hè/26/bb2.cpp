#include <bits/stdc++.h>

using namespace std;
const int mxn=1e6+5;
bool p[mxn];
long long cnt[mxn];
long long d[mxn];
void pr(long long n){
  for (int i=1; i<=mxn; i++){
    for (int j=i; j<mxn; j+=i){
      d[j]++;
    }
  }
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t; cin>>t;
  fill(p,p+mxn,true);
  p[0]=p[1]=false;
  long long mx=sqrt(mxn);
  pr(mxn);
  for(long long i=2; i<=mx; i++){
    if(p[i]){
      for(long long j=i*i; j<=mxn; j+=i){
        p[j]=false;
      }
    }
  }
  for (int i=1; i<=mxn; i++){
    cnt[i]=cnt[i-1]+p[d[i]];
  }
  while(t--){
    long long a,b; cin>>a>>b;
    cout<<cnt[b]-cnt[a-1]<<"\n";
  }

  return 0;
}
