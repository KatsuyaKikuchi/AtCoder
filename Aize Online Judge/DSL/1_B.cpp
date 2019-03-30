#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

class UnionFind
{
  public:
    UnionFind(int n)
        : mN(n)
    {
        REP(i, n)
        {
            mNodeTbl.push_back(i);
            mWaightTbl.push_back(0);
        }
    }

    int find(int x)
    {
        if (x == mNodeTbl[x])
            return x;

        int par = mNodeTbl[x];
        mNodeTbl[x] = find(mNodeTbl[x]);
        mWaightTbl[x] += mWaightTbl[par];
        return mNodeTbl[x];
    }
    bool same(int x, int y)
    {
        return find(x) == find(y);
    }

    ll waight(int x)
    {
        int y = find(x);
        return mWaightTbl[x] - mWaightTbl[y];
    }

    //! y bigger than x
    void unit(int x, int y, ll w)
    {
        int ox = x, oy = y;
        x = find(x);
        y = find(y);
        ll wx = mWaightTbl[ox];
        ll wy = mWaightTbl[oy];
        if (x == y)
            return;
        w = w + wx - wy;
        if (w < 0)
        {
            //! xにyをつなぐ
            mNodeTbl[y] = x;
            mWaightTbl[y] = mWaightTbl[x] - abs(w);
        }
        else
        {
            //! yにxをつなぐ
            mNodeTbl[x] = y;
            mWaightTbl[x] = mWaightTbl[y] - abs(w);
        }
    }

  private:
    int mN;
    vector<int> mNodeTbl;
    vector<ll> mWaightTbl;
};

int main()
{
    ll N, Q;
    cin >> N >> Q;
    UnionFind uf(N);
    REP(i, Q)
    {
        int c;
        cin >> c;
        if (c == 0)
        {
            ll x, y, z;
            cin >> x >> y >> z;
            uf.unit(x, y, z);
        }
        else if (c == 1)
        {
            ll x, y;
            cin >> x >> y;
            if (uf.same(x, y))
                cout << uf.waight(y) - uf.waight(x) << endl;
            else
                cout << '?' << endl;
        }
    }
    return 0;
}