#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

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

pll E[60];

int main()
{
    int N, M;
    cin >> N >> M;
    REP(i, M)
    {
        cin >> E[i].first >> E[i].second;
        E[i].first--;
        E[i].second--;
    }

    int n = 0;
    REP(i, M)
    {
        //! 橋iを取り除いた時に連結になるか調べる
        UnionFind uf;
        uf.init(N);
        REP(j, M)
        {
            if (i == j)
                continue;
            uf.unit(E[j].first, E[j].second);
        }

        REP(j, N - 1)
        {
            if (!uf.same(j, j + 1))
            {
                n++;
                break;
            }
        }
    }
    cout << n << endl;
    return 0;
}