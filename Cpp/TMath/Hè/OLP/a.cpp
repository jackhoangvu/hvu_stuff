#include <bits/stdc++.h>

using namespace std;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t; cin>>t;
  while(t--){
    long long a,b; cin>>a>>b;
    long long ans=(b+a+a)*(b+1)/2;
    cout<<ans<<"\n";
  }
  return 0;
}
