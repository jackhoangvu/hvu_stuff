#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  vector<int> a(2*n+2);
  for (int i=0; i<2*n; i++){
    cin>>a[i];
  }
  int cnt=0;
  for (int i=0; i<2*n; i++){
    int idx=-1;
    for(int j=i+1; j<2*n; j++){
      if(a[i]==a[j]){idx=j; break;}
    }
    while(idx>i+1){
      swap(a[idx],a[idx-1]);
      cnt++;
      idx--;
    }
  }
  cout<<cnt<<"\n";
  return 0;
}
