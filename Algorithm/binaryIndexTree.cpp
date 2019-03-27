#include "base.hpp"

class BinaryIndexTree
{
  public:
    BinaryIndexTree(int n)
        : mN(n)
    {
        node.resize(n + 1);
        REP(i, n + 1)
        {
            node[i] = 0;
        }
    }
    ~BinaryIndexTree()
    {
        node.resize(0);
    }

    //! 1-index get
    ll sum(int index)
    {
        ll sum = 0;
        for (int i = index; i > 0; i -= i & (-i))
            sum += node[i];
        return sum;
    }

    //! 1-index add
    void add(int index, ll value)
    {
        for (int i = index; i <= mN; i += i & (-i))
            node[i] += value;
    }

  private:
    vector<ll> node;
    ll mN;
};