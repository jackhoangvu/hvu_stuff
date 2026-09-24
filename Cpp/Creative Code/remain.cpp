#include <bits/stdc++.h>
using namespace std;
int n;
long long a[105];
long long gcd2(long long x, long long y) {
    if (x < 0) x=-x;
    if (y < 0) y=-y;
    while (y) { x%=y;swap(x,y);}
    return x;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for (int i= 0; i < n; i++) cin>>a[i];
    if(n == 1){ cout << a[0]; return 0; }
    long long d=0;
    for (int i = 1; i< n;i++) d = gcd2(d,a[i]-a[0]);
    if (d < 0) d= -d;
    cout<<d;
    return 0;
}
