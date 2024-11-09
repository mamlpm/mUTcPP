#ifndef mUTcPP_h
#define mUTcPP_h
#include <iostream>
#include <vector>
using namespace std;
class mUTcPP 
{
    public:
        typedef bool (*testingFunction)();
        mUTcPP(int* pointerToFunctionArray);
    private:
        vector<testingFunction> functionsToTest_;
};
#endif