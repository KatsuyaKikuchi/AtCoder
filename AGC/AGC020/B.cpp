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
ll A[100005];

bool check(ll n)
{
    REP(i, N)
    {
        ll p = n / A[i];
        n = A[i] * p;
    }
    return n == 2;
}

int main()
{
    cin >> N;
    REP(i, N)
    {
        cin >> A[i];
    }
    //! とりあえず満たすものを1つ求める
    ll t = 2;
    REP(i, N)
    {
        //! t<=k<2*tを満たす最小のA[N-1-i]の倍数
        ll a = A[N - 1 - i];
        ll p = t / a;
        if (a * p >= t)
            t = a * p;
        else
            t = a * (p + 1);
    }
    if (!check(t))
    {
        cout << -1 << endl;
        return 0;
    }

    //! 最小値と最大値を二分探索で見つける
    ll min = t;
    {
        ll ng = 0;
        while (abs(min - ng) > 1)
        {
            ll mid = (min + ng) / 2;
            if (check(mid))
            {
                min = mid;
            }
            else
            {
                ng = mid;
            }
        }
    }
    ll max = t;
    {
        ll ng = (ll)1e17;
        while (abs(max - ng) > 1)
        {
            ll mid = (max + ng) / 2;
            if (check(mid))
            {
                max = mid;
            }
            else
            {
                ng = mid;
            }
        }
    }
    cout << min << " " << max << endl;
    return 0;
}