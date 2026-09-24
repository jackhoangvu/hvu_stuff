#include <bits/stdc++.h>

using namespace std;
int n, a[1000001];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
  }
  //count # odd and even sums
  long long odd = 0, even = 0;
  for (int i = 1; i <= n; i++)
  {
    if (a[i] % 2 == 0)
    {
      even++;
    }
    else
    {
      odd++;
    }
  }
  long long evenSum =
      even * (even - 1) / 2 +
      odd * (odd - 1) / 2;

  long long oddSum = even * odd;

  cout << evenSum << '\n';
  cout << oddSum << '\n';
  return 0;
}
