#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int N, K;
int A[100005];
pair<string, int> S[100005];

string solve()
{
    if (N == K)
        return "";
    sort(A, A + K);
    sort(S, S + N, [](pair<string, int> a, pair<string, int> b) { return a.first < b.first; });
    int f = N, l = 0;
    REP(i, N)
    {
        if (*lower_bound(A, A + K, S[i].second) == S[i].second)
        {
            f = std::min(f, (int)i);
            l = std::max(l, (int)i);
        }
    }
    if (l - f + 1 != K)
        return "-1";

    int fn = 0;
    if (f > 0)
    {
        REP(i, std::min(S[f - 1].first.length(), S[f].first.length()))
        {
            if (S[f].first[i] != S[f - 1].first[i])
                break;
            fn++;
        }
    }
    int ln = 0;
    if (l < N - 1)
    {
        REP(i, std::min(S[l + 1].first.length(), S[l].first.length()))
        {
            if (S[l].first[i] != S[l + 1].first[i])
                break;
            ln++;
        }
    }
    int mn = std::max(ln, fn) + 1;
    string ans = "";
    string fs = S[f].first;
    string ls = S[l].first;
    if (std::min(fs.length(), ls.length()) < mn)
        return "-1";
    REP(i, mn)
    {
        if (fs[i] != ls[i])
            return "-1";
        ans.push_back(fs[i]);
    }
    return ans;
}

int main()
{

    cin >> N >> K;
    REP(i, K)
    {
        cin >> A[i];
        A[i]--;
    }
    A[K] = INF;

    REP(i, N)
    {
        cin >> S[i].first;
        S[i].second = i;
    }
    cout << solve() << endl;
    return 0;
}