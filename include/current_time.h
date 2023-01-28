#include <stdint.h> // uint16_t
#include <chrono>
#include <thread>

struct CurrentTime{
    uint16_t hour;
    uint16_t min;
    uint16_t sec;
    uint16_t msec;
    uint16_t mksek;
};

void Current_time(CurrentTime& currentTime);

