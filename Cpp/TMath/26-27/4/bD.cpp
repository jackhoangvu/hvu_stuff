#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n; cin>>n;
  long long a=1,b=1;
  for(long long i=2; i<=n; i++){
    long long c=(a+b)%mod;
    a=b;
    b=c;
  }
  cout<<b%mod;
  return 0;
}
