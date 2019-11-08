#include "Course.hpp"

using namespace std;

Course::Course (string title, dayOfWeek day, unsigned int start_time, unsigned int finish_time) : title (title), day (day), start_time (start_time), finish_time (finish_time)
{
}
Course::Course (const Course & m) : title (m.title), day (m.day), start_time (m.start_time), finish_time (m.finish_time)
{
}

Course & Course::operator =(Course m) {
    mySwap(*this, m);
    return *this;
}
void mySwap(Course& m1, Course& m2){
    using std::swap;
    swap(m1.title, m2.title);
    swap(m1.day, m2.day);
    swap(m1.start_time, m2.start_time);
    swap(m1.finish_time, m2.finish_time);
}
bool Course::operator < (const Course & m) const
{
    if(day < m.day){
        return true;
    }
    if(day > m.day){
        return false;
    }
    if(start_time < m.start_time){
        return true;
    }
    if(start_time == m.start_time && finish_time < m.finish_time){
        return true;
    }
    return false;
}
bool Course::operator == (const Course & m) const {
    if(title == m.title && day == m.day && start_time == m.start_time && finish_time == m.finish_time){
        return true;
    }
    return false;
}


ostream & operator << (ostream &os, const Course & m)
{
    os << m.getTitle() << " " << m.getDayString() << " " << m.getStart_time() << " " << m.getFinish_time();
    return os;
}
char Course:: getDayString() const{
    switch(day){
        case dayOfWeek :: MON :
            return 'M';
            break;
        case dayOfWeek :: TUE :
            return 'T';
            break;
        case dayOfWeek :: WED :
            return 'W';
            break;
        case dayOfWeek :: THUR :
            return 'R';
            break;
        case dayOfWeek :: FRI :
            return 'F';
            break;
    }
}
string Course:: getTitle() const{
    return title;
}
Course::dayOfWeek Course:: getDay() const{
    return day;
}
unsigned int Course:: getStart_time() const{
    return start_time;
}
unsigned int Course:: getFinish_time() const{
    return finish_time;
}