#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int N;
ll A[200005];
ll B[200005];
ll C[200005];
ll D[35];

//! under以上になる最小のindex
ll getUnder(ll under)
{
    if (under <= 0)
        return 0;
    ll ok = N, ng = -1;
    while (abs(ok - ng) > 1)
    {
        int mid = (ok + ng) / 2;
        if (C[mid] >= under)
        {
            ok = mid;
        }
        else
        {
            ng = mid;
        }
    }
    return ok;
}
//! top未満になる最大のindex
ll getTop(ll top)
{
    ll ok = -1, ng = N;
    while (abs(ok - ng) > 1)
    {
        int mid = (ok + ng) / 2;
        if (C[mid] < top)
        {
            ok = mid;
        }
        else
        {
            ng = mid;
        }
    }
    return ok;
}

int main()
{
    cin >> N;
    REP(i, N)
    {
        cin >> A[i];
    }
    REP(i, N)
    {
        cin >> B[i];
    }
    ll ans = 0;
    ll bit = 1;
    REP(i, 29)
    {
        D[i] = 0;
        bit <<= 1;
        REP(j, N)
        {
            C[j] = (B[j] % bit);
        }
        sort(C, C + N);
        ll t = (bit >> 1);
        REP(j, N)
        {
            ll a = A[j] % bit;
            {
                ll ui = getUnder(t - a);
                ll ti = getTop(2 * t - a);
                if (ui <= ti)
                {
                    D[i] += (ti - ui + 1);
                }
            }
            {
                ll ui = getUnder(3 * t - a);
                ll ti = getTop(4 * t - a);
                if (ui <= ti)
                {
                    D[i] += (ti - ui + 1);
                }
            }
        }
        ans |= ((D[i] % 2) << i);
    }

    cout << ans << endl;
    return 0;
}