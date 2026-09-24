#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  int mx=-10005,cur=0;
  while(n--){
    int a,b;//exit, enter
    cin>>a>>b;
    cur-=a;
    cur+=b;
    mx=max(mx,cur);
  }
  cout<<mx<<"\n";
  return 0;
}
