#include <stdio.h>

int main()
{
    float avarage_waiting_time = 0, avarage_turn_around_time = 0;
    int p_id[10], arr_time[10], burst_time[10], comp_time[10], turnarnd_time[10], waiting_time[10];
    int time_quantum, total, counter;
    int n, i=0, temp[10],x;
    n = x;
    printf("enter the number of process   :");
    scanf("%d", &n);
   
    for (i = 0; i < n; i++)
    {

        printf(" enter p_id = %d:", i + 1);
        scanf("%d", &p_id[i]);

        printf("enter arrival time %d:", i + 1);
        scanf("%d", &arr_time[i]);

        printf("enter burst time   %d:", i + 1);
        scanf("%d", &burst_time[i]);
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &time_quantum);
    printf("Process tBurst Time Turnaround Time Waiting Time");
    for (total = 0, i = 0; x != 0;)
    {
        if (temp[i] <= time_quantum && temp[i] > 0)
        {
            total = total + temp[i];
            temp[i] = 0;
            counter = 1;
        }
        else if (temp[i] > 0)
        {
            temp[i] = temp[i] - time_quantum;
            total = total + time_quantum;
        }
        if (temp[i] == 0 && counter == 1)
        {
            n--;

            avarage_waiting_time == waiting_time[i] + total - arr_time[i] - burst_time[i];
            avarage_turn_around_time == turnarnd_time[i] + total - arr_time[i];
            counter = 0;
            printf("PID\tA.Time\tB.Time\tC.Time\tTA.Time\tW.Time\n");
            for (i = 0; i < n; i++)
            {
                printf("%d\t%d\t%d\t%d\t%d\t%d\n", p_id[i], arr_time[i], burst_time[i], comp_time[i], turnarnd_time[i], waiting_time[i]);
            }

            
        }
        if (i == n - 1)
        {
            i = 0;
        }
        else if (arr_time[i + 1] <= total)
        {
            i++;
        }
        else
        {
            i = 0;
        }
    }

        //   printf("PID\tA.Time\tB.Time\tC.Time\tTA.Time\tW.Time\n");
        //     for (i = 0; i < n; i++)
        //     {
        //         printf("%d\t%d\t%d\t%d\t%d\t%d\n", p_id, arr_time, burst_time, comp_time, turnarnd_time, waiting_time);
        //     }

    avarage_turn_around_time = avarage_turn_around_time/n;
    avarage_waiting_time = avarage_waiting_time/n;
    printf("Average Waiting Time: ", avarage_waiting_time);
    printf("Avg Turnaround Time: ", avarage_turn_around_time);
    return 0;
}