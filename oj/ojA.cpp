#define  _CRT_SECURE_NO_WARNINGS
#define  _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    if (abs(n - m) < 2)
        cout << "Brown";
    else
        cout << "Alice";
}
int main()
{
    solve();
    return 0;
}