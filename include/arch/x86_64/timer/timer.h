#pragma once

static inline __attribute__((always_inline)) void start_timer_rdtsc(void)
{
    __asm__ __volatile__("rdtsc \n\t");
}

static inline __attribute__((always_inline)) void stop_timer_rdtscp(void)
{
    __asm__ __volatile__("rdtscp \n\t");
}
