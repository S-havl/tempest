#include <arch/x86_64/timer/timer.h>

#include <stdio.h>

void test_algorithm(void) { printf("Hello World\n"); }

int main(void)
{
    int              ret = 0;
    uint64_t         previous_time_calculation;
    rdtscp_results_t subsequent_time_calculation;
    uint64_t         result_diference;

    previous_time_calculation = start_timer_rdtsc();

    test_algorithm();

    subsequent_time_calculation = stop_timer_rdtscp();
    result_diference =
        subsequent_time_calculation.rdtscp_full_timestamp_counter_value - previous_time_calculation;

    printf("========== Results ==========\n");
    printf("Previous time calculation: %llu\n", previous_time_calculation);
    printf("\nSubsequent time calculation:\n");
    printf("Counter value = %llu\n",
           subsequent_time_calculation.rdtscp_full_timestamp_counter_value);
    printf("TSC AUX Value = %u\n", subsequent_time_calculation.rdtscp_tsc_aux);

    printf("\nResult diference = %llu\n", result_diference);

    return ret;
}
