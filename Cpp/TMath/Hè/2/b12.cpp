#include <bits/stdc++.h>

using namespace std;
const int mxn=1e6+5;
const int mod=1e9+7;
long long d[mxn];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n; cin>>n;
  for (int i=1; i<mxn; i++){
    for (int j=i; j<mxn; j+=i){
      d[j]++;
    }
  }
  long long ans=0;
  for (int i=1; i<n; i++){
    ans=(ans+d[i])%mod;
  }
  cout<<ans<<"\n";
  return 0;
}
