#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long k; cin>>k;
  long long l=1,r=1e8;
  long long ans=-1;
  while(l<=r){
    long long mid=l+(r-l)/2;
    long long val=mid*mid;
    if(val>=k){
      ans=mid;
      r=mid-1;
    }
    else l=mid+1;
  }
  cout<<2*ans;
  return 0;
}
