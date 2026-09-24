#include <bits/stdc++.h>
using namespace std;
long long m,n;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>m>>n;
  if(n%m!=0){cout<<-1; return 0; }
  long long k=n/m;
  long long ans=LLONG_MAX;
  for(long long i=1; i*i<=k; i++){
    if(k%i==0){
      long long j=k/i;
      if(__gcd(i,j)==1) ans=min(ans,i+j);
    }
  }
  if(ans==LLONG_MAX) cout<<-1;
  else cout<<ans*m;
  return 0;
}
