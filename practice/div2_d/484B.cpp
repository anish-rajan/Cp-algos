#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define N 200005
int n;
vector<int> arr(N), arr1(1000006);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.begin() + n);
    int ind = 0;
    int maxans = 0;
    int maxvalue = arr[n - 1];
    for (int i = 1; i <= maxvalue + 1; i++)
    {
        int ind = lower_bound(arr.begin(), arr.begin() + n, i) - arr.begin();
        if (ind >= 1)
        {
            arr1[i] = arr[ind - 1];
        }
        else
        {
            arr1[i] = -1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (i >= 1)
        {
            if (arr[i] == arr[i - 1])
                continue;
        }
        int temp = arr[i];
        for (int j = 2 * temp; j <= maxvalue + 1; j += temp)
        {
            maxans = max(maxans, arr1[j] % temp);
        }
        maxans = max(maxans, maxvalue % temp);
    }
    cout << maxans << "\n";
}