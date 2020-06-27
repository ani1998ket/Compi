//Disturbed people
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define REP(i, start, end, d) for( int i = (start); i < (end); i += (d) )
 
void solve(){
    int N; 
    cin >> N;
    vector<int> flats(N, 0);
    for( auto& f : flats ){
        cin >> f;
    }
    int count = 0;
    for( int i = 1; i < N - 1; i++ ){
        if( flats[i] == 0 && flats[i-1] == 1 && flats[i+1] == 1 ){
            flats[i+1] = 0;
            count++;
        }
    }
 
    cout << count << endl;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 1;
	//cin >> T;
 
	while( T-- ){
	    solve();
	}
	return 0;
}
