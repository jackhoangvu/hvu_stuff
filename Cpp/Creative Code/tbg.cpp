#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  long long x,y, z;
  cin>>x>>y>>z;
  cout<<(z*(x-y) + y -1)/y<<"\n";
}
