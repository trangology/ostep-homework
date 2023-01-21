1. The CPU utilization was 100.00%.

2. Total Time 11, CPU Busy 6 (54.55%), IO Busy  5 (45.45%)

3. Yes, switching order matters - the complete time was reduced by 4 units. That's because the system improved resource utilization by keeping the CPU busy - the CPU ran `PID 1` while waiting for `PID 0` completed.

4. The complete time is now increasing (from 7 to 11) due to the suspending of CPU as command `SWITCH_ON_END` was executed.

5. The complete time is now reduced (from 11 to 7) as command `SWITCH_ON_IO` was executed.

6. With `-I IO_RUN_LATER`, the system resources aren't effectively utilized since the CPU keeps running `PIDs 2, 3` instead of immediately running the process that was issued an I/O before and already completed.

7. Running the process that just completed an I/O might be a good idea because if that process still has more I/Os to handle, the system resources can effectively utilize other processes while waiting for said I/Os complete; hence the total time could be reduced.

8. In terms of total time and CPU utilization (`-s 3 -l 3:50,3:50` - with the seed of 3):
- A slight difference between `-I IO_RUN_IMMEDIATE` and `-I IO_RUN_LATER` (17 vs. 18, 52.94.00% vs. 50.00%)
- A larger difference between `-S SWITCH_ON_IO` and `-S SWITCH_ON_END` (18 vs. 24,  50.00% vs. 37.50%)
- Conclusion: the number of processes that issue I/Os matters to what option(s) to use in order to utilize system resources effectively?