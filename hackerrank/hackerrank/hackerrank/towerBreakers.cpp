//
//  towerBreakers.cpp
//  hackerrank
//
//  Created by Luyang Tang on 16/02/2023.
//

#include <stdio.h>
#include "hackerrank.h"
#include <iostream>

using namespace::std;
using namespace::towerBreakers;

void towerBreakers::test(){

    
    cout << towerBreakers(3, 7) << endl;
}




int towerBreakers::towerBreakers(int n, int m) {
    
    // when there are even number of towers, play 2 can always copy Play 1's move so Play 2 always win
    if (n % 2 == 0 || m == 1) return 2;
    
    // First player can reduce it to 1 and then it will be n-is-even case starting from player 2
    return 1;
    
//    return 1;
}

