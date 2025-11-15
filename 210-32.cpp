// COMSC-210 | Lab 32 | Majd Bohsali
// IDE used: Visual Studio Code
#include <iostream>
#include <ctime> 
#include <cstdlib>
#include <deque> 
#include <array>
#include "Car.h"
using namespace std; 

const int LANE_COUNT = 4; 

void printLane(deque<Car>& boothLine);
void printAllLanes(array<deque<Car>, LANE_COUNT>& plazza);

int main() {
    srand(time(0)); 
    array<deque<Car>, LANE_COUNT> plazza; 

    for (int i = 0; i < LANE_COUNT; i++)
    {
        plazza[i].push_back(Car());
        plazza[i].push_back(Car()); 
    }

    cout << "Inital queue: " << endl; 
    printAllLanes(plazza); 
    cout << endl; 
    
    /*
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
    */
    return 0; 
}

void printAllLanes(array<deque<Car>, LANE_COUNT>& plazza) { 
    for(int i = 0; i < LANE_COUNT; i++) { 
        cout << "Lane: " << i + 1 << endl; 
        printLane(plazza[i]);
    }
}

void printLane(deque<Car>& boothLine) { 
    if(boothLine.empty()) { 
        cout << "    Empty"; 
    } else { 
        for(int i =0; i < boothLine.size(); i++) { 
            cout << "    "; 
            boothLine[i].print(); 
        }
    }
}