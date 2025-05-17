#include <stdio.h>

int fr[3];

void display() {
    int i;
    printf("\n");
    for (i = 0; i < 3; i++) {
        if (fr[i] != -1)
            printf(" %d", fr[i]);
        else
            printf(" -");
    }
}

int main() {
    int p[12] = {2, 3, 2, 1, 5, 2, 4, 5, 3, 2, 5, 2};
    int i, j, k, l, index, flag1 = 0, flag2 = 0, pf = 0, frsize = 3;
    int fs[3];

    for (i = 0; i < frsize; i++) {
        fr[i] = -1;
    }

    for (j = 0; j < 12; j++) {
        flag1 = 0;
        flag2 = 0;

        for (i = 0; i < frsize; i++) {
            if (fr[i] == p[j]) {
                flag1 = 1;
                flag2 = 1;
                break;
            }
        }

        if (flag1 == 0) {
            for (i = 0; i < frsize; i++) {
                if (fr[i] == -1) {
                    fr[i] = p[j];
                    flag2 = 1;
                    pf++;
                    break;
                }
            }
        }

        if (flag2 == 0) {
            for (i = 0; i < frsize; i++) {
                fs[i] = 0;
            }

            for (k = j + 1, l = 1; l <= frsize - 1 && k < 12; k++) {
                for (i = 0; i < frsize; i++) {
                    if (p[k] == fr[i] && fs[i] == 0) {
                        fs[i] = 1;
                        l++;
                    }
                }
            }

            for (i = 0; i < frsize; i++) {
                if (fs[i] == 0) {
                    index = i;
                    break;
                }
            }

            if (i == frsize) index = 0;
            fr[index] = p[j];
            pf++;
        }

        display();
    }

    printf("\n\nNumber of page faults: %d\n", pf);
    return 0;
}
