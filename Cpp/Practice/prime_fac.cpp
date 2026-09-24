#include <bits/stdc++.h>

using namespace std;
map<int,int> ca;
void pt(long long x,map<int,int>& c){
  for(int i=2; i*i<=x; i++){
    while(x%i==0){c[i]++; x/=i;}
  }
  if(x>1) c[x]++;
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n; cin>>n;
  pt(n,ca);
  for(auto [b,e]:ca){
    cout<<b<<" "<<e<<"\n";
  }
  return 0;
}
