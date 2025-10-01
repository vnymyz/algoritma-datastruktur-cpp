/* strcpy example */
#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "Sample string";
    char str2[40];
    char str3[40];

    strcpy(str2, str1);               // copy isi str1 ke str2
    strcpy(str3, "copy successful");  // copy string literal ke str3

    printf("str1: %s\nstr2: %s\nstr3: %s\n", str1, str2, str3);

    return 0;
}
