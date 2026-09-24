#include <bits/stdc++.h>

using namespace std;
long long n;
bool check(long long x){
  long long s1=((x+1)/2)*((x+1)/2);
  long long s2=(n/2)*(n/2+1)-(x/2)*(x/2+1);
  return s1>s2;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  long long l=0,r=n;
  long long ans=0;
  while(l<=r){
    long long mid=(l+r)/2;
    if(check(mid)){
      ans=mid;
      r=mid-1;
    }
    else l=mid+1;
  }
  cout<<ans;
  return 0;
}
