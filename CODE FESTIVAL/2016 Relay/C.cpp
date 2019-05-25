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
    int N;
    cin >> N;
    vector<ll> A;
    REP(i, 1 << N)
    {
        ll a;
        cin >> a;
        A.push_back(a);
    }
    REP(i, N)
    {
        vector<ll> B;
        REP(j, A.size() / 2)
        {
            ll a = A[2 * j];
            ll b = A[2 * j + 1];
            if (a == b)
                B.push_back(a);
            else if (a > b)
                B.push_back(a - b);
            else
                B.push_back(b - a);
        }
        swap(A, B);
    }
    cout << A[0] << endl;
    return 0;
}