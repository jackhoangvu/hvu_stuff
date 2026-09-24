#include <bits/stdc++.h>
using namespace std;
bool prime(long long n){
  if(n<2) return false;
  for(int i=2; i*i<=n; ++i){
    if(n%i ==0) return false;
  }
  return true;
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t; cin>>t;
  while(t--){
    int n,k;
    cin>>n>>k;
    if (n==1) {
      if (k==2) cout<<"YES"<<"\n";
      else cout<<"NO"<<"\n";
    }
    else{
      if(k>1) cout<<"NO"<<"\n";
      else if(k==1){
        if(prime(n)) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
      }
    }

  }
  return 0;
}
