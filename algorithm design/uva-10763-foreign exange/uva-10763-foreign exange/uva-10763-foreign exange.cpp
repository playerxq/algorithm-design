// uva-10763-foreign exange.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cctype>
#include <cmath>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <utility>
#include <bitset>
#define L(x) x << 1
#define R(x) x << 1 | 1

using namespace std;
int Case, x, y, opt[1000][1000];

int solve ( ) {
    for ( int i = 0; i < 1000; ++i ) 
	for ( int j = 0; j < 1000; ++j ) 
	    if ( opt[i][j] != 0 ) return 0;
    return 1;
}

int main ( ) {
    while ( cin >> Case && Case ) {
	memset ( opt, 0, sizeof ( opt ) );
	for ( int i = 1; i <= Case; ++i ) {
	    cin >> x >> y;
	    opt[x][y]++;
	    opt[y][x]--;
	}

	if ( solve ( ) ) cout << "YES" << endl;
	else cout << "NO" << endl;
    }
    return 0;
}

