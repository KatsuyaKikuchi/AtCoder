#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll P[100005];

int main()
{
    ll N;
    cin >> N;
    REP(i, N)
    {
        ll p;
        cin >> p;
        P[p - 1] = i;
    }

    set<ll> left, right;
    right.insert(-1);
    right.insert(N);
    left.insert(1);
    left.insert(-N);

    ll ans = 0;
    for (int i = N - 1; i >= 0; --i)
    {
        left.insert(-P[i]);
        right.insert(P[i]);
        ll l = -(*left.lower_bound(-P[i] + 1));
        ll r = *right.lower_bound(P[i] + 1);
        ll num = 0;
        if (l >= 0)
        {
            //! 左との組み合わせ
            ll nl = -(*left.lower_bound(-l + 1));
            num += (l - nl) * (r - P[i]);
        }
        if (r < N)
        {
            //! 右との組み合わせ
            ll nr = *right.lower_bound(r + 1);
            num += (P[i] - l) * (nr - r);
        }
        ans += num * (i + 1);
    }
    cout << ans << endl;
    return 0;
}