#include <bits/stdc++.h>

using namespace std;
const long long mxn=1e6+5;
const long long mod=1e9+7;
long long d[mxn],p[mxn],q[mxn];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t; cin>>t;
  for(long long i=1; i<=mxn; i++){
    for (long long j=i; j<mxn; j+=i){
      d[j]++;
    }
  }
  for (int i=1; i<mxn; i++){
    p[i]=(p[i-1]+d[i])%mod;
    q[i]=(q[i-1]+i*d[i])%mod;
  }
  while(t--){
    long long n; cin>>n;
    // d[i]*(n-i),1<=i<n
    long long ans=(n*p[n-1]-q[n-1])%mod;
    if(ans<0) ans+=mod;
    cout<<ans<<"\n";
  }
  return 0;
}
