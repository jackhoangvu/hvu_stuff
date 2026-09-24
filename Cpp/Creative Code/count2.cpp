#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int k; cin>>k;
  if(k==1){cout<<10<<"\n"; return 0;}
  long long ans=9;

  for (int i=0; i<k-1; i++){
    ans*=9;
  }
  cout<<ans;
  return 0;
}
