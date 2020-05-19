#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    double n;
    cin >> n;
    double ans = 1;
    for (ll i = 2; i <= n; i++)
    {
        ans = ans + 1.0 / i;
    }
    printf("%0.9f\n", ans);
}