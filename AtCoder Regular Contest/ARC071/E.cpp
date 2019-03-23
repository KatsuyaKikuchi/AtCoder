#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

pll A[100005], B[100005];

int main()
{
    string S, T;
    cin >> S >> T;
    A[0] = B[0] = pll(0, 0);
    REP(i, S.length())
    {
        A[i + 1] = A[i];
        if (S[i] == 'A')
            A[i + 1].first++;
        else
            A[i + 1].second++;
    }
    REP(i, T.length())
    {
        B[i + 1] = B[i];
        if (T[i] == 'A')
            B[i + 1].first++;
        else
            B[i + 1].second++;
    }

    int Q;
    cin >> Q;
    REP(i, Q)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;
        c--;
        pll s(A[b].first - A[a].first, A[b].second - A[a].second);
        pll t(B[d].first - B[c].first, B[d].second - B[c].second);

        ll sa = s.first + s.second * 2;
        ll ta = t.first + t.second * 2;
        if (abs(sa - ta) % 3 == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}