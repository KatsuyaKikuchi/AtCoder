#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

pll T[100005];
//! 右回り、左回りでi番目まで取った時のエネルギー最大値
ll R[100005], L[100005];

int main()
{
    ll N, C;
    cin >> N >> C;
    REP(i, N)
    {
        cin >> T[i].first >> T[i].second;
    }
    ll rv = 0, lv = 0;
    REP(i, N)
    {
        ll l = T[i].first;
        lv += T[i].second;
        L[i] = lv - l;
        ll r = C - T[N - 1 - i].first;
        rv += T[N - 1 - i].second;
        R[i] = rv - r;
        if (i > 0)
        {
            L[i] = std::max(L[i], L[i - 1]);
            R[i] = std::max(R[i], R[i - 1]);
        }
    }

    ll max = 0;
    rv = 0;
    lv = 0;
    REP(i, N)
    {
        {
            //! 左回りにiまで歩いて食べ、そこから右回りに戻ってi+1までの最大値分食べる
            ll l = T[i].first;
            lv += T[i].second;
            ll m = std::max(lv - 2 * l + R[N - 2 - i], lv - l);
            max = std::max(max, m);
        }
        {
            //! 右回りにiまで〜
            ll r = C - T[N - 1 - i].first;
            rv += T[N - 1 - i].second;
            ll m = std::max(rv - 2 * r + L[N - 2 - i], rv - r);
            max = std::max(max, m);
        }
    }
    cout << max << endl;
    return 0;
}