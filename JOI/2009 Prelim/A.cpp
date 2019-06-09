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

    vector<int> v;
    REP(i, 3)
    {
        int h0, m0, s0;
        cin >> h0 >> m0 >> s0;
        int h1, m1, s1;
        cin >> h1 >> m1 >> s1;

        int s = s1 - s0;
        int m = m1 - m0;
        int h = h1 - h0;
        if (s < 0)
        {
            s += 60;
            m--;
        }
        if (m < 0)
        {
            m += 60;
            h--;
        }
        v.push_back(h);
        v.push_back(m);
        v.push_back(s);
    }

    REP(i, 3)
    {
        REP(j, 3)
        {
            cout << v[3 * i + j];
            if (j < 2)
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}