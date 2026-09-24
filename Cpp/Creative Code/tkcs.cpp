#include <bits/stdc++.h>

using namespace std;
int n, a[100001];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  vector<int> freq(10, 0);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] >= 0 && a[i] <= 9) {
      freq[a[i]]++;
    }
  }
  for (int i = 0; i < 10; i++) {
    cout << freq[i] << "\n";
  }
  return 0;
}
