#include <bits/stdc++.h>

using namespace std;
bool pr(long long n){
  if(n<=1) return false;
  for(long long i=2; i*i<=n; i++){
    if(n%i==0) return false;
  }
  return true;
}
// long long div(long long n,vector<long long> a){
//   if(n<=1) return 0;
//   long long cnt=0;
//   long long mx=sqrt(n);
//   for(int i=1; i<=mx; i++){
//     if(n%i==0){
//       if(pr(i)) a.push_back(i);
//       if(pr(n/i)) a.push_back(n/i);
//     }
//   }
//   return a.size();
// }
long long div2(long long n){
  if(n<=1) return false;
  long long cnt=0;
  long long mx=sqrt(n);
  for(int i=1; i<=mx; i++){
    if(n%i==0){
      cnt++;
      if(i*i!=n) cnt++;
    }
  }
  return cnt;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n; cin>>n;
  long long cnt=0;
  long long nn=n;
  long long s=sqrt(nn);
  for(long long i=2; i<=s; i++){
    if(nn%i==0){
      cnt++;
      while(nn%i==0) nn/=i;
    }
  }
  if(nn>1) cnt++;
  cout<<div2(n)-cnt;
  return 0;
}
