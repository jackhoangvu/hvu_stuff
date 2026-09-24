#include <bits/stdc++.h>

using namespace std;
const long long MOD=1e9+7;
void solve(){
  long long a,b, ans=1;
  ans=ans%MOD;
  cin>>a>>b;
  while(b>0){
    if(b%2==1) ans=(ans*a)%MOD;
    a=(a*a)%MOD;
    b=b/2;
  }
  cout<<ans<<"\n";
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  while(n--){
    solve();
  }
  return 0;
}
