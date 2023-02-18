//
//  hackerrank.h
//  hackerrank
//
//  Created by Luyang Tang on 15/02/2023.
//

#ifndef hackerrank_h
#define hackerrank_h

#include <vector>
#include <string>

namespace recursiveDigitalSum{
    void test();
    int superDigit(std::string, int);
}

namespace lonelyInteger{
    void test();
    int lonelyInteger(std::vector<int> );
};


namespace diagonalDifference{
    void test();
    int diagonalDifference(std::vector<std::vector<int>> );
};


namespace countingSort1{
    void test();
    std::vector<int> countingSort1(std::vector<int> ) ;
};

namespace zigzagSequence{
    void test();
    void findZigZagSequence(std::vector < int >, int);
}

namespace towerBreakers{
    void test();
    int towerBreakers(int, int);
}

namespace caesarCipher{
    void test();
    std::string caesarCipher(std::string, int);
}

namespace gridChallenge{
    void test();
    std::string gridChallenge(std::vector<std::string>);
}
#endif /* hackerrank_h */
