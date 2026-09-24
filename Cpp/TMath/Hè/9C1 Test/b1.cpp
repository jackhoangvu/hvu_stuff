#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  freopen("CAU1.INP", "r", stdin);
  freopen("CAU1.OUT", "w", stdout);
  long long k; cin>>k;
  long long l=1,r=1e18;
  while(l<r){
    long long mid=l+(r-l)/2;
    long long cnt=mid/8+mid/10-mid/40;
    if(cnt<k){
      l=mid+1;
    }
    else{
      r=mid;
    }
  }
  cout<<l<<"\n";
  return 0;
}
