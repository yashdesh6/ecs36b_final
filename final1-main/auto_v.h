#ifndef AUTO_V_H
#define AUTO_V_H

#include <iostream>
#include <json/json.h>
#include <json/reader.h>
#include <json/writer.h>
#include <json/value.h>
#include <string>
class auto_v {
    private:
    protected:
    public:
        int numPassengers;
        double safetyScore;
        double avgAge;
        auto_v();
        auto_v(int n, double s);
        void setPassengers(int n);
        void setScore(double s);
        void setAge(double a);
        int getPassengers();
        int getScore();
        int getAge();
        void printInfo();
        auto_v chooseCrash(auto_v av1, auto_v av2);
        Json::Value dump2JSON();
        void JSON2Object(Json::Value); 
        

};
#endif