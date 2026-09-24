#include <bits/stdc++.h>

using namespace std;
const int mxn=1e6;
bool p[mxn];
void sang(int mx){
  p[0]=p[1]=false;
  for(int i=2; i*i<=mx; i++){
    for(int j=i*i; j<=mx; j+=i){
      p[j]=false;
    }
  }
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  return 0;
}
