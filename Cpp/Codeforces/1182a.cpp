#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n; cin>>n;
  if(n%2==1) {cout<<"0"<<"\n"; return 0;}
  else cout<<(1LL<<(n/2))<<"\n";
  return 0;
}
