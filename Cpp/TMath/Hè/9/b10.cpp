#include <bits/stdc++.h>

using namespace std;
bool pr(long long n){
  if(n<2) return false;
  for(int i=2; i*i<=n; i++){
    if(n%i==0) return false;
  }
  return true;
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long k; cin>>k;
  for(int i=2; i<=k; i++){
    long long n=i;
    bool ok=true;
    while(n>0){
      if(!pr(n)){ok=false; break;}
      n/=10;
    }
    if(ok) cout<<i<<" ";
  }
  return 0;
}
