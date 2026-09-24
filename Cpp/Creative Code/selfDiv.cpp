#include <bits/stdc++.h>

using namespace std;
int l, r;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  // find numbers between l and r that is divisible by every single of each of the number (eg 128 is a "self div" because 128 is divisible by 1, 2 and 8)
  cin >> l >> r;
  int ans = 0;
  vector<long long> sd;
  for (int i = l; i <= r; i++)
  {
    int cur= i;
    bool ok = true;
    while (cur > 0)
    {
      int tmp = cur % 10;
      if (tmp == 0 || i % tmp != 0)
      {
        ok = false;
        break;
      }
      cur /= 10;
    }
    if (ok)
    {
      sd.push_back(i);
    }
  }
  cout << sd.size()<< "\n";
  for (int i = 0; i < sd.size(); i++)
  {
    cout << sd[i] <<" ";
  }
  return 0;
}
