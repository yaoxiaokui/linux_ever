/*************************************************************************
	> File Name: practice_5.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016�?2�?4�?星期�?13�?5�?2�?
 ************************************************************************/
/*
求下面数据类型的最大值和最小值是什�?
char, short, int, long, float, double, long double, unsigned
*/

#include <iostream>
#include <limits>
#include <climits>
using namespace std;

int main()
{
    cout << "char max = " << int(numeric_limits<char>::max()) << endl;
    cout << "char min = " << int(numeric_limits<char>::min()) << endl;

    //cout << "char max = " << CHAR_MAX << endl;
    //cout << "char min= " << CHAR_MIN << endl;

    cout << "short max = " << numeric_limits<short>::max() << endl;
    cout << "short min = " << numeric_limits<short>::min() << endl;

    cout << "int max = " << numeric_limits<int>::max() << endl;
    cout << "int min = " << numeric_limits<int>::min() << endl;

    cout << "long max = " << numeric_limits<long>::max() << endl;
    cout << "long min = " << numeric_limits<long>::min() << endl;

    cout << "float max = " << numeric_limits<float>::max() << endl;
    cout << "float min = " << numeric_limits<float>::min() << endl;

    cout << "double max = " << numeric_limits<double>::max() << endl;
    cout << "double min = " << numeric_limits<double>::min() << endl;

    cout << "long double max = " << numeric_limits<long double>::max() << endl;
    cout << "long double min = " << numeric_limits<long double>::min() << endl;

    cout << "unsigned max = " << numeric_limits<unsigned>::max() << endl;
    cout << "unsigned min = " << numeric_limits<unsigned>::min() << endl;

    return 0;
}
