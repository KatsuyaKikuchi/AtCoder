#include "base.hpp"

struct UnionFind
{
    void init(int n)
    {
        mN = n;
        mNodeTbl.resize(mN);
        mRankTbl.resize(mN);
        REP(i, mN)
        {
            mNodeTbl[i] = i;
            mRankTbl[i] = 0;
        }
    }
    int find(int x)
    {
        if (x == mNodeTbl[x])
            return x;
        return mNodeTbl[x] = find(mNodeTbl[x]);
    }
    bool same(int x, int y)
    {
        return find(x) == find(y);
    }
    void unit(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return;
        if (mRankTbl[x] < mRankTbl[y])
        {
            mNodeTbl[x] = y;
        }
        else
        {
            mNodeTbl[y] = x;
            if (mRankTbl[x] == mRankTbl[y])
                mRankTbl[x]++;
        }
    }

    int mN;
    vector<int> mNodeTbl;
    vector<int> mRankTbl;
};