#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int k; cin>>k;
  long long ans=3;
  for (int i=0; i<k-1; i++){
    ans*=2;
  }
  cout<<ans;
  return 0;
}
