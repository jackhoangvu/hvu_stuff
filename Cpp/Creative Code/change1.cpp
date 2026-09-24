#include <bits/stdc++.h>

using namespace std;
int n;
int a = 0, b = 0;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i < n + 1; i++) {
    if (i % 2 == 0) {
      a += 2;
      b -= 2;
    }
    if (i % 2 == 1) {
      a += i;
      b += i;
    }
  }

  cout << a << "\n" << b << "\n";

  return 0;
}
