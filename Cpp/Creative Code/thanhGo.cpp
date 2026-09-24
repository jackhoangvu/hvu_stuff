#include <bits/stdc++.h>
using namespace std;
long long a,b;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> a >> b;
  long long ans1=__gcd(a,b), ans2=(a+b)/ans1;
  cout << ans1 << "\n" << ans2;
  return 0;
}
