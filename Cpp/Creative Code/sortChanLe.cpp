#include <bits/stdc++.h>
using namespace std;
int n;
using ll = long long;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  vector<ll> l, c;
  vector<ll> a(n), odd, even;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    if (a[i] % 2 == 0) even.push_back(a[i]);
    else odd.push_back(a[i]);
  }
  sort(odd.begin(),odd.end());
  sort(even.begin(),even.end(),greater<ll>());
  int iOdd = 0, iEven = 0;
  for (int i = 0; i < n; i++)
  {
    if (a[i] % 2) a[i] = odd[iOdd++];
    else a[i] = even[iEven++];
  }
  for (int i = 0; i < n; i++) cout << a[i] << ' ';
  return 0;
}
