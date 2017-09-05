#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <climits>

using namespace std;

class Solution {
public:
    void getRet(string &s, unordered_set<string> &wordDict){
        auto strs = wordBreak(s, wordDict);
        int ret = INT_MAX;
        string output;
        for(auto &str : strs){
            int size = str.size();
            if(size < ret){
                ret = size;
                string tmp;
                for(auto &i : str) tmp = tmp + i + " ";
                output = tmp.substr(0, tmp.size()-1);
            }
        }
        if(ret == 0 || ret == INT_MAX) output = "n/a";
        cout << output << endl;
    }
private:
    vector<vector<string> > wordBreak(string &s, unordered_set<string> &wordDict){
        if(book.count(s)) return book[s];
        vector<vector<string>> ret;
        if(wordDict.find(s) != wordDict.end()){
            vector<string> tmp;
            tmp.push_back(s);
            ret.push_back(tmp);
        }
        for(int i=0; i<s.size(); ++i){
            string word = s.substr(0,i+1);
            if(wordDict.find(word) != wordDict.end()){
                string w = s.substr(i+1);
                vector<vector<string> > last = wordBreak(w, wordDict);
                combination(word, last);
                ret.insert(ret.end(), last.begin(), last.end());
            }         
        }
        book[s] = ret;
        return ret;
    }

    void combination(string &word, vector<vector<string>> &last){
        for(auto &str : last){
            str.insert(str.begin(), word);
        }
    }
private:
    unordered_map<string, vector<vector<string>> > book;
};




int main(int argc, const char * argv[])
{
    string strS;
    string dictStr;
    int nDict;
    unordered_set<string> dict;
    
    cin>>strS;
    cin>>nDict;
    for (int i = 0; i < nDict; i++)
    {
        cin>>dictStr;
        dict.insert(dictStr);
    }
    Solution Sol;
    Sol.getRet(strS, dict);
    
    return 0;
}
