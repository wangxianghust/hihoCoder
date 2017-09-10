/*one month has 2592000 seconds, we can use int32_t to save this.
 *the August has 31 days, we use 31 bucket to save these time(not include 9.1)
 *then calcuate each day
 */

#include <stdint.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int ONE_DAY = 86400; // 24*3600
const int OFFSET = 10800; // 3*3600 
const int NOON_START = 45000; // 12*3600 + 30*60
const int NOON_END = 5040; // 14*3600

int calculate_one_day(vector<int32_t>& day){
    int size = day.size();
    if(size < 2) return 0;
    int ret = 0;
    sort(day.begin(), day.end());
    int start = (day.front() - OFFSET) % ONE_DAY;
    int end = (day.back() - OFFSET) % ONE_DAY;
    if(start >= NOON_END || end < NOON_START){
        ret = end - start + 1;
    } else {
        int left = (NOON_START > start) ? (NOON_START - start) : 0;
        int right = (NOON_END <= end) ? (end - NOON_END + 1) : 0;
        ret = left + right;
    }
    return ret-1; //there is still some problems.
}

string int2str(int day){
    if(day<10){
        return "0" + to_string(day);
    } else {
        return to_string(day);
    }
}

void work(vector<vector<int32_t> > &times){
    int size = times.size();
    for(int i=0; i<size; ++i){
        int ret = calculate_one_day(times[i]);
        if(ret > 0){
            cout << "08." + int2str(i) + " " + to_string(ret) << endl;
        }
    }
}

int str2int(string &s){
    if(s[0] == '0'){
        return s[1] - '0';
    } else {
        return stoi(s);
    }
}

void parse_time(vector<string> &input, vector<vector<int32_t> > &times){
    int size = input.size();
    for(int i=0; i<size; ++i){
        string time = input[i];
        string day = time.substr(3,2);
        string hour = time.substr(6,2);
        string minute = time.substr(9,2);
        string second = time.substr(12,2);

        int32_t time_from_start = str2int(day) * 24 * 3600 + str2int(hour) * 3600 + str2int(minute) * 60 + str2int(second) - OFFSET;
        times[time_from_start/ONE_DAY].push_back(time_from_start);

    }
}

int main(){
    freopen("2.txt", "r", stdin);
    int total;
    cin >> total;
    //vector<string> input(total);
    vector<vector<int32_t> > times(31, vector<int32_t>());
    for(int i=0; i<total; ++i){
        string day_first, day_second;
        cin >> day_first >> day_second;
        string time = day_first + "-" + day_second; //08.10-01:00:00
        //input[i] = tmp;string time = input[i];
        string day = time.substr(3,2);
        string hour = time.substr(6,2);
        string minute = time.substr(9,2);
        string second = time.substr(12,2);

        int32_t time_from_start = str2int(day) * 24 * 3600 + str2int(hour) * 3600 + str2int(minute) * 60 + str2int(second) - OFFSET;
        times[time_from_start/ONE_DAY].push_back(time_from_start);

    }

    work(times);
}
