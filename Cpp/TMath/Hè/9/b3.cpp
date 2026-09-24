#include <bits/stdc++.h>

using namespace std;
bool pr(long long n){
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
  int cnt=0;
  while(n--){
    string s; cin>>s;
    long long sum=0;
    for(char c:s){
      sum+=(c-'0');
    }
    if(pr(sum)) cnt++;
  }
  cout<<cnt<<"\n";
  return 0;
}
