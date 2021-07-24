#include<iostream>
#include<cstring>
#include "corridor.h"
#include "corridor.cpp"
using namespace std;

/// provided by the solution
/////step solve(char cellValue);

const static int MAX_N = 200;
const static int MAX_STEPS = 42000;
const static int MAX_SETS = 84000;

int maxSteps(int n) {
    return 42000;
}

int maxSets(int n) {
    return 84000;
}

/// State of the test runs
static char corridor[MAX_N + 1];
static int corridorLength;
static int corridorPosition;

/// Memory exposed to the solution via get/set
const static int MEM_LIMIT = 5;
static int solutionMemory[MEM_LIMIT];

static int stepsCount;
static int setsCount;
static bool setLimitExceeded;

void set_memory(int index, int value) {
    if(setsCount == maxSets(corridorLength)) {
        setLimitExceeded = true;
        return;
    }

    if(index < MEM_LIMIT && index >= 0) {
        ++setsCount;
        solutionMemory[index] = value;
    }
}

int get_memory(int index) {
    if(index < MEM_LIMIT && index >= 0) {
        return solutionMemory[index];
    }
    else {
        return 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> corridor;
    corridorLength = strlen(corridor);

    while(true) {
        /// check if the solution makes too many steps
        if(stepsCount == maxSteps(corridorLength)) {
            cout << "Step limit exceeded!\n";
            return 0;
        }

        /// make a call to the solution
        step currStep = solve(corridor[corridorPosition]);

        if(setLimitExceeded) {
            cout << "set_memory call limit exceeded!\n";
            return 0;
        }

        /// move left
        if(currStep.action == 'l') {
            /// loop back around if needed
            if(corridorPosition == 0) {
                corridorPosition = corridorLength - 1;
            }
            else {
                --corridorPosition;
            }
        }
        /// move right
        else if(currStep.action == 'r') {
            /// loop back around if needed
            if(corridorPosition == corridorLength - 1) {
                corridorPosition = 0;
            }
            else {
                ++corridorPosition;
            }
        }
        /// toggle current cell value
        else if(currStep.action == 't') {
            corridor[corridorPosition] = (corridor[corridorPosition] == '0' ? '1' : '0');
        }
        /// guess answer
        else if(currStep.action == 'a') {
            /// correct
            if(currStep.answer == corridorLength) {
                cout << "Correct!\n";
                return 0;
            }
            /// wrong
            else {
                cout << "Wrong answer!\n";
                cout << "Answer was: " << corridorLength << "\n";
                cout << "Solution guessed: " << currStep.answer << "\n";
                return 0;
            }
        }
        else {
            cout << "Invalid step!\n";
            return 0;
        }

        ++stepsCount;
    }

    return 0;
}
