#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 100005
vector<long long int> arr(N);
vector<vector<long long int>> st(N, vector<long long int>(log2(N) + 3));

long long int merge(long long int val)
{
    return val;
}

long long int merge(long long int val1, long long int val2)
{
    return min(val1, val2);
}

void createTable()
{
    long long int K = log2(N);
    for (int i = 0; i < N; i++)
        st[i][0] = merge(arr[i]);

    for (int j = 1; j <= K; j++)
        for (int i = 0; i + (1 << j) <= N; i++)
            st[i][j] = merge(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}

//queries which take order 1 time
long long int rangequery(long long int L, long long int R)
{
    long long int j = log2(R - L + 1);
    long long int minimum = merge(st[L][j], st[R - (1 << j) + 1][j]);
    return minimum;
}

// for sumquery takes logn time
long long int sumquery(long long int L, long long int R)
{
    long long int K = log2(N);
    long long sum = 0;
    for (int j = K; j >= 0; j--)
    {
        if ((1 << j) <= R - L + 1)
        {
            sum += st[L][j];
            L += 1 << j;
        }
    }
    return sum;
}
