#include <bits/stdc++.h>

using namespace std;
void pt(long long n){
  long long cnt=0;
  long long mx=sqrt(n);
  long long c=0,l=0;
  for(long long i=1; i<=mx; i++){
    if(n%i==0){
      if(i*i==n){
        if(i%2==0) c++;
        else l++;
      }
      else{
        if(i%2==0) c++;
        else l++;
        if((n/i)%2==0) c++;
        else l++;
      }
    }
  }
  cout<<c<<"\n"<<l<<"\n";
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n; cin>>n;
  pt(n);
  return 0;
}
