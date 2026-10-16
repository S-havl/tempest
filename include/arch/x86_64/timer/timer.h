#pragma once

#include <stdint.h>

static inline __attribute__((always_inline)) uint64_t start_timer_rdtsc(void)
{
    uint32_t high_order_part_timestamp_counter_value;
    uint32_t low_order_part_timestamp_counter_value;

    __asm__ __volatile__("rdtsc \n\t"
                         : "=d"(high_order_part_timestamp_counter_value),
                           "=a"(low_order_part_timestamp_counter_value)
                         :
                         : "rbx", "rcx", "memory");

    uint64_t full_timestamp_counter_value =
        ((uint64_t)high_order_part_timestamp_counter_value << 32) |
        low_order_part_timestamp_counter_value;

    return full_timestamp_counter_value;
}

typedef struct {
    uint64_t rdtscp_full_timestamp_counter_value;
    uint32_t rdtscp_tsc_aux;
} rdtscp_result_t;

static inline __attribute__((always_inline)) rdtscp_result_t stop_timer_rdtscp(void)
{
    uint32_t high_order_part_timestamp_counter_value;
    uint32_t low_order_part_timestamp_counter_value;
    uint32_t tsc_aux;

    __asm__ __volatile__("rdtscp \n\t"
                         : "=d"(high_order_part_timestamp_counter_value),
                           "=a"(low_order_part_timestamp_counter_value), "=c"(tsc_aux)
                         :
                         : "memory");

    uint64_t full_timestamp_counter_value =
        ((uint64_t)high_order_part_timestamp_counter_value << 32) |
        low_order_part_timestamp_counter_value;

    rdtscp_result_t results;
    results.rdtscp_full_timestamp_counter_value = full_timestamp_counter_value;
    results.rdtscp_tsc_aux                      = tsc_aux;

    return results;
}
