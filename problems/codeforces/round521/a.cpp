// Frog jumping
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define REP(i, start, end, d) for( int i = (start); i < (end); i += (d) )
 
void solve(){
    int a, b, k;
    long long result = 0;
    cin >> a >> b >> k; 
    result = ( a - b ) * (long long)( k / 2);
    if( k % 2 != 0 ){
        result += a;
    }
 
    cout << result << endl;
}
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 1;
	cin >> T;
 
	while( T-- ){
	    solve();
	}
	return 0;
}
