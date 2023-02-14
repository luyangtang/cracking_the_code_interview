#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    
    if (s.substr( s.length() - 2 ) == "PM" ){
        int hour = (s.substr(0, 2) != "12")? (stoi(s.substr(0, 2)) + 12) : 0;
        s.replace(0, 2, (hour == 0) ? "00" : std::to_string(hour));
    }

    return s.substr(0, s.length() - 2);

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
