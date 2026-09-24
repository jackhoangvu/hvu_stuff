#include <bits/stdc++.h>
using namespace std;
string s;
long long d[26][100005];
int q;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin>> s;
  int n = s.size();
  for (int i = 0;i < n;i++){
    for (int j = 0;j < 26;j++){
      d[j][i+1] = d[j][i];
    }
    d[s[i]-'a'][i+1]++;
  }
  cin>>q;
  while (q--){
    int l, r;
    cin >> l>>r;
    long long ans = 0;
    for(int i = 0;i < 26;i++){
      long long cnt=d[i][r+1] -d[i][l];
      ans+=cnt * (cnt-1) / 2;
    }
    cout << ans << "\n";
  }
  return 0;
}
