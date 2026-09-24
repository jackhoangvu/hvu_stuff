#include <bits/stdc++.h>

using namespace std;
const long long mxn=1e6+5;
const long long mod=1e9+7;
long long d[mxn];
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
  while(t--){
    long long n; cin>>n;
    // d[i]*(n-i),1<=i<n
    long long ans=0;
    for (long long i=1; i<n; i++){
      ans=ans+(d[i]*(n-i))%mod;
    }
    cout<<ans%mod<<"\n";
  }
  return 0;
}
