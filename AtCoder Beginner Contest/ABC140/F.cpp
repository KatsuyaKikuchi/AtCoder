#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll S[1000005];
ll N;
ll D[25];
ll E[25];

string solve()
{
    ll M = pow(2, N);
    sort(S, S + M, [](ll a, ll b) { return a > b; });
    ll n = 0;
    bool f = true;
    memset(E, 0, sizeof(E));
    E[N] = 1;
    REP(i, M)
    {
        n++;
        if (i < M - 1 && S[i] == S[i + 1])
            continue;
        if (f)
        {
            f = false;
            if (n > 1)
                return "No";
            n = 0;
            continue;
        }
        //cout << n << endl;
        memset(D, 0, sizeof(D));
        for (int j = N; j > 0; --j)
        {
            ll m = std::min(E[j], n);
            E[j] -= m;
            //! 今回生成したやつ
            D[j - 1] += m;
            //! 前回のが降りてきたやつ
            E[j - 1] += m;
            n -= m;
        }
        REP(j, N + 1)
        {
            E[j] += D[j];
        }
        // REP(j, N + 1)
        // {
        //     cout << E[j] << " ";
        // }
        // cout << endl;

        if (n > 0)
            return "No";
    }
    FOR(i, N + 1, 1)
    {
        if (E[i] > 0)
            return "No";
    }
    return "Yes";
}

int main()
{
    cin >> N;
    ll M = pow(2, N);
    REP(i, M)
    {
        cin >> S[i];
    }
    cout << solve() << endl;
    return 0;
}