/* malloc example: random string generator */
#include <stdio.h>   /* printf, scanf, NULL */
#include <stdlib.h>  /* malloc, free, rand, srand */
#include <time.h>    /* time */

int main() {
    int i, n;
    char *buffer;

    // %d integer
    // %f float
    // %s string
    // %lf double
    printf("How long do you want the string? ");
    scanf("%d", &i);

    buffer = (char*) malloc(i + 1);
    if (buffer == NULL) exit(1);

    srand(time(NULL)); // seed random berdasarkan waktu sekarang

    for (n = 0; n < i; n++)
        buffer[n] = rand() % 26 + 'a';  // random huruf a-z

    buffer[i] = '\0'; // akhiri string dengan null terminator

    printf("Random string: %s\n", buffer);
    free(buffer);

    return 0;
}
