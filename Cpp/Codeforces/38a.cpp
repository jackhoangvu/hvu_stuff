#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,d[102],a,b;
  cin>>n;
  for(int i=1; i<n; ++i){
    cin>>d[i];
  }
  cin>>a>>b;
  int s=0;
  //d[0] + d[1] (2 nums) d[0](1 num) d[0]d[1]d[2] 3 nums d[2]d[3]d[4] 3 nums
  for(int i=a; i<b; ++i){
    s+=d[i];
  }
  cout<<s;
  return 0;
}
