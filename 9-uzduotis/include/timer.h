#ifndef TIMER_H
#define TIMER_H

#include <chrono>

/**
 * @file timer.h
 * @brief Laiko matavimo klases aprasymas.
 */

/**
 * @class Timer
 * @brief Klase, skirta programos vykdymo laikui matuoti.
 */

class Timer
{
    // usage of using
    using hrClock = std::chrono::high_resolution_clock;
    /// using std::chrono::high_resolution_clock;
    using durationDouble = std::chrono::duration<double>;

private:
    std::chrono::time_point<hrClock> start; /**< Laiko taskas, nuo kurio matuojamas laikas */

public:
    /**
     * @brief Sukria laikmati ir pradeda laiko matavima
     */
    Timer() : start{hrClock::now()} {}
    /**
     * @brief Atnaujina laikmati
     */
    void reset()
    {
        start = hrClock::now();
    }
    /**
     * @brief Grazina kiek laiko praejo
     * @return Praeitas laikas
     */
    double elapsed() const
    {
        return durationDouble(hrClock::now() - start).count();
    }
};

#endif