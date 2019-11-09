#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[500005];

int main()
{
    string S;
    cin >> S;
    ll N = S.length();
    memset(A, 0, sizeof(A));
    queue<pll> q;
    REP(i, N + 1)
    {
        if (i == 0 && S[i] == '<')
            q.push(pll(i, 0));
        else if (i == N && S[i - 1] == '>')
            q.push(pll(i, 0));
        else if (i < N && S[i - 1] == '>' && S[i] == '<')
            q.push(pll(i, 0));
    }
    while (!q.empty())
    {
        pll t = q.front();
        q.pop();
        A[t.first] = t.second;
        {
            ll n = t.first - 1;
            if (n >= 0 && S[n] == '>')
                q.push(pll(n, t.second + 1));
        }
        {
            ll n = t.first;
            if (n < N && S[n] == '<')
                q.push(pll(n + 1, t.second + 1));
        }
    }
    ll ans = 0;
    REP(i, N + 1)
    {
        ans += A[i];
    }
    cout << ans << endl;
    return 0;
}