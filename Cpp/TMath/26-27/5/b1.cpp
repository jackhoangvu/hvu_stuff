#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long a,b,c,d,e,f;
  cin>>a>>b>>c>>d>>e>>f;
  long long n; int k;
  cin>>n>>k;
  long long x=a%mod;
  long long y=b%mod;
  for(long long i=1; i<n; i++){
    long long nx=(c*x+d*y)%mod;
    long long ny=(e*x+f*y)%mod;
    x=nx;
    y=ny;
  }
  if(k==0) cout<<x;
  else cout<<y;
  return 0;
}
