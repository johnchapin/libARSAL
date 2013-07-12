/**
 * @file libARSAL/ARSAL_Time.h
 * @brief This file contains headers about time abstraction layer
 * @date 05/18/2012
 * @author frederic.dhaeyer@parrot.com
 */
#ifndef _ARSAL_TIME_H_
#define _ARSAL_TIME_H_
#include <inttypes.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>

#ifndef TIMEVAL_TO_TIMESPEC
/**
 * @brief Convert timeval structure to timespec structure
 */
#define TIMEVAL_TO_TIMESPEC(tv, ts)             \
    do                                          \
    {                                           \
        (ts)->tv_sec = (tv)->tv_sec;            \
        (ts)->tv_nsec = (tv)->tv_usec * 1000;   \
    } while(0)
#endif

#ifndef TIMESPEC_TO_TIMEVAL
/**
 * @brief Convert timespec structure to timeval structure
 */
#define TIMESPEC_TO_TIMEVAL(ts, tv)             \
    do                                          \
    {                                           \
        (tv)->tv_sec = (ts)->tv_sec;            \
        (tv)->tv_usec = (ts)->tv_nsec / 1000;   \
    } while(0)
#endif

/**
 * @brief Checks the equality of two timeval
 *
 * @param t1 First time to compare
 * @param t2 Second time to compare
 *
 * @return 1 if t1 and t2 represent the same value
 * @return 0 in all other cases
 */
int ARSAL_Time_TimevalEquals (struct timeval *t1, struct timeval *t2);

/**
 * @brief Computes the difference between two timeval
 *
 * This function returns the time, in miliseconds, between the two
 * given timevals.
 *
 * @param start Start of the time interval to compute
 * @param end End of the time interval to compute
 * @return The number of ms between the two timeval. A negative number is an error
 * @warning Make sure that "end" is after "start"
 */
int32_t ARSAL_Time_ComputeMsTimeDiff (struct timeval *start, struct timeval *end);

#if 0 // Disable Doxygen comment while function is not implemented
/**
 * @brief Get the time as well as a timezone.
 *
 * @param tv The timeval structure pointer
 * @param tz The timezone structure pointer
 * @retval On success, sal_gettimeofday() returns 0. Otherwise returns -1 (in which case errno is set apprpriately).
 */
// int gettimeofday(struct timeval *tv, struct timezone *tz);
#endif // 0

#endif // _ARSAL_TIME_H_