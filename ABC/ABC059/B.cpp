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
    string A, B;
    cin >> A >> B;
    string S = "EQUAL";
    if (A.length() > B.length())
        S = "GREATER";
    else if (A.length() < B.length())
        S = "LESS";
    else
    {
        REP(i, A.length())
        {
            if (A[i] == B[i])
                continue;
            if (A[i] > B[i])
                S = "GREATER";
            else
                S = "LESS";
            break;
        }
    }
    cout << S << endl;
    return 0;
}