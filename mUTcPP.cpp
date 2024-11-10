#include "mUTcPP.h"

template <typename T>
mUTcPP<T>::mUTcPP(vector<testingFunction> parsedVector)
{
    functionsToTest_ = parsedVector;
}
template <typename T>
void mUTcPP<T>::setTerminal(int colour)
{
    cout << "\033[" << colour << "m";
}
template <typename T>
void mUTcPP<T>::writeMessage(messageType messageT, string message)
{
    setTerminal(messageT);
    cout << message;
    setTerminal(messageType::message);
}

template <typename T>
bool mUTcPP<T>::checkIfFunctionWorks(testingFunction functionPointer, T expectedValue) {
    T result = functionPointer();
    return result == expectedValue;
}

template class mUTcPP<bool>;
template class mUTcPP<int>;
template class mUTcPP<float>;
template class mUTcPP<double>;