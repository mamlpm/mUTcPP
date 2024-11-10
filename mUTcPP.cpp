#include "mUTcPP.h"

template <typename T>
mUTcPP<T>::mUTcPP(vector<inputData> parsedVector) : functionsToTest_(parsedVector) {}
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
bool mUTcPP<T>::checkFloatVectors(vector<float> expected, vector<float> result, bool inequality)
{
    if (!inequality)
    {
        if (expected.size() != result.size())
        {
            return false;
        }
        for (size_t i = 0; i < expected.size(); ++i)
        {
            if (fabs(expected[i] - result[i]) >= 1e-5)
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        if (expected.size() != result.size())
        {
            return true;
        }
        for (size_t i = 0; i < expected.size(); ++i)
        {
            if (fabs(expected[i] - result[i]) >= 1e-5)
            {
                return true;
            }
        }
        return false;
    }
}

template <>
bool mUTcPP<vector<float>>::checkEquality(vector<float> expectedValue, vector<float> computedValue)
{
    return checkFloatVectors(expectedValue, computedValue, false);
}
template <>
bool mUTcPP<vectorOperations>::checkEquality(vectorOperations expectedValue, vectorOperations computedValue)
{
    return checkFloatVectors(expectedValue.returnVector(vectorOperations::CARTESIANO), computedValue.returnVector(vectorOperations::CARTESIANO), false) &&
           checkFloatVectors(expectedValue.returnVector(vectorOperations::POLAR), computedValue.returnVector(vectorOperations::POLAR), false);
}
template <typename T>
bool mUTcPP<T>::checkEquality(T expectedValue, T computedValue) { return expectedValue == computedValue; }

template <>
bool mUTcPP<vector<float>>::checkInEquality(vector<float> expectedValue, vector<float> computedValue)
{
    return checkFloatVectors(expectedValue, computedValue, true);
}
template <>
bool mUTcPP<vectorOperations>::checkInEquality(vectorOperations expectedValue, vectorOperations computedValue)
{
    return checkFloatVectors(expectedValue.returnVector(vectorOperations::CARTESIANO), computedValue.returnVector(vectorOperations::CARTESIANO), true) &&
           checkFloatVectors(expectedValue.returnVector(vectorOperations::POLAR), computedValue.returnVector(vectorOperations::POLAR), true);
}
template <typename T>
bool mUTcPP<T>::checkInEquality(T expectedValue, T computedValue) { return expectedValue == computedValue; }

template <typename T>
void mUTcPP<T>::checkIfFunctionWorks(inputData functionSpec)
{
    writeMessage(message, "Comprobando la función: " + functionSpec.strFunctionName + " con los parámetros: ");
    for (string param : functionSpec.params)
    {
        writeMessage(message, param);
        writeMessage(message, "; ");
    }
    writeMessage(message, functionSpec.fail ? "Alimentando resultados esperados erróneos " : "Alimentando resultados esperados correctos ");

    T result = functionSpec.functionName();
    if (functionSpec.fail ? checkInEquality(result, functionSpec.expectedValue) : checkEquality(result, functionSpec.expectedValue))
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
template class mUTcPP<vector<float>>;
template class mUTcPP<double>;
template class mUTcPP<vectorOperations>;