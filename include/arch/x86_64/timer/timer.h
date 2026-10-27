#pragma once

#include <stdint.h>

static inline __attribute__((always_inline)) uint64_t start_timer_rdtsc(void)
{
    uint32_t high_order_part_timestamp_counter_value;
    uint32_t low_order_part_timestamp_counter_value;

    __asm__ __volatile__("cpuid \n\t"
                         "rdtsc"
                         : "=d"(high_order_part_timestamp_counter_value),
                           "=a"(low_order_part_timestamp_counter_value)
                         : "a"(0)
                         : "rbx", "rcx", "memory");

    uint64_t full_timestamp_counter_value =
        ((uint64_t)high_order_part_timestamp_counter_value << 32) |
        low_order_part_timestamp_counter_value;

    return full_timestamp_counter_value;
}

typedef struct {
    uint64_t rdtscp_full_timestamp_counter_value;
    uint32_t rdtscp_tsc_aux;
} rdtscp_results_t;

static inline __attribute__((always_inline)) rdtscp_results_t stop_timer_rdtscp(void)
{
    uint32_t high_order_part_timestamp_counter_value;
    uint32_t low_order_part_timestamp_counter_value;
    uint32_t tsc_aux;

    __asm__ __volatile__("rdtscp"
                         : "=d"(high_order_part_timestamp_counter_value),
                           "=a"(low_order_part_timestamp_counter_value), "=c"(tsc_aux)
                         :
                         : "memory");

    uint64_t full_timestamp_counter_value =
        ((uint64_t)high_order_part_timestamp_counter_value << 32) |
        low_order_part_timestamp_counter_value;

    rdtscp_results_t results;
    results.rdtscp_full_timestamp_counter_value = full_timestamp_counter_value;
    results.rdtscp_tsc_aux                      = tsc_aux;

    return results;
}

static inline __attribute__((always_inline)) void
move_non_temporal_hint_movnti_instruction(uint64_t* memory_address, uint64_t value)
{
    __asm__ __volatile__("movntiq %[value], (%[memory_address])"
                         :
                         : [memory_address] "r"(memory_address), [value] "r"(value)
                         : "memory");
}

static inline __attribute__((always_inline)) void
cache_line_flush_optimized_clflushopt_instruction(const void* memory_address)
{
    __asm__ __volatile__("clflushopt (%[memory_address])"
                         :
                         : [memory_address] "r"(memory_address)
                         : "memory");
}

static inline __attribute__((always_inline)) void store_fence_sfence_instruction(void)
{
    __asm__ __volatile__("sfence" : : : "memory");
}

static inline __attribute__((always_inline)) void load_fence_lfence_instruction(void)
{
    __asm__ __volatile__("lfence" : : : "memory");
}
