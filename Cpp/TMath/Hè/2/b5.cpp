#include <bits/stdc++.h>

using namespace std;
long long pr(long long n){
  if(n<=1) return false;
  long long sum=0;
  long long mx=sqrt(n);
  for(int i=1; i<=mx; i++){
    if(n%i==0){
      sum+=i;
      if(i*i!=n) sum+=(n/i);
    }
  }
  return sum;
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n; cin>>n;
  cout<<pr(n)<<"\n";
  return 0;
}
