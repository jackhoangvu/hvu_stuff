#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,k, ans=0, sum=0;
  // 3 222
  cin>>n>>k;
  sum=k;
  for(int i=5; i<=n*5; i+=5){
    if(i+sum>240) break;
    else {ans++; sum+=i;}
  }
  cout<<ans;
  return 0;
}
