#include <bits/stdc++.h>

using namespace std;
void solve(){
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  if(d<b||c<a) {cout<<"NO"<<"\n"; return;}
  //check [a,b] then [c,d]
  if(b>2*a+2) {cout<<"NO"<<"\n"; return;}
  if(a>2*b+2) {cout<<"NO"<<"\n"; return;}
  if((d-b)>2*(c-a)+2) {cout<<"NO"<<"\n"; return;}
  if((c-a)>2*(d-b)+2) {cout<<"NO"<<"\n"; return;}
  cout<<"YES"<<"\n";
  // 8 11 17 36
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
