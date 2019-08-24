#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll N;
ll A[100005];
bool U[100005];

string solve()
{
    sort(A, A + N);
    ll s = -1;
    ll t = -1;
    REP(i, N - 1)
    {
        ll x = A[N - 1] ^ A[i];
        ll ok = i, ng = N - 1;
        while (abs(ok - ng) > 1)
        {
            ll mid = (ok + ng) / 2;
            if (A[mid] <= x)
                ok = mid;
            else
                ng = mid;
        }
        if (ok == i || A[ok] != x)
            continue;
        s = i;
        t = ok;
        break;
    }
    if (s < 0 || t < 0)
        return "No";

    U[N - 1] = U[s] = U[t] = true;
    vector<ll> v;
    v.push_back(A[N - 1]);
    v.push_back(A[s]);
    v.push_back(A[t]);

    while (v.size() < N)
    {
        ll num = v.size();
        ll x = v[num - 1] ^ v[num - 2];
        int low = lower_bound(A, A + N, x) - A;
        int upp = upper_bound(A, A + N, x) - A;
        ll ok = low, ng = upp;
        while (abs(ok - ng) > 1)
        {
            ll mid = (ok + ng) / 2;
            if (!U[mid])
                ok = mid;
            else
                ng = mid;
        }
        int index = ok;
        if (x != A[index] || U[index])
            return "No";
        v.push_back(A[index]);
        U[index] = true;
    }

    if ((v[0] ^ v[1]) != v[N - 1])
        return "No";
    return "Yes";
}

int main()
{
    cin >> N;
    REP(i, N)
    {
        cin >> A[i];
    }

    cout << solve() << endl;
    return 0;
}
