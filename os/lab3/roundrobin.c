// cs20b1085 gugulothu ravindar


#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000
int context_switch_overhead, i;

struct proccess
{
    int p_id, arr_time, burst_time, completion_time, turn_around_time, waiting_time, temp_burst_time;
};

struct proccess *proccess;
int start = -1, end = -2, ready_queue[SIZE], time_quantum, n;

// We are using the push function to perform push operation for the ready queue.
void push(int index)
{
    if (start == -1)
    {
        start = 0;
        end = start;
        ready_queue[end] = index;
    }
    else
    {
        end++;
        ready_queue[end] = index;
    }
}

// we are using to remove the completed proccess.
int pop()
{
    if (start == -1)
    {
        return -1;
    }
    else if (start == end)
    {
        int index = start;
        start = -1;
        end = start;
        return ready_queue[index];
    }
    else
    {
        int index = start;
        start++;
        return ready_queue[index];
    }
}

// function to sort the arrival time.
void sort_arr_time()
{
    struct proccess temp;
    for (i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (proccess[i].arr_time > proccess[j].arr_time)
            {
                temp = proccess[i];
                proccess[i] = proccess[j];
                proccess[j] = temp;
            }
        }
    }
}

// function to sort pp_id's
void sort_Pid()
{
    struct proccess temp;
    for (i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (proccess[i].p_id > proccess[j].p_id)
            {
                temp = proccess[i];
                proccess[i] = proccess[j];
                proccess[j] = temp;
            }
        }
    }
}

// function to perform Round Robin scheduling.
void schedule_proccesses()
{
    sort_arr_time(); // sorting arrival time.
    int count = 0;

    // declaring a ready queue.
    int queued_proccess[n];

    // initialising the ready queue with '0'.
    for (i = 0; i < n; i++)
    {
        queued_proccess[i] = 0;
    }

    // loop until all the proccesses are completed.
    for (int time = 0; count != n; time += time_quantum)
    {
        int fcfs = n;

        // if the ready queue is empty, we will take the proccess with less arrival time.
        if (start == -1)
        {
            int arr_time = time;
            for (i = 0; i < n; i++)
            {
                if ((proccess[i].arr_time <= arr_time) && (proccess[i].temp_burst_time > 0))
                {
                    arr_time = proccess[i].arr_time;
                    fcfs = i;
                }
            }

            // if fcfs is equal to number of proccesses then the loop ends.
            if (fcfs == n)
            {
                time += 1;
                time -= time_quantum;
                continue;
            }
        }
        else
        { // we use the start element as the proccesses.
            fcfs = pop();
            queued_proccess[fcfs] = 0;
        }

        // if burst time is less than the quantum time.
        if (proccess[fcfs].temp_burst_time < time_quantum)
        {
            int time_to_finish;

            time_to_finish = proccess[fcfs].temp_burst_time;
            proccess[fcfs].temp_burst_time = 0;
            time += time_to_finish;
            count++;

            proccess[fcfs].completion_time = time;
            proccess[fcfs].turn_around_time = proccess[fcfs].completion_time - proccess[fcfs].arr_time;
            proccess[fcfs].waiting_time = proccess[fcfs].turn_around_time - proccess[fcfs].burst_time;
            time -= time_quantum;
        }
        else
        {
            proccess[fcfs].temp_burst_time -= time_quantum;

            if (proccess[fcfs].temp_burst_time == 0)
            {
                count++;
                proccess[fcfs].completion_time = time + time_quantum;
                proccess[fcfs].turn_around_time = proccess[fcfs].completion_time - proccess[fcfs].arr_time;
                proccess[fcfs].waiting_time = proccess[fcfs].turn_around_time - proccess[fcfs].burst_time;
            }
        }

        context_switch_overhead++; // here we are counting the no.of context switch.

        for (i = 0; i < n; i++)
        {
            if ((proccess[i].arr_time <= (time + time_quantum)) && (proccess[i].temp_burst_time > 0) && (i != fcfs) && (!queued_proccess[i]))
            {
                push(i);
                queued_proccess[i] = 1; // adding the proccess to the ready queue.
            }
        }

        // add the proccess to the end of the ready queue if the burst time is not equal to 0.
        if (proccess[fcfs].temp_burst_time != 0)
        {
            push(fcfs);
            queued_proccess[fcfs] = 1;
        }
    }

    context_switch_overhead--; // decrementing the context switch, because it is less than the no.of proccesses.

    sort_Pid();
}

// function to print table and calculate average waiting time and arrival time.
void printTable()
{
    float sum_at, sum_wt, avg_at = 0, avg_wt = 0;
    printf("Pp_id\tA.Time\tB.Time\tC.Time\tTA.Time\tW.Time\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", proccess[i].p_id, proccess[i].arr_time, proccess[i].burst_time, proccess[i].completion_time, proccess[i].turn_around_time, proccess[i].waiting_time);
    }

    for (i = 0; i < n; i++)
    {
        sum_at += proccess[i].arr_time;
        sum_wt += proccess[i].waiting_time;
    }

    // calculating the average.
    avg_at = sum_at / n;
    avg_wt = sum_wt / n;

    printf("\nAverage waiting time is : %f", avg_at);
    printf("\nAverage waiting time is : %f", avg_wt);
    printf("\nContext switch Overhead : %d\n", context_switch_overhead);
}

// main driver function.
int main()
{
    printf("Enter the number of proccesses: "); // asking the user to enter the no.of proccesses
    scanf("%d", &n);

    proccess = malloc((n) * sizeof(*proccess));

    for (i = 0; i < n; i++)
    {
        printf("Enter the p_id of proccess: ");
        scanf("%d", &proccess[i].p_id); // entering the proccess p_id's
    }

    printf("\n");

    for (i = 0; i < n; i++)
    {
        printf("Enter the arrival time of proccess  %d: ", proccess[i].p_id); // asking the user to enter the arrival time.
        scanf("%d", &proccess[i].arr_time);
    }
    printf("\n");

    for (i = 0; i < n; i++)
    {
        printf("Enter the burst time of proccess  %d: ", proccess[i].p_id); // asking the user to enter the burst time.
        scanf("%d", &proccess[i].burst_time);
        proccess[i].temp_burst_time = proccess[i].burst_time;
    }
    printf("\n");

    printf("Enter the time quantum of proccesses: "); // asking the user to enter time quantum.
    scanf("%d", &time_quantum);
    schedule_proccesses();
    printTable();
    return 0;
}
