#include "base.hpp"

//! Range Minimum Query用 SegmentTree
class SegmentTree
{
public:
    SegmentTree(int n)
    {
        ll cnt = 1;
        while (cnt < n)
            cnt <<= 1;
        node.resize(2 * cnt - 1);
        REP(i, 2 * cnt - 1)
        {
            node[i] = inf;
        }
        mN = cnt - 1;
    }
    ~SegmentTree()
    {
        node.resize(0);
    }

    //! 0-index get
    ll get(int left, int right, int l = 0, int r = -1, int index = 0)
    {
        if (r == -1)
            r = mN;

        if (r < left || right < l)
            return inf;
        if (left <= l && r <= right)
            return node[index];
        return std::min(get(left, right, l, (l + r) / 2, 2 * index + 1),
                        get(left, right, (l + r) / 2 + 1, r, 2 * index + 2));
    }

    //! 0-index set
    void set(int index, ll value)
    {
        node[mN + index] = value;
        //! update
        int par = (mN + index);
        while (par > 0)
        {
            par = (par - 1) / 2;
            node[par] = std::min(node[2 * par + 1], node[2 * par + 2]);
        }
    }

private:
    ll mN;
    vector<ll> node;
    const ll inf = (ll)1e15;
};