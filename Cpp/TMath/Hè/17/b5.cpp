#include <bits/stdc++.h>

using namespace std;
long long a,b,n;
const int mxn=1e6+5;
const int mod=1e9+7;
long long fib[mxn];
void solve(long long a,long long b,long long n){
  if(n==0){cout<<a; return;}
  fib[0]=a,fib[1]=b,fib[2]=a+b;
  for(int i=2; i<=n; i++) fib[i]=(fib[i-1]+fib[i-2])%mod;
  cout<<fib[n]<<"\n";
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
