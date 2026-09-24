#include <bits/stdc++.h>

using namespace std;
void solve(){
  int n,a[200005]; cin>>n;
  for (int i=0; i<n; i++){
    cin>>a[i];
  }

  vector<int> arr;
  arr.push_back(a[0]);
  cout<<"1";
  bool wrapped=false;
  for (int i=1; i<n; i++){
    int last=arr.back();
    if(wrapped){
      if(a[i]>=last&&a[i]<=arr.front()){
        arr.push_back(a[i]);
        cout<<"1";
      }
      else{
        cout<<"0";
      }
    }
    else{
      if(a[i]>=last){
        arr.push_back(a[i]);
        last=a[i];
        cout<<"1";
      }
      else if(a[i]<last){
        if(a[i]<=arr.front()){
          arr.push_back(a[i]);
          last=a[i];
          wrapped=true;
          cout<<"1";
        }
        else{
          cout<<"0";
        }
      }
    }
  }
  cout<<"\n";
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t; cin>>t;
  while(t--){
    solve();
  }
  return 0;
}
