#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int T[200005][30];

int main()
{
    string S;
    cin >> S;
    REP(i, S.length())
    {
        T[i][(int)(S[i] - 'a')]++;
    }
    FOR(i, S.length(), 1)
    {
        REP(j, 30)
        {
            T[i][j] += T[i - 1][j];
        }
    }

    ll sum = 1;
    REP(i, S.length())
    {
        int t = (int)(S[i] - 'a');
        sum += (S.length() - 1 - i) - (T[S.length() - 1][t] - T[i][t]);
    }
    cout << sum << endl;
    return 0;
}