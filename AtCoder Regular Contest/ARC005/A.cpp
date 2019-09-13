#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

string A[3] = {"TAKAHASHIKUN", "Takahashikun", "takahashikun"};
int main()
{
    ll N;
    cin >> N;

    ll s = 0;
    REP(i, N)
    {
        string S;
        cin >> S;
        REP(j, 3)
        {
            if (S == A[j] || S == A[j] + ".")
                s++;
        }
    }
    cout << s << endl;
    return 0;
}