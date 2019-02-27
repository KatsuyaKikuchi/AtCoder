#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll S[20];

int main()
{
    ll N;
    cin >> N;
    ll ans = 0;
    int i = 1;
    for (; pow(10, i) <= N; ++i)
    {
        S[i] = pow(10, i - 1) + S[i - 1] * 10;
    }
    --i;
    for (; i >= 0; --i)
    {
        ll t = pow(10, i);
        FOR(j, 10, 0)
        {
            if (N < (j + 1) * t)
            {
                N %= t;
                if (j == 1)
                    ans += N + 1;
                break;
            }
            ans += S[i];
            if (j == 1)
                ans += t;
        }
    }

    cout << ans << endl;
    return 0;
}