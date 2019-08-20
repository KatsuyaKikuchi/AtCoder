#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

bool C[30];
vector<ll> A[30];

int main()
{
    string S, T;
    cin >> S >> T;
    memset(C, 0, sizeof(C));
    REP(i, S.length())
    {
        C[S[i] - 'a']++;
        A[S[i] - 'a'].push_back(i);
    }
    REP(i, 30)
    {
        A[i].push_back(INF);
    }

    bool e = true;
    REP(i, T.length())
    {
        if (C[T[i] - 'a'] == 0)
            e = false;
    }

    if (!e)
    {
        cout << -1 << endl;
        return 0;
    }

    ll index = -1;
    ll ans = 0;
    REP(i, T.length())
    {
        ll n = T[i] - 'a';
        ll m = lower_bound(A[n].begin(), A[n].end(), index + 1) - A[n].begin();
        if (A[n][m] == INF)
        {
            m = 0;
            ans += A[n][m] + (S.length() - index);
        }
        else
        {
            ans += A[n][m] - index;
        }
        index = A[n][m];
    }
    cout << ans << endl;
    return 0;
}