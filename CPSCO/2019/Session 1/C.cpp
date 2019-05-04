#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[100];
vector<ll> S;
int N, K;

void dfs(vector<int> v, int index = 0)
{
    if (v.size() == K)
    {
        ll s = 0;
        REP(i, v.size())
        {
            s += A[v[i]];
        }
        S.push_back(s);
        return;
    }

    FOR(i, N, index)
    {
        v.push_back(i);
        dfs(v, i + 1);
        v.pop_back();
    }
    return;
}

ll calc(ll n)
{
    ll s = 0;
    ll t = 1e9;
    while (n > 0)
    {
        s += n / (5 * t);
        n %= 5 * t;
        s += n / t;
        n %= t;
        t /= 10;
    }
    return s;
}

int main()
{
    cin >> N >> K;
    REP(i, N)
    {
        cin >> A[i];
    }
    vector<int> v;
    dfs(v);
    sort(S.begin(), S.end());
    S.erase(unique(S.begin(), S.end()), S.end());

    ll min = INF;
    REP(i, S.size())
    {
        min = std::min(min, calc(S[i]));
    }
    cout << min << endl;
    return 0;
}