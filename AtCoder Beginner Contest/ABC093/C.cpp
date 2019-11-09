#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int main()
{
    ll S[3];
    ll odd = 0;
    REP(i, 3)
    {
        cin >> S[i];
        if (S[i] % 2 == 1)
            odd++;
    }
    REP(i, 3)
    {
        if (odd == 1)
        {
            if (S[i] % 2 == 0)
                S[i]++;
        }
        else if (odd == 2)
        {
            if (S[i] % 2 == 1)
                S[i]++;
        }
    }
    sort(S, S + 3);
    ll ans = 0;
    if (odd == 1 || odd == 2)
        ans++;
    ans += (S[2] - S[1]) / 2 + (S[2] - S[0]) / 2;

    cout << ans << endl;
    return 0;
}