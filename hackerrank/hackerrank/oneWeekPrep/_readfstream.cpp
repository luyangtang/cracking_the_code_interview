//
//  _readfstream.cpp
//  hackerrank
//
//  Created by Luyang Tang on 22/02/2023.
//

#include "hackerrank.h"
#include <fstream>
#include <string>

using namespace::std;

string utils::ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), [](auto c) {return
            !std::isspace(c);})
    );

    return s;
}

string utils::rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), [](auto c) {return
            !std::isspace(c);}).base(),
        s.end()
    );

    return s;
}



vector<string> utils::split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
