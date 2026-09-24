#include <bits/stdc++.h>
using namespace std;
long long h[100005];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n,m; cin>>n>>m;
  unsigned __int128 mod=(unsigned __int128)m*6;
  unsigned __int128 s1=0;
  unsigned __int128 s2=0;
  unsigned __int128 s3=0;
  for (int i=0; i<n; i++){
    cin>>h[i];
    unsigned __int128 x=h[i]%mod;
    s1=(s1+x)%mod;
    unsigned __int128 y=(x*x)%mod;
    s2=(s2+y)%mod;
    unsigned __int128 z=(y*x)%mod;
    s3=(s3+z)%mod;
  }
  unsigned __int128 a1=s1*s1%mod*s1%mod;
  unsigned __int128 a2=3*s1%mod*s2%mod;
  unsigned __int128 a3=2*s3%mod;
  unsigned __int128 t=(a1-a2+mod)%mod;
  t=(t+a3)%mod;
  long long ans=(long long)((t/6)%m);
  cout<<ans;
  return 0;
}
