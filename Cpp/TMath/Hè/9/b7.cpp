#include <bits/stdc++.h>

using namespace std;
void pt(long long n){
  long long sum=0;
  long long mx=sqrt(n);
  for(long long i=2; i<mx; i++){
    if(n%i==0){
      if(i*i==n) sum+=0;
      else{sum+=(n/i); sum+=i;}
      cout<<(n/i)<<" "<<i<<"\n";
    }
  }
  cout<<sum<<"\n";
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n; cin>>n;
  pt(n);
  return 0;
}
