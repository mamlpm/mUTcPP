#ifndef mUTcPP_h
#define mUTcPP_h
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <type_traits>
#include "../arduinoLibraries/vectorOperations/vectorOperations.h"
using namespace std;
template <typename T>
class mUTcPP
{
public:
    using testingFunction = T (*)();
    struct inputData
    {
        testingFunction functionName;
        string strFunctionName;
        vector<string> params;
        T expectedValue;
        bool fail = false;
    };

    mUTcPP(vector<inputData> parsedVector);
    enum messageType
    {
        message = 0,
        error = 31,
        success = 32
    };
    void runAllFunctions();

private:
    static void setTerminal(int colour);
    vector<inputData> functionsToTest_;
    void checkIfFunctionWorks(inputData functionPointer);
    void writeMessage(messageType messageT, string message);
    bool checkEquality(T expectedValue, T computedValue);
    bool checkInEquality(T expectedValue, T computedValue);
    bool checkFloatVectors(vector<float> expected, vector<float> result, bool inequality);
};
#endif