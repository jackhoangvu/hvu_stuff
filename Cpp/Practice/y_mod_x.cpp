#include <bits/stdc++.h>

using namespace std;
long long rev(long long n){
  long long ans=0;
  while(n>0){
    ans=ans*10+(n%10);
    n/=10;
  }
  return ans;
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n; cin>>n;
  if(n<=10){
    for(int i=1; i<=n; i++){
      if(i==10) cout<<"";
      else cout<<i<<" ";
    }
  }
  else{
    for(int i=1; i<=9; i++){
      cout<<i<<" ";
    }
    for (int i=11; i<=n; i++){
      if(rev(i)%i==0) cout<<i<<" ";
    }
  }
  return 0;
}
