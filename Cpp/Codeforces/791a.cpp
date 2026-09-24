#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a,b; cin>>a>>b;
  int cnt=0;
  while(a<=b){
    a*=3; b*=2;
    cnt++;
  }
  cout<<cnt<<"\n";
  return 0;
}
