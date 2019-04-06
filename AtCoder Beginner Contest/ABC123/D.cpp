#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[3005];
ll B[3005];
ll C[3005];

int main()
{
    ll X, Y, Z, K;
    cin >> X >> Y >> Z >> K;
    REP(i, X)
    {
        cin >> A[i];
    }
    REP(i, Y)
    {
        cin >> B[i];
    }
    REP(i, Z)
    {
        cin >> C[i];
    }
    sort(A, A + X, [](ll a, ll b) { return a > b; });
    sort(B, B + Y, [](ll a, ll b) { return a > b; });
    sort(C, C + Z, [](ll a, ll b) { return a > b; });
    vector<ll> v;
    REP(a, X)
    {
        REP(b, Y)
        {
            v.push_back(A[a] + B[b]);
        }
    }
    sort(v.begin(), v.end(), [](ll a, ll b) { return a > b; });
    vector<int> zi(Z, 0);
    REP(i, K)
    {
        int mi = Z - 1;
        REP(z, Z)
        {
            if (zi[z] >= v.size())
                continue;
            if (C[z] + v[zi[z]] > C[mi] + v[zi[mi]])
                mi = z;
        }
        cout << C[mi] + v[zi[mi]] << endl;
        zi[mi]++;
    }
    return 0;
}