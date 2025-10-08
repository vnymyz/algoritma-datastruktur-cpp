/* time example */
#include <stdio.h>   /* printf */
#include <time.h>    /* time_t, struct tm, difftime, time, mktime */

int main() {
    time_t timer;
    struct tm y2k;
    double seconds;

    // Set tanggal 1 Januari 2000 (Y2K)
    y2k.tm_hour = 0;  
    y2k.tm_min = 0;   
    y2k.tm_sec = 0;
    y2k.tm_year = 100;  // tahun dihitung dari 1900 -> 2000 = 1900+100
    y2k.tm_mon = 0;     // bulan dimulai dari 0 (0 = Januari)
    y2k.tm_mday = 1;    // tanggal 1

    // Ambil waktu sekarang
    time(&timer);  /* sama dengan: timer = time(NULL); */

    // Hitung selisih detik antara waktu sekarang dan 1 Jan 2000
    seconds = difftime(timer, mktime(&y2k));

    printf("%.f seconds since January 1, 2000 in the current timezone\n", seconds);

    return 0;
}
