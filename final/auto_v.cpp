#include <iostream>
#include "auto_v.h"
class auto_v {
    public:
        int numPassengers;
        int safetyScore;
        auto_v() {

        }
        auto_v(int n, int s) {
            numPassengers = n;
            safetyScore = s;
        }

        void setPassengers(int n) {
            numPassengers = n;
        }
        void setScore(int s) {
            safetyScore = s;
        }
        int getPassengers() {
            return numPassengers;
        }
        int getScore() {
            return safetyScore;
        }
        void printInfo() {
            std::cout << "passengers:" << numPassengers << "safety score:" << safetyScore << "\n";

        }

        
};