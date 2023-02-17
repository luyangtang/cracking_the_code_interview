//
//  caeserCipher.cpp
//  hackerrank
//
//  Created by Luyang Tang on 17/02/2023.
//

#include <stdio.h>
#include "hackerrank.h"
#include <iostream>
#include <string>

using namespace::std;

void caesarCipher::test(){
    
    string s = "!m-rB`-oN!.W`cLAcVbN/CqSoolII!SImji.!w/`Xu`uZa1TWPRq`uRBtok`xPT`lL-zPTc.BSRIhu..-!.!tcl!-U";
    
    
    cout  << caesarCipher(s, 10) << endl ;
    
//    cout << caesarCipher("Always-Look-on-the-Bright-Side-of-Life", 5) << endl;
    cout << "!w-bL`-yX!.G`mVKmFlX/MaCyyvSS!CSwts.!g/`He`eJk1DGZBa`eBLdyu`hZD`vV-jZDm.LCBSre..-!.!dmv!-E" << endl;
    
    cout << s << endl;
    cout << 62 % 26 << endl;
    
};

string caesarCipher::caesarCipher(string s, int k){
    
    string sCiphered;
    
    k = k % 26;
    
    for (string::iterator it = s.begin(); it != s.end(); it++){
        char a('a');
        char A('A');
        
        // if it is capital letter
        if (int(*it) >= int (A) && int(*it) < int (A) + 26){
            sCiphered += (int(*it) + k - int(A) + 26) % 26 + int(A);
            
        // lower case
        } else if (int(*it) >= int(a) && int(*it) < int(a) + 26){
            sCiphered += (int(*it) + k - int(a) + 26) % 26 + int(a);
        }
        
        // special symbols
        else {
            sCiphered += *it;
        }
        
        cout << *it << " " << int(*it) << " " << (int(*it) + k - int(A) + 26) % 26 + int(A) << " " << char((int(*it) + k - int(A) + 26) % 26 + int(A))
        << " " << (int(*it) + k - int(a) + 26) % 26 + int(a)<< " " << char((int(*it) + k - int(a) + 26) % 26 + int(a)) << endl ;
            
    }
    return sCiphered;
}
