#include <bits/stdc++.h>

using namespace std;
long long c;
long long mo(string s,long long m=c){
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
  string a,b; cin>>a>>b;
  cin>>c;
  cout<<(mo(a)*mo(b))%c;
  return 0;
}
