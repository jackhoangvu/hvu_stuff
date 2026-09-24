#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, cnt=0; cin>>n;
  while(n>=5){
    cnt+=n/5; n/=5;
  }
  cout<<cnt;
  return 0;
}
