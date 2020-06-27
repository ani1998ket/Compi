#include <bits/stdc++.h>
using namespace std;

int ask_query( int r1, int c1, int r2, int c2){
    int r;
    printf( "1 %d %d %d %d\n", r1, c1, r2, c2 );
    cin >> r;
    return r;
}
void query1_1( vector< vector<int> >& matrix ){
    int e22 = matrix[1][1], e21 = matrix[1][0], e12 = matrix[0][1];
    if( !( e21 && e12) ){
       matrix[0][0] = 0; 
    }else if( e21 == 2 || e12 == 2 ){
        matrix[0][0] = 1;
    }else{
        if( e22 == 3 ){
            matrix[0][0] = 0;
        }else if( e22 == 1 ){
            matrix[0][0] = 1;
        }else{
            matrix[0][0] = ask_query(1, 1, 1, 1);
        }
    }
}
void process_matrix( vector< vector<int> >& matrix ){
    for( int i = matrix.size() - 1; i > 0; i-- ){
        for( int j = matrix.size() - 1; j > 0; j-- ){
            int pi = i - 1;
            int pj = j - 1;
            matrix[i][j] -= matrix[ pi ][ pj ];
            matrix[i][j] -= matrix[ i ][ pj ] - matrix[ pi ][ pj ];
            matrix[i][j] -= matrix[ pi ][ j ] - matrix[ pi ][ pj ];
        }
    }
    for( int i = matrix.size() - 1; i > 0; i-- ){
        matrix[i][0] -= matrix[i-1][0];
    }
    for( int j = matrix.size() - 1; j > 0; j-- ){
        matrix[0][j] -= matrix[0][j-1];
    }
}
void print_matrix( vector< vector<int> >& matrix ){
    for( int i = 0; i < matrix.size(); i++ ){
        for( int j = 0; j < matrix.size(); j++ ){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void setValue(  vector< vector<int> >& matrix , int r, int c, int val ){
    for( int i = 0; i <= r; i++ ){
        for( int j = 0; j <= c; j++ ){
            matrix[i][j] = val;
        }
    }
}
void setCol(  vector< vector<int> >& matrix , int r, int c, int val ){
    for( int i = 0; i <= r; i++ ){
            matrix[i][c] = val;
    }
}
int main(){
    int T;
    cin >> T;
    while( T-- ){
        int N, P;
        cin >> N >> P;
        vector< vector<int> > matrix( N, vector<int>( N, -1 ) );
        
        for( int i = matrix.size() - 1; i >= 0; i-- ){
            
            if( i != matrix.size() - 1 ){
            
                int j = matrix.size() - 1;
                while( j >= 0 ){
                    int k = j;
                    while( k >= 0 && matrix[i+1][k] == -1 ){
                        k--;
                    }
                    int val = matrix[i+1][k];
                    while( k <= j ){
                        matrix[i+1][k] = val;
                        k++;
                    }
                    j--;
                }

            }
            for( int j = matrix.size() - 1; j >= 0; j-- ){

                //cout << "---------------" << endl;
                //print_matrix( matrix );
                // value unfilled
                if( matrix[i][j] == -1 ){
                    
                    //fill unfilled value in next row
                  //  if( i != matrix.size() - 1 ){
                  //      int k = j;
                  //      while( k > 0 && matrix[i + 1][k] == -1 ){
                  //          k--;
                  //      }
                  //      int val = matrix[i+1][k];
                  //      while( k <= j ){
                  //          matrix[i+1][k] = val;
                  //          k++;
                  //      }
                  //  }
                    // no need to ask if all value lies in left sub grid
                    if( i != matrix.size() - 1 ){
                        if( j > 0 && matrix[i+1][j] == matrix[i+1][j-1] ){      
                            continue;
                        }
                    }
                    if( 1 ){
                         matrix[i][j] = ask_query(1, 1, i + 1, j + 1);
                         // Set every value to 0 in subgrid when query is 0
                         if( matrix[i][j] == 0 ){
                             setValue( matrix, i, j, 0 );
                         // set every value to 1 in case query is max_possible                    
                         }else if( matrix[i][j] == ( i + 1) * ( j + 1 ) ){
                             for( int r = 0; r <= i; r++ ){
                                 for( int c = 0; c <= j; c++ ){
                                     matrix[r][c] = ( r + 1) * ( c + 1 );
                                 }
                             }
                         }
                    }

                }
            
                //print_matrix( matrix );
                //cout << "---------------" << endl;
            }
        }
        int j = matrix.size() - 1;
        while( j >= 0 ){
            int k = j;
            while( k >= 0 && matrix[0][k] == -1 ){
                k--;
            }
            int val = matrix[0][k];
            while( k <= j ){
                matrix[0][k] = val;
                k++;
            }
            j--;
        }
        //query1_1( matrix );
        process_matrix( matrix );
        cout << 2 << endl;
        print_matrix( matrix );
        int X;
        cin >> X;
        if( X == -1 )
            exit(1);
    }
    return 0;
}

