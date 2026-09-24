#include <bits/stdc++.h>
using namespace std;
int n, p[10][8];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin>>n;
  for (int i = 0; i <= 9; i++){
    p[i][0]= 1;
    for (int j = 1; j <= 7; j++) p[i][j] = p[i][j-1] * i;
  }
  for (int i = 0; i <= n; i++){
    int t=i, k=0, s=0;
    if (!i){
      cout<<0<<'\n';
      continue;
    }
    for (int x = i; x; x /= 10) k++;
    for (; t; t /= 10) s += p[t % 10][k];
    if (s == i) cout<<i<<'\n';
  }
  return 0;
}
