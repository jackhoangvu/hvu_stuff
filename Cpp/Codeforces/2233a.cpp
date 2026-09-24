#include <bits/stdc++.h>

using namespace std;
void solve(){
  int n,x,y,z;
  cin>>n>>x>>y>>z;
  int time=x+y;
  if(n<=x+y) time=1;
  else time=(n+x+y-1)/(x+y);
  int rem=n-(x*z);
  int perh=x+10*y;
  int hrem=0;
  if(rem<=0){
    hrem=0;
    z=(n+x-1)/x;
  }
  else{
    hrem=(rem+perh-1)/perh;
  }
  int ai_time=hrem+z;
  if(ai_time<time) cout<<ai_time<<"\n";
  else cout<<time<<"\n";
  // 6 2 1 3
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t; cin>>t;
  while(t--){
    solve();
  }
  return 0;
}
