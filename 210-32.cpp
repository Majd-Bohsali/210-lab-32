// COMSC-210 | Lab 32 | Majd Bohsali
// IDE used: Visual Studio Code
#include <iostream>
#include <ctime> 
#include <cstdlib>
#include <deque> 
#include <array>
#include "Car.h"
using namespace std; 

const int LANE_COUNT = 4, EMPTY_LEAVE = 50, LEAVE_PROP = 46, ENTER_PROP = 39; 

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

    for(int timeCount = 0; timeCount < 20; timeCount++) { 
        cout << "Time: " << timeCount + 1 << endl; 

        for(int i = 0; i < LANE_COUNT; i++) { 
            int prop = rand() % 100 + 1; 
            cout << "Lane: " << i + 1 << " "; 
            if(plazza[i].empty()) { 
                if(prop <= EMPTY_LEAVE) { 
                    if(!plazza[i].empty()) { 
                        cout << "Paid: ";
                        plazza[i].front().print(); 
                        plazza[i].pop_front(); 
                    } else {
                        cout << "Empty"; 
                    }
                } else if (prop <= 39) { 
                    cout << "Joined: "; 
                    plazza[i].push_back(Car());
                    plazza[i].back().print();
                }
            } else {
                if(prop <= LEAVE_PROP) { 
                    if(!plazza[i].empty()) { 
                        cout << "Paid: ";
                        plazza[i].front().print(); 
                        plazza[i].pop_front(); 
                    } else {
                        cout << "Empty"; 
                    }
                } else if (prop <= ENTER_PROP) { 
                    cout << "Joined: "; 
                    plazza[i].push_back(Car());
                    plazza[i].back().print();
                } else { 

                }
            }
        }
        printAllLanes(plazza); 
        cout << endl;
    }
    return 0; 
}

void printAllLanes(array<deque<Car>, LANE_COUNT>& plazza) { 
    for(int i = 0; i < LANE_COUNT; i++) { 
        cout << "Lane: " << i + 1 << " Queue:" << endl; 
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