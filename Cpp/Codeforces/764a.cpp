#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,m,z;
  cin>>n>>m>>z;
  int mn=lcm(m,n);
  int cnt=0;
  for(int i=mn; i<=z; i+=mn){
    cnt++;
  }
  cout<<cnt;
  return 0;
}
