//
//  mySolution.hpp
//  oneWay
//
//  Created by LYT on 23/01/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#ifndef mySolution_hpp
#define mySolution_hpp

#include <stdio.h>

bool isReplacement(char const *string1, char const *string2);
bool isInsert(char const *originalString, char const *newString, int strLen1, int strLen2);
void testIsReplacement();
void testIsInsert();
bool isOneWay(char const *string1, char const *string2, int strLen1, int strLen2);
void testIsOneWay();

#endif /* mySolution_hpp */
