#include <stdio.h>
#include <stdlib.h>

void paskal_uchburchagi(int n) {
    int **paskal = (int **)malloc(n * sizeof(int *));
    if (paskal == NULL) {
        printf("Xatolik: Xotira ajratilmadi!\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        paskal[i] = (int *)malloc((i + 1) * sizeof(int));
        if (paskal[i] == NULL) {
            for (int j = 0; j < i; j++) free(paskal[j]);
            free(paskal);
            return;
        }

        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                paskal[i][j] = 1;
            } else {
                paskal[i][j] = paskal[i - 1][j - 1] + paskal[i - 1][j];
            }
        }
    }

    printf("\n--- Paskal Uchburchagi (%d qator) ---\n", n);
    for (int i = 0; i < n; i++) {
        for (int space = 0; space < n - i - 1; space++) {
            printf("  ");
        }
        for (int j = 0; j <= i; j++) {
            printf("%4d ", paskal[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++) {
        free(paskal[i]);
    }
    free(paskal);
    printf("\nXotira muvaffaqiyatli tozalandi!\n");
}

int main(void) {
    int n;
    printf("Paskal uchburchagi qatorlar sonini kiriting (1 dan 15 gacha): ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > 15) {
        printf("Xatolik: Qatorlar soni 1 va 15 oralig'ida bo'lishi kerak!\n");
        return 1;
    }

    paskal_uchburchagi(n);
    return 0;
}
