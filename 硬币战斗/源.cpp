#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int main()
{
    int n, a, b;
    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        cin >> a >> b;
        a += a;
        b += b;
    }
    if ((a + 2 * b) & 1)
    {
        cout << "N";
    }
    else
    {
        cout << "Y";
    }
    return 0;
}
