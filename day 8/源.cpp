#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
//两种排序方式
bool lexicographically(vector<string>& arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i + 1 < n && arr[i].size() > arr[i + 1].size())
            return false;

    }
    return true;
}
bool lengths(vector<string>& arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i + 1 < n && arr[i] > arr[i + 1])
            return false;

    }
    return true;
}
int main()
{
    vector<string> arr;
    int n = 0;
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
    bool b1, b2;
    b1 = lexicographically(arr, n);
    b2 = lengths(arr, n);
    if (b1 && b2) cout << "both" << endl;
    else if (b1) cout << "lengths" << endl;
    else if (b2) cout << "lexicographically" << endl;
    else cout << "none" << endl;
    return 0;

}
// 64 位输出请用 printf("%lld")

// 最小公约数
#include <iostream>
using namespace std;
int main()
{
    int a = 0;
    int b = 0;
    cin >> a >> b;
    int x = max(a, b);
    while (1)
    {
        if (x % a == 0 && x % b == 0)
        {
            printf("%d", x);
            break;
        }
        x++;
    }
    return 0;
}

int main()
{
    int a = 0;
    int b = 0;
    int c = a + b;
    return 0;
}
// 64 位输出请用 printf("%lld")