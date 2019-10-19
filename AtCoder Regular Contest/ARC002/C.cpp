#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

char C[4] = {'A', 'B', 'X', 'Y'};

int main()
{
    ll N;
    cin >> N;
    string S;
    cin >> S;
    vector<string> v;
    REP(i, 4)
    {
        REP(j, 4)
        {
            string s = "";
            s.push_back(C[i]);
            s.push_back(C[j]);
            v.push_back(s);
        }
    }

    ll min = INF;
    REP(i, v.size())
    {
        REP(j, v.size())
        {
            string c0 = v[i];
            string c1 = v[j];
            ll m = 0;
            REP(n, N)
            {
                m++;
                if (n < N - 1 && ((S[n] == c0[0] && S[n + 1] == c0[1]) || (S[n] == c1[0] && S[n + 1] == c1[1])))
                    n++;
            }
            min = std::min(m, min);
        }
    }
    cout << min << endl;

    return 0;
}