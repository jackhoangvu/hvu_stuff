#include <bits/stdc++.h>

using namespace std;
const int mod=1e9+7;
void solve(long long a,long long b,long long n){
  if(n==0){cout<<(a%mod+mod)%mod<<"\n"; return;}
  if(n==1){cout<<(b%mod+mod)%mod<<"\n"; return;}
  long long f0=a,f1=b,fn=0;
  for(int i=2; i<=n; i++){
    fn=(3*f1-f0)%mod;
    if(fn<0) fn+=mod;
    f0=f1;
    f1=fn;
  }
  cout<<fn%mod<<"\n";
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t; cin>>t;
  while(t--){
    long long a,b,n; cin>>a>>b>>n;
    solve(a,b,n);
  }

  return 0;
}
