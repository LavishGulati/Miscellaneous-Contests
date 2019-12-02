#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unordered_map<int, int> umapii;
typedef unordered_map<int, bool> umapib;
typedef unordered_map<string, int> umapsi;
typedef unordered_map<string, string> umapss;
typedef map<string, int> mapsi;
typedef map<pair<int, int>, int> mappiii;
typedef map<int, int> mapii;
typedef map<int, bool> mapib;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef unordered_set<int> useti;
typedef set<int> seti;
typedef vector<int> vi;

#define uset unordered_set
#define it iterator
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define allp(x) (x)->begin(), (x)->end()
#define f first
#define s second
#define MOD 1000000007
#define PI acos(-1)

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n;
    cin >> n;

    ll dp[n+1][3];
    for(ll i = 1; i <= min(ll(8), n); i++){
        dp[i][0] = 0;
        dp[i][1] = (i-1)/2;
        if(i%2 == 0) dp[i][2] = 2;
        else dp[i][2] = 1;
    }
    for(ll i = 9; i <= n; i++){
        dp[i][0] = dp[i-5][0]+1;
        dp[i][1] = dp[i-5][1];
        dp[i][2] = dp[i-5][2];
    }
    ll a = dp[n][0], b = dp[n][1], c = dp[n][2];
    cout << a+b+c << " " << a << " " << b << " " << c << endl;
}
