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
    mUTcPP(vector<testingFunction> parsedVector);
    enum messageType
    {
        message = 0,
        error = 31,
        success = 32
    };
    // TODO
    bool checkIfFunctionWorks(testingFunction functionPointer, T expectedValue);
    void writeMessage(messageType messageT, string message);

private:
    static void setTerminal(int colour);
    vector<testingFunction> functionsToTest_;
};
#endif