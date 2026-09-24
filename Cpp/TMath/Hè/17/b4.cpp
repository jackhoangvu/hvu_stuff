#include <bits/stdc++.h>

using namespace std;
long long mul(long long a,long long b,long long c){
  long long ans=0;
  while(b>0){
    if(b&1) ans=(ans+a)%c;
    a=(a+a)%c;
    b>>=1;
  }
  return ans;
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long a,b,c; cin>>a>>b>>c;
  cout<<mul(a,b,c);
  return 0;
}
