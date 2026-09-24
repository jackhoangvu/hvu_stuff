#include <bits/stdc++.h>
using namespace std;
long long t[5000005], u[5000005];
int n,a[1000005];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>> n;
  for (int i=1; i<= 5000005; ++i){
    for (int j =i; j<=5000005; j+=i){
      u[j]+= i;
    }
  }
  for (int i=1; i<=5000005; ++i){
    t[i]= t[i-1] + u[i];
  }
  while (n--){
    int i, j;
    cin>> i>> j;
    cout << t[j] - t[i-1] << "\n";
  }
  return 0;
}
