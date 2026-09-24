#include <bits/stdc++.h>

using namespace std;
int k;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);


  cin >> k;
  int a = 0;
  int b = 1;

  while (true)
  {
    if (b % 3 == 0 || b % 5 == 0 || b % 7 == 0)
    {
      a++;
    }
    if (a == k)
    {
      cout << b;
      return 0;
    }

    b++;
  }

  return 0;
}
