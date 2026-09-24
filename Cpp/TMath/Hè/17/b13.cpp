#include <bits/stdc++.h>

using namespace std;
long long mo(string s,long long m){
  long long r=0;
  for(char d:s){
    r=(r*10+(d-'0'))%m;
  }
  return r;
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t; cin>>t;
  while(t--){
    string s; cin>>s;
    long long k; cin>>k;
    cout<<((mo(s,k)*(mo(s,k))%k==0)?"YES":"NO")<<"\n";
  }
  return 0;
}
