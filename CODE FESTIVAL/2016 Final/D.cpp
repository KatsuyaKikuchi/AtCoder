#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

vector<ll> Y[100005];
//! 同じmodのなかで同じ整数ペアの数
ll P[100005];
ll S[100005];

int main()
{
    ll N, M;
    cin >> N >> M;
    vector<ll> v;
    REP(i, N)
    {
        ll x;
        cin >> x;
        Y[x % M].push_back(x);
        if (Y[x % M].size() == 1)
            v.push_back(x % M);
    }

    memset(P, 0, sizeof(P));
    memset(S, 0, sizeof(S));
    REP(i, v.size())
    {
        sort(Y[v[i]].begin(), Y[v[i]].end());
        ll p = 0;
        FOR(j, Y[v[i]].size(), 1)
        {
            if (Y[v[i]][j - 1] == Y[v[i]][j])
            {
                p++;
                j++;
            }
        }
        S[v[i]] = Y[v[i]].size();
        P[v[i]] = p;
    }

    ll ans = 0;
    REP(i, v.size())
    {
        //! 先に足してMの倍数になるのかぞえる
        ll n = std::min(S[v[i]], S[(M - v[i]) % M]);
        if (v[i] == 0 || v[i] == M / 2)
            n /= 2;
        ans += n;
        S[v[i]] -= n;
        S[(M - v[i]) % M] -= n;
    }

    REP(i, v.size())
    {
        //! ペアが残ってれば数える
        ans += std::min(P[v[i]], S[v[i]] / 2);
    }
    cout << ans << endl;
    return 0;
}