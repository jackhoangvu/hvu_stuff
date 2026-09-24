#include <bits/stdc++.h>
using namespace std;
long long tongUoc[100005];
int a;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> a;
  for (int i = 1; i <= a; i++) {
      for (int j = i; j <= a; j += i) {
          tongUoc[j] += i;
      }
    }

    bool t= false;
    for (int n = 2; n <= a; ++n) {
        if (tongUoc[n] == 2LL * n) {
          cout<<n<<"\n";
          t = true;
        }
    }

    if (!t) {
      cout<<"No perfect"<<"\n";
    }
  return 0;
}
