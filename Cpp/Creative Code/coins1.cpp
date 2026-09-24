#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, k;
pair<int, int> a[100005];

bool comp(pair<int, int> x, pair<int, int> y)
{
    if (x.first > y.first)
    {
        return true;
    }
    if (x.first == y.first)
    {
        return x.second < y.second;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a, a + n, comp);
    vector<int> v;
    v.reserve(k);
    for (int i = 0; i < k; i++)
    {
        v.push_back(a[i].second);
    }
    sort(v.begin(), v.end());
    for (int x : v)
    {
        cout << x << " ";
    }

    return 0;
}
