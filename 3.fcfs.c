#include <stdio.h>

int main() {
    int bt[20], wt[20], tat[20], i, n;
    float wtavg, tatavg;

    printf("\nEnter the number of processes -- ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter Burst Time for Process %d -- ", i);
        scanf("%d", &bt[i]);
    }

    wt[0] = 0;
    wtavg = 0;
    tat[0] = bt[0];
    tatavg = bt[0];

    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = wt[i] + bt[i];
        wtavg += wt[i];
        tatavg += tat[i];
    }

    printf("\n\tPROCESS\t\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for (i = 0; i < n; i++) {
        printf("\n\tP%d\t\t%d\t\t%d\t\t%d", i, bt[i], wt[i], tat[i]);
    }

    printf("\n\nAverage Waiting Time -- %.2f", wtavg / n);
    printf("\nAverage Turnaround Time -- %.2f\n", tatavg / n);

    return 0;
}
