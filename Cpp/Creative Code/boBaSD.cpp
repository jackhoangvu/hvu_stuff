#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin>>n;
  long long c= 0;
  for(int i=0; i<n; ++i) {
    int x;
    cin>>x;
    if(x%5 != 0) c++;
  }
  long long mt = (long long)n*(n-1)*(n-2)/6;
  long long ms = c*(c-1)*(c-2)/6;
  cout<<mt-ms<<"\n";
}
