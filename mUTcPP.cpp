#include "mUTcPP.h"

template <typename T>
mUTcPP<T>::mUTcPP(vector<inputData> parsedVector)
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
void mUTcPP<T>::checkIfFunctionWorks(inputData functionSpec)
{
    writeMessage(message, "Comprobando la función: " + funcionSpec.strFunctionName);
    T result = funcionSpec.functionName();
    if (result == functionSpec.expectedValue)
    {
        writeMessage(success, "Done\n");
    }
    else
    {
        writeMessage(error, "Error\n");
    }
}
template <typename T>
void mUTcPP<T>::runAllFunctions()
{
    for (inputData functionToTest : functionsToTest_)
    {
        checkIfFunctionWorks(functionToTest);
    }
}

template class mUTcPP<bool>;
template class mUTcPP<int>;
template class mUTcPP<float>;
template class mUTcPP<double>;