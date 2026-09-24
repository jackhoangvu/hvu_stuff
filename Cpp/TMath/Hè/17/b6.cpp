#include <bits/stdc++.h>

using namespace std;
long long a,b,n;
const int mxn=1e6+5;
const int mod=1e9+7;
long long fib[mxn];
void precompute(){
  fib[1]=1,fib[2]=1;
  for(int i=3; i<=mxn; i++) fib[i]=(fib[i-1]+fib[i-2])%mod;
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t; cin>>t;
  precompute();
  while(t--){
    long long n; cin>>n;
    cout<<fib[n]<<"\n";
  }

  return 0;
}
