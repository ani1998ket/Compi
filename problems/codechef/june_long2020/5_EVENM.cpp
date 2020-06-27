#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio( 0 );
	cin.tie( 0 );
	int T;
	cin >> T;
	while( T-- ){
	    int N;
	    cin >> N;
	    int num = 1;
	    int change = 1;
        for( int i = 0; i < N; i++ ){
            num = N * i + 1;
            change = 1;
            if( i % 2 != 0){
                num = N * ( i + 1 );
                change = -1;
            }
            for( int j = 0; j < N; j++ ){
                cout << num << " ";
                num += change;         
            }
            cout << endl;
        }
	}
	return 0;
}

