#include <bits/stdc++.h>

using namespace std;
int n,k;
int x[12];
vector<int> vt;
void Try(int i){
  for (int j=0; j<k; j++){
    if(vt[j]!=x[i-1]){
      x[i]=vt[j];
      if(i==n){
        for (int i=1; i<=n; i++){
          cout<<x[i];
        }
        cout<<"\n";
      }
      else Try(i+1);
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>k;
  for (int j=0; j<k; j++){
    int a;
    cin>>a;
    vt.push_back(a);
  }
  sort(vt.begin(),vt.end());
  Try(1);
  return 0;
}
