#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  vector<int> a(n);
  for (int i=1; i<=n; i++){
    cin>>a[i];
  }
  for(int i=n; i>=2; i--){
    for(int j=1; j<i; j++){
      if(a[j]>a[j+1]){
        swap(a[j],a[j+1]);
        for(int k=1; k<=n; k++){
          cout<<a[k]<<" ";
        }
        cout<<"\n";
      }
    }
  }
  return 0;
}
