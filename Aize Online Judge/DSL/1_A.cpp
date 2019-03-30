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
    UnionFind(int N)
    {
        par.resize(N);
        rank.resize(N);
        REP(i, N)
        {
            par[i] = i;
            rank[i] = 0;
        }
    }
    ~UnionFind()
    {
        par.resize(0);
        rank.resize(0);
    }

    ll find(int x)
    {
        if (par[x] == x)
            return x;
        return par[x] = find(par[x]);
    }

    bool same(ll x, ll y)
    {
        return find(x) == find(y);
    }

    void unit(ll x, ll y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return;
        if (rank[x] > rank[y])
        {
            par[y] = x;
        }
        else
        {
            par[x] = y;
            if (rank[x] == rank[y])
                rank[y]++;
        }
    }

  private:
    vector<ll> par;
    vector<ll> rank;
};

int main()
{
    ll N, Q;
    cin >> N >> Q;
    UnionFind uf(N);
    REP(i, Q)
    {
        int c, a, b;
        cin >> c >> a >> b;
        if (c == 0)
        {
            uf.unit(a, b);
        }
        else if (c == 1)
        {
            if (uf.same(a, b))
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
    }
    return 0;
}