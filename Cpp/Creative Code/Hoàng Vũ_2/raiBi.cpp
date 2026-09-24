#include <bits/stdc++.h>

using namespace std;
int T, n;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  while (T--) {
    cin >> n;
    int cnt = 0;
    while (n>1){
      n = (n + 1)/2;
      cnt++;
    }
    cout << cnt << "\n";
}
  return 0;
}
