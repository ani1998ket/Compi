// Good Array
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define REP(i, start, end, d) for( int i = (start); i < (end); i += (d) )
 
void solve(){    
    int N;
    cin >> N;
    vector<int> arr( N, 0 );
    unordered_map<int, int> count_map;
    long long sum = 0;
    for( auto& e : arr ){
        cin >> e;
        sum += e;
        count_map[ e ]++;
    }
    vector<int> result;
    int index = 0;
    for( auto e : arr ){
        ++index;
        sum -= e;
        if( sum & 1 || sum > INT_MAX){
            sum += e;
            continue;
        }
        count_map[e]--;
        if( count_map[ sum / 2 ] > 0 ){
            result.push_back( index );
        }
        count_map[e]++;
        sum += e;
    }
 
    cout << result.size() << endl;
    for ( auto e : result ){
        cout << e << " ";
    }
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
