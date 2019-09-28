#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

vector<ll> V, A, C, M;
ll N, K;
bool solvev(ll n)
{
    ll v = n * 10LL - K;
    ll a = n * 7LL - K;
    ll c = n * 7LL - K;

    ll s = std::min((ll)M.size(), n * 7LL);
    REP(i, V.size())
    {
        if (v < V[i])
            break;
        v -= V[i];
        s++;
    }
    REP(i, A.size())
    {
        if (a < A[i])
            break;
        a -= A[i];
        s++;
    }
    REP(i, C.size())
    {
        if (c < C[i])
            break;
        c -= C[i];
        s++;
    }
    return s >= K;
}

int main()
{
    cin >> N >> K;
    REP(i, N)
    {
        ll v, a, c;
        cin >> v >> a >> c;
        if (v > 1)
            V.push_back(v - 1);
        else if (a > 1)
            A.push_back(a - 1);
        else if (c > 1)
            C.push_back(c - 1);
        else
            M.push_back(0);
    }
    sort(V.begin(), V.end());
    sort(A.begin(), A.end());
    sort(C.begin(), C.end());

    ll ok = 10000000, ng = 0;
    while (abs(ok - ng) > 1)
    {
        ll mid = (ok + ng) / 2;
        if (solvev(mid))
            ok = mid;
        else
            ng = mid;
    }

    cout << ok << endl;

    return 0;
}