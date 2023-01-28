#include "../include/current_time.h"

void Current_time(CurrentTime &currentTime){
    std::chrono::microseconds ms = std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::system_clock::now().time_since_epoch()
            );
        currentTime.mksek = ms.count() % 1000;
        currentTime.msec = ((ms.count() - currentTime.mksek) / 1000) %1000;
        currentTime.sec = ((ms.count() - currentTime.mksek - currentTime.msec * 1000) / (1000 * 1000)) % 60;
        currentTime.min = ((ms.count() - currentTime.mksek - currentTime.msec * 1000 - currentTime.sec * 1000000) / (1000 * 1000 * 60)) % 60;
        currentTime.hour = ((ms.count() - currentTime.mksek - currentTime.msec * long long(1000) - currentTime.sec * long long(1000000) - currentTime.min * (long long(1000) * long long(1000) * long long(60))) / (long long(1000) * long long(1000) * long long(60) * long long(60))) % 24;
}
