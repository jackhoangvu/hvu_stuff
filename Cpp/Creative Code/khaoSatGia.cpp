#include <bits/stdc++.h>

using namespace std;
int n;
string a[100];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    int min = 9;
    cin >> a[i];
    string cacSo = a[i].substr(1);
    for (char c : cacSo)
    {
      int cur = c - '0';
      if (cur < min)
      {
        min = cur;
      }
    }
    sum += min;
    cout << a[i][0] << min << "\n";
  }
  cout << sum;
  return 0;
}
