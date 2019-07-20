#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

class BinaryIndexTree
{
public:
    BinaryIndexTree(int n)
        : mN(n)
    {
        mPow = 1;
        while (mPow < n)
            mPow <<= 1;
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

    int lowerBound(ll value)
    {
        if (value <= 0)
            return 0;
        int x = 0;
        for (int k = mPow; k > 0; k >>= 1)
        {
            if (x + k <= mN && node[x + k] < value)
            {
                value -= node[x + k];
                x += k;
            }
        }
        return x + 1;
    }

private:
    vector<ll> node;
    ll mN;
    ll mPow;
};

ll R, C, N;
struct Line
{
    pll a;
    pll b;
};

ll length(pll g)
{
    //! (0,0)からの距離
    if (g.second == 0)
        return g.first;
    if (g.first == R)
        return R + g.second;
    if (g.second == C)
        return R + C + (R - g.first);
    return R + C + R + (C - g.second);
}

bool onEdge(pll g)
{
    if (g.first == 0 || g.first == R)
        return true;
    if (g.second == 0 || g.second == C)
        return true;
    return false;
}

int main()
{
    cin >> R >> C >> N;
    vector<Line> L;
    vector<ll> S;
    REP(i, N)
    {
        pll a, b;
        cin >> a.first >> a.second >> b.first >> b.second;
        if (!onEdge(a) || !onEdge(b))
            continue;
        Line l;
        ll la = length(a), lb = length(b);
        if (la < lb)
        {
            l.a = a;
            l.b = b;
        }
        else
        {
            l.a = b;
            l.b = a;
        }
        L.push_back(l);
        S.push_back(la);
        S.push_back(lb);
    }
    sort(L.begin(), L.end(), [](Line a, Line b) { return length(a.a) < length(b.a); });

    BinaryIndexTree bit(S.size());
    sort(S.begin(), S.end());
    bool f = true;
    REP(i, L.size())
    {
        ll la = length(L[i].a);
        ll lb = length(L[i].b);
        int ia = lower_bound(S.begin(), S.end(), la) - S.begin();
        int ib = lower_bound(S.begin(), S.end(), lb) - S.begin();
        int num = bit.sum(ib) - bit.sum(ia);
        //cout<<bit.sum(ib)<<" "<<bit.sum(ia)<<endl;
        if (num > 0)
            f = false;
        bit.add(ib, 1);
    }
    if (f)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}