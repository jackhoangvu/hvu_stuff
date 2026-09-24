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
  int a,b; cin>>a>>b;
  for(int c=0;; c++){
    if(pr(a+b+c)){cout<<c; return 0;}
  }
  return 0;
}
