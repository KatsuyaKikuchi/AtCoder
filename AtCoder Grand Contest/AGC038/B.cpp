#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

//! Range Minimum Query用 SegmentTree
class SegmentTreeMin
{
public:
    SegmentTreeMin(int n)
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
    ~SegmentTreeMin()
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
    const ll inf = (1LL << 31) - 1LL;
};

//! Range Minimum Query用 SegmentTree
class SegmentTreeMax
{
public:
    SegmentTreeMax(int n)
    {
        ll cnt = 1;
        while (cnt < n)
            cnt <<= 1;
        node.resize(2 * cnt - 1);
        REP(i, 2 * cnt - 1)
        {
            node[i] = -1;
        }
        mN = cnt - 1;
    }
    ~SegmentTreeMax()
    {
        node.resize(0);
    }

    //! 0-index get
    ll get(int left, int right, int l = 0, int r = -1, int index = 0)
    {
        if (r == -1)
            r = mN;

        if (r < left || right < l)
            return -1;
        if (left <= l && r <= right)
            return node[index];
        return std::max(get(left, right, l, (l + r) / 2, 2 * index + 1),
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
            node[par] = std::max(node[2 * par + 1], node[2 * par + 2]);
        }
    }

private:
    ll mN;
    vector<ll> node;
};

ll P[200005];
SegmentTreeMin segMin(200005);
SegmentTreeMax segMax(200005);
bool Q[200005]; //! そーとしても変わらないやつか

ll getMin(ll l, ll r)
{
    return segMin.get(l, r);
}
ll getMax(ll l, ll r)
{
    return segMax.get(l, r);
}
int main()
{
    ll N, K;
    cin >> N >> K;

    REP(i, N)
    {
        cin >> P[i];
        segMin.set(i, P[i]);
        segMax.set(i, P[i]);
    }
    int k = 1;
    memset(Q, 0, sizeof(Q));
    FOR(i, N, 1)
    {
        if (P[i] > P[i - 1])
        {
            k++;
            if (k >= K)
                Q[i - k + 1] = true;
        }
        else
        {
            k = 1;
        }
    }
    ll ans = Q[0] ? 0 : 1;
    FOR(i, N, 1)
    {
        if (Q[i])
            continue;
        if (i + K - 1 >= N)
            break;
        ll min = getMin(i - 1, i - 1 + K - 1);
        ll max = getMax(i, i + K - 1);
        //cout << min << " " << max << endl;
        if (P[i - 1] == min && P[i + K - 1] == max)
            continue;
        ans++;
    }
    REP(i, N)
    {
        if (Q[i])
        {
            ans++;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}