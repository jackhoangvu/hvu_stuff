#include <bits/stdc++.h>

using namespace std;
int a,b, ans = 0;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> a >> b;
  if ((a+b)%3==0) ans++;
  if ((a-b)%3==0) ans++;
  if ((a*b)%3==0) ans++;
  if ((a/b)%3==0) ans++;
  cout << ans;
  return 0;
}
