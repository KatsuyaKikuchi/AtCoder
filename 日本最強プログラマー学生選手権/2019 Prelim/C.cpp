#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

bool L[200005];

int main()
{
    ll N;
    cin >> N;
    string S;
    cin >> S;
    memset(L, 0, sizeof(L));
    ll s = 0;
    bool e = true;
    REP(i, 2 * N)
    {
        if (S[i] == 'B')
        {
            if (s % 2 == 0)
            {
                L[i] = true;
                s++;
            }
            else
            {
                s--;
            }
        }
        else
        {
            if (s % 2 == 0)
            {
                s--;
            }
            else
            {
                L[i] = true;
                s++;
            }
        }
        if (s < 0)
            e = false;
    }

    ll ans = 1;
    s = 0;
    for (int i = 2 * N - 1; i >= 0; --i)
    {
        if (L[i])
        {
            ans *= s;
            s--;
        }
        else
            s++;
        ans %= MOD;
    }

    REP(i, N)
    {
        ans *= (i + 1);
        ans %= MOD;
    }
    if (!e)
        cout << 0 << endl;
    else
        cout << ans << endl;
    return 0;
}