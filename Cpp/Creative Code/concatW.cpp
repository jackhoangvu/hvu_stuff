#include <bits/stdc++.h>
using namespace std;
int T;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> T;
  while (T--) {
    int n, m, k;
    cin>>n>>m>>k;
    vector<int> a(n), b(m);
    for (int i = 0; i<n; i++) cin >>a[i];
    for (int i =0; i < m; i++) cin >> b[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int sm = 2e9+7;
    for (int i= 0; i < k;i++) {
        int sum = a[n-k+i] + b[m-1-i];
        if (sum<sm) sm=sum;
    }
    cout<<sm<<"\n";
  }
  return 0;
}
