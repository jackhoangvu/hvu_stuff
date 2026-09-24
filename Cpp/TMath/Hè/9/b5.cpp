#include <bits/stdc++.h>

using namespace std;
long long pt(long long n){
  long long cnt=0;
  long long mx=sqrt(n);
  for(long long i=1; i<=mx; i++){
    if(n%i==0){
      if(i*i==n) cnt++;
      else cnt+=2;
    }
  }
  return cnt;
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n; cin>>n;
  cout<<pt(n);
  return 0;
}
