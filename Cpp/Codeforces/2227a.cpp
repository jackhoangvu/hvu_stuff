#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t; cin>>t;
  while(t--){
    int cnt=0;
    int x,y; cin>>x>>y;
    if(x%2==1) cnt++;
    if(y%2==1) cnt++;
    if(cnt==2) cout<<"NO"<<"\n";
    else cout<<"YES"<<"\n";
  }
  return 0;
}
