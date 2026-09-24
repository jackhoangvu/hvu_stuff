#include <bits/stdc++.h>

using namespace std;
void solve(){
  long long k; cin>>k;
  k--;
  long long len=1, cnt=9,st=1;
  while(true){
    if(k<len*cnt) break;
    k-=(len*cnt);
    len++;
    cnt*=10;
    st*=10;
    if(st>=1000000000000000000LL) break;
  }
  long long at=st+(k/len);
  string num=to_string(at);
  long long digit=k%len;
  cout<<num[digit]<<"\n";
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int q; cin>>q;
  while(q--){
    solve();
  }
  return 0;
}
