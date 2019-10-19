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
    ll H, W, A, B;
    cin >> H >> W >> A >> B;
    vector<string> M;
    REP(i, H)
    {
        string s = "";
        REP(j, W)
        {
            if ((i < B) ^ (j < A))
                s.push_back('0');
            else
                s.push_back('1');
        }
        M.push_back(s);
    }
    REP(i, H)
    {
        cout << M[i] << endl;
    }

    return 0;
}