#include <bits/stdc++.h>

using namespace std;

struct SA
{
    long long int MAXN = 1 << 21;
    string s;
    long long int sz, gap;
    vector<long long int> sa, pos, tmp, lcp;

    SA(string t)
    {
        s = t;
        sz = s.size();
        sa.resize(sz);
        pos.resize(sz);
        tmp.resize(sz);
        lcp.resize(sz);
    }

    bool sufCmp(long long int i, long long int j)
    {
        if (pos[i] != pos[j])
            return pos[i] < pos[j];
        i += gap;
        j += gap;
        return (i < sz && j < sz) ? pos[i] < pos[j] : i > j;
        // return i > j;
    }

    void buildSA()
    {
        for (long long int i = 0; i < sz; i++)
        {
            sa[i] = i;
            pos[i] = s[i];
        }
        for (gap = 1;; gap *= 2)
        {
            sort(sa.begin(), sa.begin() + sz, [=](long long int i, long long int j) -> bool {
                if (pos[i] != pos[j])
                    return pos[i] < pos[j];
                i += gap;
                j += gap;
                return (i < sz && j < sz) ? pos[i] < pos[j] : i > j;
            });
            for (long long int i = 0; i < sz - 1; i++)
                tmp[i + 1] = tmp[i] + sufCmp(sa[i], sa[i + 1]);
            for (long long int i = 0; i < sz; i++)
                pos[sa[i]] = tmp[i];
            if (tmp[sz - 1] == sz - 1)
                break;
        }
    }

    void buildLCP()
    {
        buildSA();
        for (long long int i = 0, k = 0; i < sz; ++i)
            if (pos[i] != sz - 1)
            {
                for (long long int j = sa[pos[i] + 1]; s[i + k] == s[j + k];)
                    ++k;
                lcp[pos[i]] = k;
                if (k)
                    --k;
            }
    }
};  // end namespace SuffixArray
    //time complexity nlog^2n