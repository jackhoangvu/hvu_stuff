#include <bits/stdc++.h>

using namespace std;
bool pr(int n){
  if(n<2) return false;
  for(int i=2; i*i<=n; i++){
    if(n%i==0) return false;
  }
  return true;
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  for(int a=2; a<=n/2; a++){
    if(pr(a)&&pr(n-a)){cout<<a<<" "<<n-a<<"\n"; return 0;}
  }
  return 0;
}
