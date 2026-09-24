#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t; cin>>t;
  while(t--){
    long long y,x; cin>>y>>x;
    long long l=max(y,x);
    long long ans=0;
    if(l%2==0){
      if(y==l){
        ans=(l*l)-x+1;
      }
      else if(x==l){
        ans=(l-1)*(l-1)+y;
      }
    }
    else{
      if(x==l){
        ans=(l*l)-y+1;
      }
      else if(y==l){
        ans=(l-1)*(l-1)+x;
      }
    }
    cout<<ans<<"\n";
  }
  return 0;
}
