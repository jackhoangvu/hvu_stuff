#include <bits/stdc++.h>
using namespace std;
int n;
long long f[200005];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>> n;
  for (int i=1; i<=n; ++i){
    int p;
    cin>> p;
    long long s=0;
    int j= p-1;
    while (j> 0) {
      s+= f[j];
      j-= (j& -j);
    }
    cout<< s<< " ";
    j=p;
    while (j<= n) {
      f[j]+= p;
      j+=(j& -j);
    }
  }
  return 0;
}
