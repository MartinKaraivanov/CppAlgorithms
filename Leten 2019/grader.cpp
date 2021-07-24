#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
//#include<random>
#include "corridor.h"
#include "corridor.cpp"
using namespace std;

/// provided by the solution
////step solve(char cellValue);

const static int MAX_TESTS = 5;
const static int REPETITION = 5;
const static int MAX_N = 200;
const static int MAX_STEPS = 42000;
const static int MAX_SETS = 84000;

/// State of the test runs
static char corridors[REPETITION][MAX_TESTS][MAX_N + 1];
static int corridorLength[MAX_TESTS];
static int corridorPosition[REPETITION][MAX_TESTS];
static bool runComplete[REPETITION][MAX_TESTS];
static int TEST_MAX_STEPS;

namespace {
    int maxSteps(int n) {
        return TEST_MAX_STEPS;
    }

    int maxSets(int n) {
        return 2*TEST_MAX_STEPS;
    }
}

/// Memory exposed to the solution via get/set
const static int MEM_LIMIT = 5;
static int solutionMemory[REPETITION][MAX_TESTS][MEM_LIMIT];

static int stepsMadeCount[REPETITION][MAX_TESTS];
static step stepHistory[MAX_TESTS][MAX_STEPS+10];

static int setsMadeCount[REPETITION][MAX_TESTS];
static pair<int, int> setHistory[MAX_TESTS][MAX_SETS]; /// {index, value}

static int currRunningTest, currRepetition;
static bool setHistoryDifference;
static bool setLimitExceeded;

void set_memory(int index, int value) {
    if(setsMadeCount[currRepetition][currRunningTest] == maxSets(corridorLength[currRunningTest])) {
        setLimitExceeded = true;
        return;
    }

    if(index < MEM_LIMIT && index >= 0) {
        int currSet = setsMadeCount[currRepetition][currRunningTest];

        if (setHistory[currRunningTest][currSet].first == -1) {
            setHistory[currRunningTest][currSet] = {index, value};
        }
        else if (setHistory[currRunningTest][currSet] != make_pair(index, value)) {
            setHistoryDifference = true;
        }

        setsMadeCount[currRepetition][currRunningTest]++;
        solutionMemory[currRepetition][currRunningTest][index] = value;
    }
}

int get_memory(int index) {
    if(index < MEM_LIMIT && index >= 0) {
        return solutionMemory[currRepetition][currRunningTest][index];
    }
    else {
        return 0;
    }
}

namespace {
    struct test {
        int testRepetition;
        int testNumber;
    };
}

static test testing[REPETITION * MAX_TESTS * (MAX_STEPS+10)];
static int testingLength;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> TEST_MAX_STEPS;
    int numberOfTests;
    cin >> numberOfTests;

    for(int i = 0; i < numberOfTests; ++i) {
        cin >> corridors[0][i];

        for(int j = 1; j < REPETITION; ++j) {
            strcpy(corridors[j][i], corridors[0][i]);
        }

        corridorLength[i] = strlen(corridors[0][i]);
    }

    for(int cnt = 0; cnt < REPETITION; ++cnt) {
        for(int i = 0; i < numberOfTests; ++i) {
            for(int j = 0; j < maxSteps(corridorLength[i]) + 10; ++j) {
                testing[testingLength++] = {cnt, i};
            }
        }
    }

    srand(0);
    random_shuffle(testing, testing + testingLength);
    // shuffle(testing, testing + testingLength, default_random_engine(0));

    for (int i = 0; i < MAX_TESTS; ++i) {
        for (int j = 0; j < MAX_SETS; ++j) {
            setHistory[i][j] = {-1, 0};
        }
    }

    for(int i = 0; i < MAX_TESTS; ++i) {
        for(int j = 0; j < (MAX_STEPS+10); ++j) {
            stepHistory[i][j] = {0, 0};
        }
    }

    for(int i = 0; i < testingLength; ++i) {
        currRepetition = testing[i].testRepetition;
        currRunningTest = testing[i].testNumber;

        if(runComplete[currRepetition][currRunningTest]) {
            continue;
        }

        /// check if the current running test makes too many steps
        if(stepsMadeCount[currRepetition][currRunningTest] == maxSteps(corridorLength[currRunningTest])) {
            cout << 0 << endl;
            return 0;
        }

        /// make a call to the solution
        step stepMade
            = solve(corridors[currRepetition][currRunningTest][corridorPosition[currRepetition][currRunningTest]]);

        if(setHistoryDifference) {
            cout << -1 << endl;
            return 0;
        }

        if(setLimitExceeded) {
            cout << -2 << endl;
            return 0;
        }

        /// move left
        if(stepMade.action == 'l') {
            /// loop back around if needed
            if(corridorPosition[currRepetition][currRunningTest] == 0) {
                corridorPosition[currRepetition][currRunningTest]
                    = corridorLength[currRunningTest] - 1;
            }
            else {
                --corridorPosition[currRepetition][currRunningTest];
            }
        }
        /// move right
        else if(stepMade.action == 'r') {
            /// loop back around if needed
            if(corridorPosition[currRepetition][currRunningTest] == corridorLength[currRunningTest] - 1) {
                corridorPosition[currRepetition][currRunningTest] = 0;
            }
            else {
                ++corridorPosition[currRepetition][currRunningTest];
            }
        }
        /// toggle current cell value
        else if(stepMade.action == 't') {
            corridors[currRepetition][currRunningTest][corridorPosition[currRepetition][currRunningTest]]
                = (corridors[currRepetition][currRunningTest][corridorPosition[currRepetition][currRunningTest]] == '0' ? '1' : '0');
        }
        /// guess answer
        else if(stepMade.action == 'a') {
            /// correct
            if(stepMade.answer == corridorLength[currRunningTest]) {
                runComplete[currRepetition][currRunningTest] = true;
            }
            /// wrong
            else {
                cout << -3 << endl;
                return 0;
            }
        }
        else {
            cout << -4 << endl;
            return 0;
        }

        /// check step history
        int currStepNumber = stepsMadeCount[currRepetition][currRunningTest];
        if (stepHistory[currRunningTest][currStepNumber].action == 0) {
            stepHistory[currRunningTest][currStepNumber] = stepMade;
        }
        else if (stepHistory[currRunningTest][currStepNumber].action != stepMade.action) {
            cout << -5 << endl;
            return 0;
        }

        ++stepsMadeCount[currRepetition][currRunningTest];
    }

    /// check if all repetitions of a test do the same number of steps
    for(int i = 1; i < REPETITION; ++i) {
        for(int j = 0; j < numberOfTests; ++j) {
            if(stepsMadeCount[i][j] != stepsMadeCount[0][j]) {
                cout << -5 << endl;
                return 0;
            }
        }
    }

    /// check if all repetitions of a test call set_memory the same number of times
    for(int i = 1; i < REPETITION; ++i) {
        for(int j = 0; j < numberOfTests; ++j) {
            if(setsMadeCount[i][j] != setsMadeCount[0][j]) {
                cout << -6 << endl;
                return 0;
            }
        }
    }

    /// check if all tests have an answer
    for(int i = 0; i < REPETITION; ++i) {
        for(int j = 0; j < numberOfTests; ++j) {
            if(!runComplete[i][j]) {
                cout << -7 << endl;
                return 0;
            }
        }
    }

    long long int hashCode=0;
    const long long mod=1e9+7;
    for (int i=0; i<numberOfTests; i++) {
        hashCode=(hashCode*3301+corridorLength[i])%mod;
        }
    cout << ((hashCode*685008889LL)+874362901LL)%mod+1 << endl ;
    return 0;
}
