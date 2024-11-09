#ifndef mUTcPP_h
#define mUTcPP_h
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class mUTcPP
{
public:
    typedef bool (*testingFunction)();
    mUTcPP(vector<testingFunction> parsedVector);
    enum messageType
    {
        message = 0,
        error = 31,
        success = 32
    };
    //TODO
    template <typename T>
    bool checkIfFunctionWorks(testingFunction functionPointer, T expectedValue);
    //TODO
    void setRedTerminal();
    //TODO
    void setGreendTerminal();
    //TODO
    void setDefaultTerminal();
    //TODO
    void writeMessage(messageType messageT, string message);

private:
    vector<testingFunction>
        functionsToTest_;
};
#endif