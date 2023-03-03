#ifndef TIME_STAMP_H
#define TIME_STAMP_H



#include <iostream>
#include <string>
#include <sys/time.h>

class Timestamp{
public:
    Timestamp()
        :microSecondsSinceEpoch_(0)
        {}

    explicit Timestamp(int64_t microSecondsSinceEpoch)
        :microSecondsSinceEpoch_(microSecondsSinceEpoch)
        {}

    static Timestamp now();

    std::string toString() const;

    std::string toFormattedString(bool showMicroSeconds = false) const;

    int64_t microSecondsSinceEpoch() const{
        return microSecondsSinceEpoch_;
    }

    time_t secondsSinceEpoch() const{
        return static_cast<time_t>(microSecondsSinceEpoch_ / kMicroSecondsPerSecond);
    }

    static Timestamp invalid(){
        return Timestamp();
    }


    static const int kMicroSecondsPerSecond = 1000 * 1000;

private:
    int64_t microSecondsSinceEpoch_;

};


inline bool operator < (const Timestamp& lhs, const Timestamp& rhs){
    return lhs.microSecondsSinceEpoch() < rhs.microSecondsSinceEpoch();
}

inline bool operator > (const Timestamp& lhs, const Timestamp& rhs){
    return lhs.microSecondsSinceEpoch() > rhs.microSecondsSinceEpoch();
}

inline bool operator == (const Timestamp& lhs, const Timestamp& rhs){
    return lhs.microSecondsSinceEpoch() == rhs.microSecondsSinceEpoch();
}


inline Timestamp addTime(Timestamp timestamp, double seconds){
    int64_t delta = static_cast<int64_t>(seconds * Timestamp::kMicroSecondsPerSecond);
    return Timestamp(timestamp.microSecondsSinceEpoch() + delta);
}

#endif // TIME_STAMP_H