#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a,b;
  cin>>a>>b;
  int mi=min(a,b);
  int ans=mi;
  for (int i=mi-1; i>=1; i--){
    ans*=i;
  }
  cout<<ans;
  return 0;
}
