#define _GNU_SOURCE
#include <arch/x86_64/timer/timer.h>

#include <sched.h>

#include <stdio.h>
#include <unistd.h>

int activate_cpu_affinity(void)
{
    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    CPU_SET(7, &cpuset);

    return sched_setaffinity(0, sizeof(cpuset), &cpuset);
}

void test_algorithm(void) { printf("Hello World\n"); }

int main(void)
{
    int              ret = 0;
    uint64_t         previous_time_calculation;
    rdtscp_results_t subsequent_time_calculation;
    uint64_t         result_diference;

    if (activate_cpu_affinity() == -1) {
        printf("CPU affinity activation failed.\n");
        perror("sched_affinity");

        ret = 1;
    }

    printf("\033[H\033[38;2;0;255;0mCPU affinity activation successful: core 7\n\033[0m");

    // timer test
    previous_time_calculation = start_timer_rdtsc();

    test_algorithm();

    subsequent_time_calculation = stop_timer_rdtscp();
    result_diference =
        subsequent_time_calculation.rdtscp_full_timestamp_counter_value - previous_time_calculation;

    printf("\033[38;2;255;0;0m========== Timer Results ==========\n\033[0m");
    printf("\033[38;2;0;0;255mPrevious time calculation: %llu\n\033[0m", previous_time_calculation);
    printf("\033[38;2;255;0;0m\nSubsequent time calculation:\n\033[0m");
    printf("\033[38;2;0;0;255mCounter value = %llu\n\033[0m",
           subsequent_time_calculation.rdtscp_full_timestamp_counter_value);
    printf("\033[38;2;0;0;255mTSC AUX Value = %u\n\033[0m",
           subsequent_time_calculation.rdtscp_tsc_aux);

    printf("\033[38;2;0;255;0m\nResult diference = %llu\n\033[0m", result_diference);

    printf("\033[38;2;90;0;255m===================================================================="
           "=============================\n\033[0m");

    // cache bypass test
    int non_cached_write_variable;

    move_non_temporal_hint_movnti_instruction(&non_cached_write_variable, 50);
    store_fence_sfence_instruction();

    printf("\033[38;2;255;0;0m========== Cache Bypass Results  ==========\n\033[0m");

    return ret;
}
