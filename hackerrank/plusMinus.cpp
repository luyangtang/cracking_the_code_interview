#include <bits/stdc++.h>
#include <cmath>
#include <iomanip>


using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'plusMinus' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void plusMinus(vector<int> arr) {
    
    double posCnt = 0;
    double negCnt = 0;
    double zeroCnt = 0;
    
    for(int i : arr) 
    {
        int positivity = (i == 0) ? 0 : (i / abs(i));
        switch(positivity){
            case 1:
                posCnt++;
                break;
            case -1:
                negCnt++;
                break;
            default:
                zeroCnt++;
        }
    }
    
    std::cout << std::setprecision(6) << std::fixed;
    // cout << arr.size() << ' ' << posCnt << ' '<< negCnt << ' '<<  zeroCnt<< endl;
    cout << round(1000000 * posCnt / arr.size()) / 1000000 << endl;
    cout << round(1000000 * negCnt / arr.size()) / 1000000 << endl;
    cout <<  round(1000000 * zeroCnt / arr.size()) / 1000000 << endl;
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    plusMinus(arr);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
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
