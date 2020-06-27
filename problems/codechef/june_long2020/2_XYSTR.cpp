#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int T;
	cin >> T;
	while( T-- ){
	    string s;
	    cin >> s;
	    int count = 0;
	    for( int i = 0; s.size() > 1 && i < s.size() - 1; i++ ){
	        if( s[i] !=  s[i + 1] ){
	            count++;
	            ++i;
	        }
	    }
	    cout << count << endl;
	}
	return 0;
}
