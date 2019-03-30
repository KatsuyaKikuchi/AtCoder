#include "base.hpp"

class LazySegmentTree
{
  public:
    LazySegmentTree(ll n)
    {
        ll c = 1;
        while (c < n)
            c <<= 1;
        REP(i, 2 * c - 1)
        {
            node.push_back(0);
            lazy.push_back(0);
        }
        mN = c - 1;
    }

    //! 0-index 区間加算
    void add(ll value, int left, int right, int k = 0, int l = 0, int r = -1)
    {
        if (r < 0)
        {
            r = mN;
            value = value * (mN + 1);
        }
        LazyProgation(k);
        if (r < left || right < l)
            return;
        if (left <= l && r <= right)
        {
            //! 区間を完全被覆しているのでlazyに区間和を入れる
            lazy[k] += value;
            LazyProgation(k);
        }
        else
        {
            add(value / 2, left, right, 2 * k + 1, l, (l + r) / 2);
            add(value / 2, left, right, 2 * k + 2, (l + r) / 2 + 1, r);
            node[k] = node[2 * k + 1] + node[2 * k + 2];
        }
    }

    //! 0-index 区間和
    ll sum(ll left, ll right, int k = 0, int l = 0, int r = -1)
    {
        if (r < 0)
            r = mN;
        if (r < left || right < l)
            return 0;

        LazyProgation(k);
        if (left <= l && r <= right)
            return node[k];
        return sum(left, right, 2 * k + 1, l, (l + r) / 2) + sum(left, right, 2 * k + 2, (l + r) / 2 + 1, r);
    }

    void dev()
    {
        FOR(i, node.size(), 0)
        {
            cout << node[i] << ";" << lazy[i] << " ";
        }
        cout << endl;
    }

  private:
    //! index番目のnodeの遅延評価
    void LazyProgation(int index)
    {
        if (lazy[index] == 0)
            return;
        node[index] += lazy[index];
        if (2 * index + 1 < node.size())
        {
            lazy[2 * index + 1] += lazy[index] / 2;
            lazy[2 * index + 2] += lazy[index] / 2;
        }
        lazy[index] = 0;
    }

    ll mN;
    vector<ll> node;
    //! 遅延評価配列
    vector<ll> lazy;
};