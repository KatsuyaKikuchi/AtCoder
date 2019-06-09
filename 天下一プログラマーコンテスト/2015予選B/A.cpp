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
    vector<ll> A;
    A.push_back(100);
    A.push_back(100);
    A.push_back(200);
    while (A.size() <= 20)
    {
        int i = A.size() - 1;
        ll a = A[i] + A[i-1] + A[i-2];
        A.push_back(a);
    }
    cout << A[19] << endl;

    return 0;
}