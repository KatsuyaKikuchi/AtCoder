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

struct Node
{
    int a;
    int b;
    int c;
};

ll M[105][105];
Node n[100005];
int x[2] = {0, 1}, y[2] = {1, 0};

int main()
{
    int H, W;
    cin >> H >> W;
    pll S, G;
    cin >> S.first >> S.second >> G.first >> G.second;
    ll cost = 0;
    REP(i, H)
    {
        REP(j, W)
        {
            cin >> M[i][j];
            cost += M[i][j];
        }
    }

    int num = 0;
    REP(h, H)
    {
        REP(w, W)
        {
            REP(i, 2)
            {
                int nh = h + y[i], nw = w + x[i];
                if (nh >= H || nw >= W)
                    continue;
                Node node;
                node.a = W * h + w;
                node.b = W * nh + nw;
                node.c = M[h][w] * M[nh][nw];
                n[num++] = node;
            }
        }
    }
    UnionFind uf;
    uf.init(H * W);
    sort(n, n + num, [](Node a, Node b) { return a.c > b.c; });

    REP(i, num)
    {
        if (uf.same(n[i].a, n[i].b))
            continue;
        uf.unit(n[i].a, n[i].b);
        cost += n[i].c;
    }
    cout << cost << endl;
    return 0;
}