#include <bits/stdc++.h>

using namespace std;
bool pr(long long n){
  if(n<=1) return false;
  long long sum=1;
  long long mx=sqrt(n);
  for(int i=2; i<=mx; i++){
    if(n%i==0){
      sum+=i;
      if(i*i!=n) sum+=(n/i);
    }
  }
  return n<sum;
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n;
  while(cin>>n){
    if(pr(n)) cout<<1<<"\n";
    else cout<<0<<"\n";
  }
  return 0;
}
