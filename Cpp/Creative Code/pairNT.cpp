#include<bits/stdc++.h>
using namespace std;
int n,k;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>k;
  vector<bool>prime(n+1,true);
  prime[0]=prime[1]=false;
  for(int p=2; p*p<=n; p++){
    if(prime[p]){
      for(int i=p*p; i<=n; i+=p){
        prime[i]=false;
      }
    }
  }
  int ans=0;
  for(int x=2; x<=n-k; ++x){
    if(prime[x]){
      if(prime[x+k]) ans++;
    }
  }
  cout<<ans<<"\n";
  return 0;
}
