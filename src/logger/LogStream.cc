#include <algorithm>
#include "LogStream.h"

static const char digits[] = {'9', '8', '7', '6', '5', '4', '3', '2', '1', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

template<typename T>
void LogStream::formatInteger(T num){
    if(buffer.avail() >= kMax)
}