#include <stdio.h>
int main() {
    int bt[20], wt[20], tat[20], i, n;
    float wtavg, tatavg;
    printf("\nEnter the number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("\nEnter Burst Time for Process %d: ", i);
        scanf("%d", &bt[i]);
    }
    wt[0] = 0;
    wtavg = 0;
    tat[0] = bt[0];
    tatavg = bt[0];
    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];  // Waiting time calculation
        tat[i] = wt[i] + bt[i];         // Turnaround time calculation
        wtavg += wt[i];
        tatavg += tat[i];
    }
    printf("\n\tPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for (i = 0; i < n; i++)
        printf("\n\tP%d\t\t%d\t\t%d\t\t%d", i, bt[i], wt[i], tat[i]);
    printf("\nAverage Waiting Time: %.2f", wtavg / n);
    printf("\nAverage Turnaround Time: %.2f\n", tatavg / n);
    return 0;
}

// Output
// Enter the number of processes: 3
// Enter Burst Time for Process 0: 24
// Enter Burst Time for Process 1: 3
// Enter Burst Time for Process 2: 3
// 	PROCESS	BURST TIME	WAITING TIME	TURNAROUND TIME
// 	P0		24		0		24
// 	P1		3		24		27
// 	P2		3		27		30
// Average Waiting Time: 17.00
// Average Turnaround Time: 27.00
