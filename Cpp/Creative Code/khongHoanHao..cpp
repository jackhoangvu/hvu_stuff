#include <bits/stdc++.h>

using namespace std;
int a, b;
vector<int> d;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> a >> b;
  vector<int> s(b + 1, 0);
  for (int i = 1; i * 2 <= b; i++)
  {
    for (int j = i * 2; j <= b; j += i)
      s[j] += i;
  }
  int ans = 0;
  for (int n = a; n <= b; n++)
    if (s[n] > n)
      ans++;
  cout << ans;
  return 0;
}
