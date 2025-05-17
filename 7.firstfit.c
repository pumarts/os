#include <stdio.h>
#define MAX 25
int main() {
    int frag[MAX], block[MAX], file[MAX];
    int bf[MAX] = {0}, ff[MAX];
    int nb, nf, i, j;
    printf("Memory Management Scheme - First Fit\n");
    printf("Enter number of blocks: ");
    scanf("%d", &nb);
    printf("Enter number of files: ");
    scanf("%d", &nf);
    printf("Enter size of blocks:\n");
    for (i = 0; i < nb; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &block[i]);
    }
    printf("Enter size of files:\n");
    for (i = 0; i < nf; i++) {
        printf("File %d: ", i + 1);
        scanf("%d", &file[i]);
    }
    for (i = 0; i < nf; i++) {
        ff[i] = -1;
        for (j = 0; j < nb; j++) {
            if (bf[j] == 0 && block[j] >= file[i]) {
                ff[i] = j;
                bf[j] = 1;
                frag[i] = block[j] - file[i];
                break;
            }
        }
    }
    printf("\nFile No\tFile Size\tBlock No\tBlock Size\tFragment\n");
    for (i = 0; i < nf; i++) {
        if (ff[i] != -1) {
            printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, file[i], ff[i] + 1, block[ff[i]], frag[i]);
        } else {
            printf("%d\t%d\t\tNot Allocated\n", i + 1, file[i]);
        }
    }
    return 0;
}
