#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  int mx=-1e6, cur=0,cnt=0;
  for (int i=0; i<n; i++){
    int x; cin>>x;
    if(x) cnt++;
    int add=(x==0)?1:-1;
    cur=max(add,add+cur);
    mx=max(mx,cur);
  }
  cout<<mx+cnt<<"\n";
  return 0;
}
