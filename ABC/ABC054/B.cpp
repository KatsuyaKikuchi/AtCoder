#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int N, M;
string A[55], B[55];

bool check(int th, int tw)
{
    if (N - th + 1 < M || N - tw + 1 < M)
        return false;
    REP(h, M)
    {
        REP(w, M)
        {
            if (A[th + h][tw + w] != B[h][w])
                return false;
        }
    }
    return true;
}

int main()
{
    cin >> N >> M;
    REP(i, N)
    {
        cin >> A[i];
    }
    REP(i, M)
    {
        cin >> B[i];
    }

    string ans = "No";
    REP(h, N)
    {
        REP(w, N)
        {
            if (check(h, w))
            {
                ans = "Yes";
            }
        }
    }
    cout << ans << endl;
    return 0;
}