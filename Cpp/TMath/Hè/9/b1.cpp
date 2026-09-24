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
  int a,b,c; cin>>a>>b>>c;
  int cnt=0;
  if(pr(a)) cnt++;
  if(pr(b)) cnt++;
  if(pr(c)) cnt++;
  cout<<cnt<<"\n";
  return 0;
}
