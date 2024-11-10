#ifndef mUTcPP_h
#define mUTcPP_h
#include <iostream>
#include <vector>
#include <string>
using namespace std;
template <typename T>
class mUTcPP
{
public:
    using testingFunction = T (*)();
    typedef struct inputData
    {
        testingFunction functionName;
        string strFunctionName;
        vector<string> params;
        string overRideSpec;
        T expectedValue;
    };
    
    mUTcPP(vector<inputData> parsedVector);
    enum messageType
    {
        message = 0,
        error = 31,
        success = 32
    };
    // TODO
    void runAllFunctions();
    

private:
    static void setTerminal(int colour);
    vector<inputData> functionsToTest_;
    void checkIfFunctionWorks(inputData functionPointer);
    void writeMessage(messageType messageT, string message);
};
#endif