#ifndef ___MINIUNIT_H__
#define ___MINIUNIT_H__

#ifdef __cplusplus
extern "C"
{
#endif

#define LOG_MODULE "minunit"
#include "log.h"

/* file: minunit.h */
#define MU_ASSERT(test)              \
    do                               \
    {                                \
        if (!(test))                 \
            LOG_W("(" __FILE__ ":%d" \
                  ":" #test ")\r\n", \
                  __LINE__);         \
    } while (0)

#define MU_RUN(test)                 \
    do                               \
    {                                \
        if (!test())                 \
            LOG_W("(" __FILE__ ":%d" \
                  ":" #test ")\r\n", \
                  __LINE__);         \
    } while (0)

#define MU_ASSERT_EQUALS(a, b)            \
    do                                    \
    {                                     \
        if (a != b)                       \
            LOG_W("(" __FILE__ ":%d"      \
                  ":" #a "==" #b ")\r\n", \
                  __LINE__);              \
    } while (0)

#define MU_ASSERT_VEC_EQUALS(a, b, size)                \
    do                                                  \
    {                                                   \
        for (uint32_t i = 0; i < size; i++)             \
        {                                               \
            if (a[i] != b[i])                           \
                LOG_W("(" __FILE__ ":%d"                \
                      ":" #a "[%lu]==" #b "[%lu])\r\n", \
                      __LINE__, i, i);                  \
        }                                               \
    } while (0)

#define MU_VEC_CLEAR(vec, size)             \
    do                                      \
    {                                       \
        for (uint32_t i = 0; i < size; i++) \
        {                                   \
            vec[i] = 0;                     \
        }                                   \
    } while (0)

#ifdef __cplusplus
}
#endif

#endif // ___MINIUNIT_H__