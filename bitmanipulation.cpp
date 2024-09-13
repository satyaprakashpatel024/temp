#include <bits/stdc++.h>
using namespace std;

void fun(int &num, int k)
{
    cout << num << endl;
    num = (~(1 << k));
}
int main()
{
    cout << (2 & 1) || (5 + 1);
    return 0;
}
