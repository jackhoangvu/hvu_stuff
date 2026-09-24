#include <bits/stdc++.h>
using namespace std;
int T;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> T;
  while(T--){
    string s;
    cin >> s;
    int n = s.size();
    bool ok = false;
    for(int i = 0; i < n && !ok; i++){
      for(int j = i; j < n && !ok; j++){
        string t = s;
        reverse(t.begin()+i, t.begin()+j+1);
        bool p = true;
        for(int k = 0; k < n/2; k++)
          if(t[k]!=t[n-1-k]){ p = false; break; }
        if(p) ok = true;
      }
    }
    cout << (ok ? "YES" : "NO") << "\n";
  }
  return 0;
}
