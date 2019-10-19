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
    ll N;
    string S, T;
    cin >> N >> S >> T;
    REP(i, N)
    {
        if (S[i] == T[i])
            continue;
        if (S[i] >= '0' && S[i] <= '9')
        {
            char c = T[i];
            REP(j, N)
            {
                if (S[j] == c)
                    S[j] = S[i];
                if (T[j] == c)
                    T[j] = S[i];
            }
        }
        else
        {
            char c = S[i];
            REP(j, N)
            {
                if (S[j] == c)
                    S[j] = T[i];
                if (T[j] == c)
                    T[j] = T[i];
            }
        }
    }

    ll ans = 1;
    bool U[30] = {false};
    REP(i, N)
    {
        if (S[i] >= '0' && S[i] <= '9')
            continue;
        if (U[S[i] - 'A'])
            continue;
        U[S[i] - 'A'] = true;
        if (i == 0)
            ans *= 9;
        else
            ans *= 10;
    }
    cout << ans << endl;
    return 0;
}