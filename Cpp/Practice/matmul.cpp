#include <bits/stdc++.h>

using namespace std;
const int mod=1e9+7;
struct Matrix{
  int a[105][105];
  Matrix(){
    memset(a,0, sizeof(a));
  }
};
Matrix matmul(const Matrix &x, const Matrix &y){
  Matrix ans{};
  for(int i=0; i<105; i++){
    for(int j=0; j<105; j++){
      for(int k=0; k<105; k++){
        ans.a[i][j]=(ans.a[i][j]+x.a[i][k]*y.a[k][j])%mod;
      }
    }
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int m,n,p; cin>>m>>n>>p;
  Matrix m1;
  for (int i=0; i<m; i++){
    for (int j=0; j<n; j++){
      cin>>m1.a[i][j];
    }
  }
  Matrix m2;
  for (int i=0; i<n; i++){
    for (int j=0; j<p; j++){
      cin>>m2.a[i][j];
    }
  }
  Matrix ans=matmul(m1,m2);
  for (int i=0; i<m; i++){
    for (int j=0; j<p; j++){
      cout<<ans.a[i][j]<<" ";
    }
    cout<<"\n";
  }
  return 0;
}
