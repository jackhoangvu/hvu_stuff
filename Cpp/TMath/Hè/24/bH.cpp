#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  vector<string> s(n);
  for (int i=0; i<n; i++){
    cin>>s[i];
  }
  for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){

      if(s[i][j]!='.') s[i][j]=',';
    }
// this problem is like you have a grid of n*n with dots and uppercase letters and you must count all of the uppercase letters (in the problem it's also 'characters that are different than the dot/. character') that form DIAGONALS of 3(just diagonals, no vertical/horizontal/dont count the ones with 4 or 5 consecutive, if one diagonal contains 5 consecutive then you count the diagonals of 3 form that form a diagonal, like XYZT -> XYZ counts, XYT counts(like T and XY is separated by Z but those counts because still diagonal), YZT counts, XZT counts, yeah the problem is that
  }
  return 0;
}
