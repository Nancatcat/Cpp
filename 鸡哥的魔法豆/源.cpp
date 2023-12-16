#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int arr[3];
int main()
{
    int n, x, ans;
    cin >> n;
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        arr[x]++;
    }
    cout << min(arr[0] * 2 + arr[1], min(arr[0] + arr[2] * 2, arr[1] * 2 + arr[2]));
    return 0;
}