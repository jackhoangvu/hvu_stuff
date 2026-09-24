#include <bits/stdc++.h>
using namespace std;
long long x, n, tong =0;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> x>>n;
  long long mu=x;
  for(int i = 1;i <=n; i++){
    tong=(tong+mu) % 123456789;
    mu=(mu*x) % 123456789;
  }
  cout<< tong;
  return 0;
}
