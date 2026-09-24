#include <bits/stdc++.h>

using namespace std;
long long n;
typedef long long ll;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  if (n < 2)
    return 0;

  vector<int> a(n);

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  ll min = 10000000;
  ll pd1 = (ll)a[0] * a[1];
  if (pd1 < min)
  {
    min = pd1;
  }
  ll pd2 = (ll)a[0] * a[n - 1];
  if (pd2 < min)
  {
    min = pd2;
  }
  ll pd3 = (ll)a[n - 1] * a[n - 2];
  if (pd3 < min)
  {
    min = pd3;
  }
  cout << min;
  return 0;
}
