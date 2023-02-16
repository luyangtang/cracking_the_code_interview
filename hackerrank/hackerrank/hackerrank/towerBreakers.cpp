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
//    cout << "Player " << towerBreakers(1, 4) << " wins";
//    cout << endl;
    
//    vector<int> a = defactorise(6);
//
//    for (vector<int>::iterator it = a.begin(); it != a.end(); ++it){
//        cout << *it << " ";
//    }
    
//    cout << playerWins(4, 1) << endl;
    
    cout << towerBreakers(2, 2) << endl;
    cout << towerBreakers(1, 4) << endl;
}


int playerWins(int m, int p){
    // when player p reaching m, decides if p will win
    
    if (m == 1) return 3 - p;
    if (m == 2) return p;
    
    // otherwise find the possible moves of player 2
    
    cout << "possible takes: " << endl;
    for (int i = 1; (i < m) && (m % i == 0); i++){
        cout << "    " << i << " (Player " << (3 - p) << " starts with " << (m - i) << ")" << endl;
        
        // as long as there is 1 path for current player to win, jump out of the loop
        if (playerWins(m -i, 3 - p) == p) return p;
    }
    cout << endl;
    
    return true;
}

int towerBreakers::towerBreakers(int n, int m) {
    
    // when there are even number of towers, play 2 can always copy Play 1's move so Play 2 always win
    if (n % 2 == 0) return 2;
    
    // when there are odd number of towers, play 2 can play copy the strategy until there is 1 tree (maybe partially) left
    return playerWins(m, 1);
    
//    return 1;
}

