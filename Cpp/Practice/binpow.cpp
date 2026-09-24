#include <bits/stdc++.h>

using namespace std;
const int mod=1e9+7;
long long bp(long long b,long long e,long long m=mod){
  b%=m;
  long long ans=1;
  while(e>0){
    if(e&1) ans=ans*b%m;
    b=b*b%m;
    e>>=1;
  }
  return ans;
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int b,e; cin>>b>>e;
  cout<<bp(b,e)<<"\n";
  return 0;
}
