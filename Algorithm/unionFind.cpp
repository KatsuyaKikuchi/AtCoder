#include "base.hpp"

struct UnionFind
{
    void init(int n)
    {
        mN = n;
        mNodeTbl.resize(mN);
        REP(i, mN)
        {
            mNodeTbl[i] = i;
        }
    }
    int find(int x)
    {
        if (x == mNodeTbl[x])
            return x;
        return mNodeTbl[x] = find(mNodeTbl[x]);
    }
    bool same(int x,int y)
    {
        return find(x)==find(y);
    }
    void unit(int x,int y)
    {
        x=find(x);
        y=find(y);
        mNodeTbl[x]=y;
    }

    int mN;
    vector<int> mNodeTbl;
};