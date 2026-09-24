#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  int cnt=0;
  int b[]={100,20,10,5,1};
  for(int i:b){
    cnt+=n/i;
    n%=i;
  }
  cout<<cnt<<"\n";
  return 0;
}
