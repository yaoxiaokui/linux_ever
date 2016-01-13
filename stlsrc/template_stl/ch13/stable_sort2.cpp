/*************************************************************************
	> File Name: stable_sort.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月11日 星期一 17时09分02秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <cstdlib>
#include <string>
using namespace std;


class job{

    public:
    enum priority_code{standy, normal, high, urgent};
    job(string id, priority_code p = normal): nam(id), pri(p){}
    string name() const { return nam; }
    priority_code priority() const {return pri;}

    private:
        string nam;
        priority_code pri;
};

ostream & operator<<(ostream &os, const job & j)
{
    os << j.name() << " : " << j.priority() << endl;
    return os;
}

bool operator<(const job & j1, const job & j2)
{
    return j1.priority() > j2.priority();
}


int main()
{
    vector<job> jobs;

    jobs.push_back(job("Long computation", job::standy));
    jobs.push_back(job("System reboot", job::urgent));
    jobs.push_back(job("Print"));
    jobs.push_back(job("Another long computation", job::standy));
    jobs.push_back(job("Copy file"));

    cout << "jobs: ";
    cout << endl;
    copy(jobs.begin(), jobs.end(), ostream_iterator<job>(cout, "\n"));
    
    stable_sort(jobs.begin(), jobs.end());

    cout << "**************************sorted jobs*************************: ";
    cout << endl;
    copy(jobs.begin(), jobs.end(), ostream_iterator<job>(cout, "\n"));

    return 0;
}

