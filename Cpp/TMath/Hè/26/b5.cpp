#include <bits/stdc++.h>

using namespace std;
const int mod=1e9+7;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t; cin>>t;
  while(t--){
    long long cnt=0;
    long long n,x; cin>>n>>x;
    for(long long a=1; a<=n&&a+2<=x; a++){
      for(long long b=1; b<=n/a&&a+b+1<=x; b++){
        long long mxp=(n-a*b)/(a+b);
        long long mxs=x-a-b;
        cnt+=max(0LL,min(mxp,mxs));
      }
    }
    cout<<cnt<<"\n";
  }
  return 0;
}
