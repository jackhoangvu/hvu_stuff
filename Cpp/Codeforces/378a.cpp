#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a,b,c1=0,c2=0,c3=0;
  cin>>a>>b;
  for (int i=1; i<=6; i++){
    if(abs(i-a)>abs(i-b)) c3++;
    else if(abs(i-a)==abs(i-b)) c2++;
    else c1++;
  }
  cout<<c1<<" "<<c2<<" "<<c3;
  return 0;
}
