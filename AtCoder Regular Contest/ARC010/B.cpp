#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll P[500];
bool D[1000];
int M[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

ll get(string s)
{
    ll t = 0;
    ll m = 0;
    REP(i, s.length())
    {
        if (s[i] == '/')
        {
            REP(j, m - 1)
            {
                t += M[j];
            }
            m = 0;
            continue;
        }
        m = m * 10 + s[i] - '0';
    }

    return t + m - 1;
}

int main()
{
    ll N;
    cin >> N;
    REP(i, N)
    {
        string s;
        cin >> s;
        P[i] = get(s);
    }
    sort(P, P + N);
    memset(D, 0, sizeof(D));
    REP(i, 366)
    {
        if (i % 7 == 0 || i % 7 == 6)
            D[i] = true;
    }
    REP(i, N)
    {
        ll n = P[i];
        while (D[n])
            n++;
        D[n] = true;
    }

    int max = 0;
    int m = 0;
    REP(i, 366)
    {
        if (!D[i])
        {
            max = std::max(m, max);
            m = 0;
            continue;
        }
        m++;
    }
    cout << std::max(max, m) << endl;
    return 0;
}