#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n,x; cin>>n>>x;
  int l=1,r=n;
  long long cnt=0;
  while(l<=r){
    cnt++;
    int mid=l+(r-l)/2;
    if(mid==x){
      cout<<cnt;
      return 0;
    }
    else if(mid>x) r=mid-1;
    else l=mid+1;
  }
  cout<<cnt;
  return 0;
}
