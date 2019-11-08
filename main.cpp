#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include "Course.hpp"


using namespace std;

/*
 * print schedule - outputs course schedule to the screen
 * @param - add any new parameters you need
 */
void printSchedule(vector<Course> cMap)
{
    std::copy(cMap.begin(), cMap.end(), std::ostream_iterator<Course>(cout, "\n"));
}
void checkConflict(vector<Course> cMap){
    vector<Course>::iterator i;
    vector<Course>::iterator j;

    for (i = cMap.begin(); i < cMap.end(); i++){
        for (j = i + 1; j < cMap.end(); j++){
            if(!(*i == *j)){
                if(i->getDay() == j->getDay()){
                    if(j->getStart_time() <= i->getFinish_time()){
                        cout << "CONFLICT " << *i << " " << *j << endl;
                    }
                }
            }
        }
    }
}
int main () {
    ifstream file;
    file.open ("../courses.txt");


    vector<Course> courseMap;
    string title = "";
    char dayC = ' ';
    Course:: dayOfWeek day = Course::MON;
    unsigned int start_time;
    unsigned int finish_time;

    if (file.is_open())
    {
        while ( file >> title >> dayC >> start_time >> finish_time)
        {
            switch (dayC){
                case 'M' :
                    day = Course::MON;
                    break;
                case 'T' :
                    day = Course::TUE;
                    break;
                case 'W' :
                    day = Course::WED;
                    break;
                case 'R' :
                    day = Course::THUR;
                    break;
                case 'F' :
                    day = Course::FRI;
                    break;
            }
            Course c(title, day, start_time, finish_time);
            courseMap.insert(courseMap.end(), c);
        }
        file.close();
    }
    sort(courseMap.begin(), courseMap.end());
    checkConflict(courseMap);
    printSchedule(courseMap);
    return 0;
}
