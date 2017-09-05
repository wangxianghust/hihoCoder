/*
中国历史上曾出现过多次诸侯割据的时期，诸侯之间通过各种方式派出间谍来刺探军情，留下了许多惊心动魄的谍战故事，其中有一个是这样的：A国在B国安插了多名间谍，有一次这些间谍刺探到B国将在T时间攻打A国，如果A国不做防备则A国必败；如果A国能提前埋伏则A国必胜，所以A国的间谍需要在T之前将情报安全的送回A国。为了避免情报被B国截获而取消攻打计划：A国的间谍采用了一种特殊的编码算法，会将情报编码在m份数据中，只有同时拿到至少任意的n份数才能解码出情报；这m份数据会由m个间谍分别送出，避免同时被B国捕获。由于输送情报的过程中要躲避B国的随机检查，输送情报的时间是不固定的，A国间谍已经将之前情报的输送时间都记录下来。A国间谍需要估算出A国拿到完整情报时间的期望值。
注：为了简单起见，m个间谍都会成功的把各自的情报送回A国；所耗费的时间是独立的。
概念抽象：A国间谍记录的情报输送时间的情况：会记录每个时间总共出现的次数，以Point结构表示：
struct Point
{
    int value; // 情报输送时间
    int num; // value出现过的次数。
    double ratio; // value在所有情报输送占的概率。
};


编译器版本: gcc 4.8.4
请使用标准输入输出(stdin，stdout) ；请把所有程序写在一个文件里，勿使用已禁用图形、文件、网络、系统相关的头文件和操作，如sys/stat.h , unistd.h , curl/curl.h , process.h
时间限制: 3S (C/C++以外的语言为: 5 S)   内存限制: 128M (C/C++以外的语言为: 640 M)
输入:
输入总共分三部分： 1.m n 2.Point个数 3.每个Point中value 和 num的值
输出:
A国拿到完整情报的时间期望值。 以浮点数表示，精确到小数点后6位，不足6位补零。
输入范例:
1 1
1
1 2
输出范例:
1.000000
*/


#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Point
{
    int value;
    int num;
    double ratio;
};

void input(vector<Point>* points);

double calculateExpectation(const vector<Point>& points, const int total, const int min);
int main()
{
    int total = 0;
    cin >> total;
    int min = 0;
    cin >> min;

    vector<Point> points;
    input(&points);

    double res = calculateExpectation(points, total, min);
    cout << setiosflags(ios::fixed) << setprecision(6) << res << endl;                                                                                                                                                                                          
    return 0;
}

void input(vector<Point>* points)
{
    int n = 0;
    cin >> n;
    points->resize(n);

    double sum = 0;
    for (int i = 0; i < n; ++i)
    {   
        Point& point = (*points)[i];
        cin >> point.value;
        cin >> point.num;
        sum += point.num;
    }

    for (int i = 0; i < n; ++i)
    {   
        Point& point = (*points)[i];
        point.ratio = point.num / sum;
    }
}

static bool cmp(Point& a, Point& b){
    return a.value < b.value;
}

double calculateExpectation(const vector<Point>& points, const int total, const int min)
{
    sort(points.begin(), points.end(), cmp);

}
