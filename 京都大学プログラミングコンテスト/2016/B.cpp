#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll P[30];
ll N, K;

//! n回開催できる？
bool solve(ll n)
{
    vector<ll> v;
    REP(i, 30)
    {
        if (P[i] > 0)
            v.push_back(P[i]);
    }

    if (v.size() < K)
        return false;
    REP(i, n)
    {
        sort(v.begin(), v.end(), [](ll a, ll b) { return a > b; });
        REP(j, K)
        {
            if (v[j] <= 0)
                return false;
            v[j]--;
        }
    }
    return true;
}

int main()
{
    cin >> N >> K;
    memset(P, 0, sizeof(P));
    REP(i, N)
    {
        string S;
        cin >> S;
        P[S[0] - 'A']++;
    }

    ll ok = 0, ng = 100000;
    while (abs(ok - ng) > 1)
    {
        ll mid = (ok + ng) / 2;
        if (solve(mid))
            ok = mid;
        else
            ng = mid;
    }
    cout << ok << endl;
    return 0;
}