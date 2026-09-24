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
    int N;
    long long X;
    cin >> N >> X;
    vector<pair<long long, int>> a;
    a.reserve(N);

    for (int i = 1; i <= N; i++)
    {
      long long A;
      cin >> A;
      long long r = (A + X - 1) / X;
      a.push_back({r, i});
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < N; i++)
    {
      cout << a[i].second << (i + 1 < N ? ' ' : '\n');
    }
  }

  return 0;
}
