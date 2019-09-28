#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

string S;
ll N;
vector<ll> v;

char solve(ll q)
{
    ll ok = 0, ng = N;
    while (abs(ok - ng) > 1)
    {
        ll mid = (ok + ng) / 2;
        if (v[mid] < q)
            ok = mid;
        else
            ng = mid;
    }
    //cout << v[ok] << endl;
    return S[q - v[ok] - 1];
}

int main()
{
    cin >> N;
    cin >> S;
    REP(i, N)
    {
        ll n = i + 1;
        v.push_back((i * (i + 1) / 2));
    }
    ll Q;
    cin >> Q;
    REP(i, Q)
    {
        ll q;
        cin >> q;
        cout << solve(q) << endl;
    }
    return 0;
}