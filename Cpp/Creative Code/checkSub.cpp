#include <bits/stdc++.h>

using namespace std;
string S;
int n;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> S >> n;
  vector<int> pos[26];
  for (int i = 0; i < (int)S.size(); i++)
    pos[S[i] - 'a'].push_back(i);

  while (n--)
  {
    string X;
    cin >> X;
    int cuoi = -1;
    bool ok = true;
    for (char c : X)
    {
      auto &v = pos[c - 'a'];
      auto it = upper_bound(v.begin(), v.end(), cuoi);
      if (it == v.end())
      {
        ok = false;
        break;
      }
      cuoi = *it;
    }
    cout << ok << '\n';
  }
  return 0;
}
