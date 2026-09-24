#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long a,b; cin>>a>>b;
  if(b%2==1) b--;
  if(a%2==1) a++;
  cout<<(a+b)*((b-a)/2+1)/2<<"\n";
  return 0;
}
