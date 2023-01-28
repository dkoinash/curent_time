#include "../include/current_time.h"

void Current_time(CurrentTime &currentTime){
    std::chrono::microseconds ms = std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::system_clock::now().time_since_epoch()
            );
        currentTime.mksek = ms.count() % 1000;
        currentTime.msec = ((ms.count() - currentTime.mksek) / uint64_t(1000)) %1000;
        currentTime.sec = ((ms.count() - currentTime.mksek - currentTime.msec * uint64_t(1000)) / (uint64_t(1000) * uint64_t(1000))) % 60;
        currentTime.min = ((ms.count() - currentTime.mksek - currentTime.msec * uint64_t(1000) - currentTime.sec * uint64_t(1000000)) / (uint64_t(1000) * uint64_t(1000) * uint64_t(60))) % 60;
        currentTime.hour = ((ms.count() - currentTime.mksek - currentTime.msec * uint64_t(1000) - currentTime.sec * uint64_t(1000000) - currentTime.min * (uint64_t(1000) * uint64_t(1000) * uint64_t(60))) / (uint64_t(1000) * uint64_t(1000) * uint64_t(60) * uint64_t(60))) % 24;
}
