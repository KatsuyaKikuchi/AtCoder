#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[100005];

int main()
{
    int N;
    cin >> N;
    REP(i, N)
    {
        cin >> A[i];
    }
    sort(A, A + N, [](ll a, ll b) { return a > b; });
    vector<ll> v;
    FOR(i, N, 1)
    {
        if (A[i] == A[i - 1])
        {
            v.push_back(A[i++]);
            continue;
        }
    }
    v.push_back(0);
    v.push_back(0);
    cout << v[0] * v[1] << endl;
    return 0;
}