#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n,k; cin>>n>>k;
  long long ans=LLONG_MAX;
  long long mx=sqrt(n);
  long long m=1;
  for (int i=0; i<k-1; i++){
    m*=10;
  }
  for(long long i=1; i<=mx; i++){
    if(n%i==0){
      if(i>=m) ans=min(ans,i);
      if(n/i>=m) ans=min(ans,n/i);
    }
  }
  if(ans==LLONG_MAX) cout<<-1<<"\n";
  else cout<<ans<<"\n";
  return 0;
}
