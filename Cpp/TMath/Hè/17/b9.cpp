#include <bits/stdc++.h>

using namespace std;
const int mod=2022;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n; cin>>n;
  __uint128_t a=static_cast<__uint128_t>(n)*(n+1)*(2*n+1);
  __uint128_t ans=a/6;
  cout<<static_cast<long long>(ans%mod)<<"\n";
  return 0;
}
