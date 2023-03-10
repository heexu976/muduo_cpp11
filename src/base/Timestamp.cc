#include "Timestamp.h"


Timestamp Timestamp::now(){
    struct timeval tv;
    gettimeofday(&tv, NULL);
    int64_t second = tv.tv_sec;
    return Timestamp(second * Timestamp::kMicroSecondsPerSecond);
}


std::string Timestamp::toFormattedString(bool showMicroSeconds) const{
    char buf[64] = {0};
    time_t seconds = static_cast<time_t>(microSecondsSinceEpoch_ / kMicroSecondsPerSecond);
    tm *tm_time = localtime(&seconds);
    if (showMicroSeconds){
        int microseconds = static_cast<int>(microSecondsSinceEpoch_ % kMicroSecondsPerSecond);
        snprintf(buf, sizeof(buf), "%4d/%02d/%02d %02d:%02d:%02d.%06d",
                tm_time->tm_year + 1900,
                tm_time->tm_mon + 1,
                tm_time->tm_mday,
                tm_time->tm_hour,
                tm_time->tm_min,
                tm_time->tm_sec,
                microseconds);
    }
    else{
        snprintf(buf, sizeof(buf), "%4d/%02d/%02d %02d:%02d:%02d",
                tm_time->tm_year + 1900,
                tm_time->tm_mon + 1,
                tm_time->tm_mday,
                tm_time->tm_hour,
                tm_time->tm_min,
                tm_time->tm_sec);
    }
    return buf;
}

int main(){
    Timestamp timestamp;
    std::cout << timestamp.now().toFormattedString() << std::endl;
}