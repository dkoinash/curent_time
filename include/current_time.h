#include <stdint.h> // uint16_t
#include <chrono>
#include <thread>

struct CurrentTime{
    uint16_t hour;
    uint16_t min;
    uint16_t sec;
    uint16_t msec;
    uint16_t mksec;
};

void Current_time_1(CurrentTime& currentTime);

void Current_time_2(uint16_t &hour, uint16_t &min, uint16_t &sec, uint16_t &minisec, uint16_t &microsec);

void
Current_time_3(uint16_t& hour, uint16_t& min, uint16_t& sec, uint16_t& minisec, uint16_t& microsec, uint16_t timeZone);
