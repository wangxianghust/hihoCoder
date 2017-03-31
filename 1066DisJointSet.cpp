/*0代表有边，1代表不确定，输出1处的有没有边
 */

#include <iostream>
#include <vector>
#include <string>
#include <map>


using namespace std;

class Solution{
    public:
        map<string, string> parent;
    public:
        string Find(string name){
            if(parent.find(name) == parent.end()){
                return name; //if name is not appread, return it.
            }
            if(parent[name] == name){
                return parent[name];
            } else {
                return parent[name] = Find(parent[name]);
            }
        }

        void Union(string name1, string name2){
            name1 = Find(name1);
            name2 = Find(name2);
            if(name1 != name2){
                parent[name1] = name2;
            }
        }

        bool Friend(string name1, string name2){
            return Find(name1) == Find(name2);
        }
};

int main(){
    freopen("1066test.txt", "r", stdin);
    int total; cin >> total;
    Solution Sol;
    for(int i=0; i<total; ++i){
        int flag;
        cin >> flag;
        string name1, name2;
        cin >> name1 >> name2;
        if(0 == flag){
            if(Sol.parent.find(name1) == Sol.parent.end()) Sol.parent[name1] = name1;
            if(Sol.parent.find(name2) == Sol.parent.end()) Sol.parent[name2] = name2;
            Sol.Union(name1, name2);
        } else {
            if(Sol.Friend(name1, name2)){
                cout << "yes" << endl;
            } else {
                cout << "no" << endl;
            }
        }
    }
}
