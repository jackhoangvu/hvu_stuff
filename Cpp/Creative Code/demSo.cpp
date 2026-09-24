#include <bits/stdc++.h>

using namespace std;
int n;
const int MAXN = 1000000;
bool tong[MAXN + 1];
bool tongChuSo[100]; // max = 54
int sumDigits(int x)
{
  int s = 0;
  while (x)
  {
    s += x % 10;
    x /= 10;
  }
  return s;
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  memset(tong, 0xff, sizeof(bool) * (n + 1));
  tong[0]= tong[1] = false;
  for (int i = 2; i * i <= n; i++)
  {
    if (tong[i])
    {
      for (int j = i * i; j <= n; j += i)
      {
        tong[j] = false;
      }
    }
  }
  int l = 60;
  memset(tongChuSo, true, l * sizeof(bool));
  tongChuSo[0] = tongChuSo[1] = false;
  for (int i = 2; i * i < l; i++)
  {
    if (tongChuSo[i])
    {
      for (int j = i * i; j < l; j += i)
      {
        tongChuSo[j] = false;
      }
    }
  }
  int ans = 0;
  for (int x = 2; x <= n; x++)
  {
    if (tong[x])
    {
      int s = sumDigits(x);
      if (tongChuSo[s]) ans++;
    }
  }
  cout << ans;
  return 0;
}
