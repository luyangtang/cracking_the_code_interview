//
//  lego.cpp
//  hackerrank
//
//  Created by Luyang Tang on 23/02/2023.
//

#include <stdio.h>
#include "hackerrank.h"
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>

using namespace::std;
using namespace::utils;

class Wall{
public:
    int n; int m; vector<vector<bool>> wall;
    Wall(int, int);
    void print();
};
ostream &operator<< (ostream &, const vector<int> &);
ostream &operator<< (ostream &, const vector<vector<int>> &);
vector<vector<int>> constructRow(int);
vector<vector<int>> brickToBinary(const vector<vector<int>> &);



int legoBlocks(int n, int m) {
    
    // the first layer will be of
    int res = 0;
    return res % 1000000007;
}


long layoutCount(int n, const vector<vector<int>> &binaryPossibleRows){
//    vector<vector<int>> wall;
    
    cout << binaryPossibleRows;
    
    // base case, when there is only 1 row, then it is the number of possible rows
    if (n == 0) return 1;
    if (n == 1) return binaryPossibleRows.size();
    
    else{
        long counter = 0;
        
        for (int i = 0; i < binaryPossibleRows.size(); i++){
            // loop through each possible rows (n - 1) level and figure out what can be placed on top.
            
            // previous row
            vector<int> prevRow = binaryPossibleRows[i];
            
            for (int j = 0; (j < binaryPossibleRows.size()) && (i != j); j++){
                vector <int> currRow = binaryPossibleRows[j];
//                cout << prevRow << binaryPossibleRows[j] ;
                
                // check if there are slits at the same position by taking sum
                transform(currRow.begin(), currRow.end(), prevRow.begin(),
                          currRow.begin(), std::plus<int>());
                vector<int>::iterator maxCommonSlit = max_element(currRow.begin(), currRow.end() - 1);// ignore the last one
//                cout << currRow << " " << *maxCommonSlit << endl; // ignore the last one
                if (*maxCommonSlit < 2) counter++;
            }
            
            cout << "Valid next row count " << counter << endl;
           
        }
        
        return counter;
    }
}




void lego::test()
{
    int m = 3; int n = 2;
    vector<vector<int>> binaryPossibleRows = brickToBinary(constructRow(m));
    cout << layoutCount(n, binaryPossibleRows) << endl;
//    cout << possibleRows << endl<< brickToBinary(possibleRows);
//    Wall wall(2,3);
//    wall.print();
//
//    cout << legoBlocks(2, 3);
    
    
    /*
    std::ifstream input("/Users/luyangtang/Documents/cracking_the_code_interview/hackerrank/lego/testcase.txt");
    
    string t_temp;
    
    getline(input, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string first_multiple_input_temp;
        getline(input, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        int result = legoBlocks(n, m);

        cout << result << "\n\n";
    }
     */

}


Wall::Wall(int _n, int _m){
    n = _n; m = _m;
//    for (int i = 0; i < n; i++)
//    {
//        wall.push_back(vector<bool>(m, 0));
//    }
}


void Wall::print(){
    for (vector<vector<bool>>::iterator it = wall.end() - 1; it != wall.begin() - 1; it--){
        for (vector<bool>::iterator itr = it->begin(); itr != it->end(); itr++){
            cout << *itr << " ";
        } cout << endl;
    }cout << endl;
}


ostream &operator<< (ostream &out, const vector<int> &v){

        cout << "(";
        for (int i = 0; i < v.size(); i++){
            out << v[i] << " ";
        }
        cout << ")";

    return cout;
}

ostream &operator<< (ostream &out, const vector<vector<int>> &possibleRows){
    int n = possibleRows.size();
    for (int i = 0; i < n; i++){
        out << possibleRows[i] << endl;
    }
    return out;
}


vector<vector<int>> constructRow(int m){
    
    // recursively construct a row.
    vector<vector<int>> possibleRows;
    
    // base case
    if (m == 1){
        possibleRows.push_back({1});
    }
    else if (m == 0){}
    else{
        for (int i = 1; i <= min(4, m); i++){
            vector<int> row;
            
            // put the first brick
            row.push_back(i);
            
            // find out the possible arrangement of other bricks recursively
            vector<vector <int>> remaining = constructRow(m - i);

            // combine the possible arrangement to the first brick
            if (remaining.size()){
                for (vector<vector<int>>::iterator it = remaining.begin(); it != remaining.end(); it++)
                    it->insert(it->begin(), row.begin(), row.end());
                //                row.insert(row.end(), remaining.begin(), remaining.end());
                possibleRows.insert(possibleRows.begin(), remaining.begin(), remaining.end());
            }
            else{
                possibleRows.push_back(row);
            }
        }
    }
    

    return possibleRows;
}



vector<vector<int>> brickToBinary(const vector<vector<int>> &possibleRows){
    // matrix[i][j] indicates if there is a slit
    //  |   | |
    //  1 0 1 1
    // (2, 1)
    
//    cout << possibleRows;
    vector<vector<int>> binaryPossibleRows;
    
    for (int i = 0; i < possibleRows.size(); i++){
//        vector<int> binaryRow({1});
        vector<int> binaryRow;
        
        for (int j = 0; j < possibleRows[i].size(); j++){
            binaryRow.insert(binaryRow.end(), possibleRows[i][j] - 1, 0);
            binaryRow.push_back(1);
        }
        
        binaryPossibleRows.push_back(binaryRow);
    }
    
    return binaryPossibleRows;
}
