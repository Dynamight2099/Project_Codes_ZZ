#include <stdio.h>

// Process structure
typedef struct {
    int process_id;
    int burst_time;
    int remaining_time;
} Process;

// Function to perform round-robin scheduling
void roundRobinScheduling(Process processes[], int n, int timeQuantum, int currentTime) {
    for (int i = 0; i < n; i++) {
        if (processes[i].remaining_time > 0) {
            // Execute one time unit or until the time quantum is exhausted
            int executionTime = (processes[i].remaining_time > timeQuantum) ? timeQuantum : processes[i].remaining_time;
            printf("Executing Process %d at Time %d\n", processes[i].process_id, currentTime);
            processes[i].remaining_time -= executionTime;
            currentTime += executionTime;

            // Check if the process has completed
            if (processes[i].remaining_time == 0) {
                printf("Process %d completed.\n", processes[i].process_id);
            }
        }
    }
}

int main() {
    int n, timeQuantum;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process processes[n];

    // Input process details
    for (int i = 0; i < n; i++) {
        processes[i].process_id = i + 1;
        printf("Enter burst time for Process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
    }

    // Input time quantum for round-robin scheduling
    printf("Enter time quantum for Round Robin: ");
    scanf("%d", &timeQuantum);

    int currentTime = 0;

    // Perform round-robin scheduling
    while (1) {
        roundRobinScheduling(processes, n, timeQuantum, currentTime);

        // Check if all processes have completed
        int allProcessesCompleted = 1;
        for (int i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0) {
                allProcessesCompleted = 0;
                break;
            }
        }

        if (allProcessesCompleted) {
            break;
        }
    }

    return 0;
}
