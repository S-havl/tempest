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
                         :);

    uint64_t full_timestamp_counter_value =
        ((uint64_t)high_order_part_timestamp_counter_value << 32) |
        low_order_part_timestamp_counter_value;

    return full_timestamp_counter_value;
}

static inline __attribute__((always_inline)) void stop_timer_rdtscp(void)
{
    __asm__ __volatile__("rdtscp \n\t");
}
