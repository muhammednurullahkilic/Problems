#include <vector>
#include <string>

using namespace std;

bool isValid(string& s) {
    
    if (s.empty() || s.size() > 3 || (s.size() > 1 && s[0] == '0'))
        return false;
    int num = stoi(s);
    return num >= 0 && num <= 255;
}

void backtrack(string& s, int index, int segment, string current, vector<string>& result) {
   
    if (segment == 4 && index == s.size()) {
        
        result.push_back(current);
        return;
    }
    if (segment == 4 || index == s.size()) {
        return;
    }

    for (int len = 1; len <= 3 && index + len <= s.size(); ++len) {
        string segmentStr = s.substr(index, len);
        if (isValid(segmentStr)) 
        {

            string newSegment = segment == 0 ? segmentStr : current + "." + segmentStr;
            backtrack(s, index + len, segment + 1, newSegment, result);
        }
    }
}

vector<string> genIp(string S) {
    vector<string> result;
    backtrack(S, 0, 0, "", result);
    return result.empty() ? vector<string>{"-1"} : result;
}
