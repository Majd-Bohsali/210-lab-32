// COMSC-210 | Lab 32 | Majd Bohsali
// IDE used: Visual Studio Code
#include <iostream>
#include <ctime> 
#include <cstdlib>
#include <deque> 
#include "Car.h"
using namespace std; 

void printDeque(deque<Car>& boothLine);

int main() {
    srand(time(0)); 
    deque<Car> boothLine; 

    Car car1, car2; 
    boothLine.push_back(car1); 
    boothLine.push_back(car2);

    cout << "Inital queue:" << endl; 
    printDeque(boothLine); 
    cout << endl;
   
    int timeCount = 1; 
    while(!boothLine.empty()) { 
        int prop = rand() % 100 + 1; 
        cout << "Time: " << timeCount << " Operation: "; 
        if(prop <= 55) { 
            cout << "Car paid: "; 
            boothLine.front().print(); 
            boothLine.pop_front();
        } else {
            Car newCar; 
            boothLine.push_back(newCar);
            cout << "Joined lane: ";
            boothLine.back().print();  
        }

        cout << "Queue" << endl; 
        printDeque(boothLine); 
        cout << endl;
        timeCount++; 
    }

    return 0; 
}

void printDeque(deque<Car>& boothLine) { 
    if(boothLine.empty()) { 
        cout << "    Empty"; 
    } else { 
        for(int i =0; i < boothLine.size(); i++) { 
            cout << "    "; 
            boothLine[i].print(); 
        }
    }
}