#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int m[5][5];
  int val=0;
  for (int i=0; i<5; i++){
    for (int j=0; j<5; j++){
      cin>>m[i][j];
      if(m[i][j]==1) {cout<<abs(i-2)+abs(j-2); break;}
    }
  }
  return 0;
}
