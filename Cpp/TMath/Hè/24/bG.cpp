#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int p,q; cin>>p>>q;
  int cnt=0;
  for (int i=0; i<q; i++){
    for(int j=0; j<q; j++){
      int c=p-i-j;
      if(i*j==0) cnt+=p-i-j+1;
      else cnt+=min(c,(q/(i*j)))+1;
    }
  }
  cout<<cnt;
  return 0;
}
