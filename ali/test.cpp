#include <iostream>

using namespace std;

class Singleton{
    static Singleton* get_instance(){
        if(ptr == NULL){
            return new Singleton();
        } else {
            return ptr;
        }
    }

    private:
    Singleton();
    ~Singleton();
    Singleton(const Singleton&);
    Singleton operator=(const Singleton&);

    private:
    static Singleton* ptr;
};

Singleton* Singleton::ptr = NULL;



//实现大整数乘法，大整数用10进制的字符串表示，要求空间复杂度O(N)，时间复杂度O(N^2)
#include <string>
#include <utility>
#include <algorithm>
using namespace std;

std::string big_int_multiple(const std::string &lhs, const std::string &rhs) {
  //实现本函数
  //reverse(lhs.begin(), lhs.end());
  //reverse(rhs.begin(), rhs.end());
  int size_l = lhs.size();
  int size_r = rhs.size();
  string ret;
  string cur(size_l + 1， '0');
  for(int i=size_l - 1; i>=0; --i){ 
    // once should named previous
    string once(size_l + 1, '0'); 
    int c = 0;
  	for(int j=size_r-1; j>=0; --j){
    	pair<int,int> tmp{0,0};
        tmp = helper(lhs[i], rhs[j], once[j-1] - '0' + c);
        cur[j-1] = tmp.second + '0';
        c = tmp.first;   
    }
    once = cur;
    //reverse(cur.begin(), cur.end());
  }
  return cur;
}

pair<int, int> helper(char a, char b, int c_before){
	int sum = (a - '0') * (b - '0') + c_before;
    int c = sum/10;
    int ret = sum%10;
    return {c, ret};
}








