#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  int ans=2;
  for (int i=1; i<n; i++){
    ans%=MOD;
    ans*=2;
    ans%=MOD;
  }
  cout<<ans;
  return 0;
}
