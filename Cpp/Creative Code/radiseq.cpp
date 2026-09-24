#include <bits/stdc++.h>
using namespace std;
int n, d, a[100005];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> d;
  for(int i = 0; i<n; ++i){
    cin >> a[i];
  }

  cout<<*max_element(a, a+n) - *min_element(a, a+n)<< "\n";
  if(*max_element(a, a+n) - *min_element(a, a+n) <=d) {cout<<0; return 0;}
  int t=0, l=0;
  sort(a,a+n);
  for(int r=0; r<n; ++r){
    while(a[r]-a[l]>d) l++;
    t = max(t, r-l+1);
  }
  cout<< n-t;
  return 0;
}
