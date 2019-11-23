#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int main()
{
    vector<ll> A(2), B(2);
    cin >> A[0] >> A[1];
    cin >> B[0] >> B[1];
    ll C;
    cin >> C;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    B.erase(unique(B.begin(), B.end()), B.end());

    vector<ll> v;
    REP(i, A.size())
    {
        if (A[i] == C)
        {
            REP(j, B.size())
            {
                v.push_back(B[j]);
            }
            break;
        }
    }
    REP(i, B.size())
    {
        if (B[i] == C)
        {
            REP(j, A.size())
            {
                v.push_back(A[j]);
            }
            break;
        }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    cout << v.size() << endl;
    REP(i, v.size())
    {
        cout << v[i] << endl;
    }
    return 0;
}