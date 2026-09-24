#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,m,a,b;
  cin>>n>>m>>a>>b;
  cout<<min(n*a,min((n%m)*a+(n/m)*b,(n/m+1)*b));
  return 0;
}
