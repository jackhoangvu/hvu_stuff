#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  int a[102];
  for (int i=0; i<n; i++){
    cin>>a[i];
    if(a[i]==1){cout<<"HARD"<<"\n"; return 0;}
  }
  cout<<"EASY"<<"\n";
  return 0;
}
