#include <bits/stdc++.h>

using namespace std;
int T;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  while (T--)
  {
    int n;
    cin >> n;
    long long sum = 0;
    long long tmp = n;
    for (long long i = 2; i * i <= tmp; i++) {
      if (tmp % i == 0) {
        sum += i*i;
        while (tmp % i == 0) {
          tmp /= i;
        }
      }
    }
    if (tmp > 1) {
      sum += tmp*tmp;
    }
    cout << sum << "\n";
  }
  return 0;
}
