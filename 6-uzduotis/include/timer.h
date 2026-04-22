#ifndef TIMER_H
#define TIMER_H

#include <chrono>

class Timer
{
    // usage of using
    using hrClock = std::chrono::high_resolution_clock;
    /// using std::chrono::high_resolution_clock;
    using durationDouble = std::chrono::duration<double>;

private:
    std::chrono::time_point<hrClock> start;

public:
    Timer() : start{hrClock::now()} {}
    void reset()
    {
        start = hrClock::now();
    }
    double elapsed() const
    {
        return durationDouble(hrClock::now() - start).count();
    }
};

#endif