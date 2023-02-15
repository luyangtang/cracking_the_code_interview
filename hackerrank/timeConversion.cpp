#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {

    int hour = std::stoi(s.substr(0, 2));
    
    if (s.substr(s.length() - 2) == "PM") {
        hour = (hour == 12) ? hour : (hour + 12);
    }
    else if (hour == 12){
        hour = 0;
    }
    
    // padding
    string hourStr = (hour >= 10) ? std::to_string(hour) : ("0" + std::to_string(hour));
    
    string outputString = s.replace(0, 2, hourStr).substr(0, s.length() - 2);

    return outputString;
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
