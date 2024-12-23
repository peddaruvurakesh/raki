#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to get the number of CPUs, clock speed, and number of cores
void get_cpu_info() {
    FILE *cpuinfo = fopen("/proc/cpuinfo", "r");
    if (cpuinfo == NULL) {
        perror("Error opening /proc/cpuinfo");
        return;
    }

    int cpu_count = 0;
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), cpuinfo)) {
        if (strncmp(buffer, "processor", 9) == 0) {
            cpu_count++;
        } else if (strncmp(buffer, "cpu MHz", 7) == 0) {
            printf("CPU %d clock speed: %s", cpu_count, buffer + 11);
        } else if (strncmp(buffer, "cpu cores", 9) == 0) {
            printf("CPU %d cores: %s", cpu_count, buffer + 12);
        }
    }
    printf("Total CPUs: %d\n", cpu_count);
    fclose(cpuinfo);
}

// Function to get the Linux kernel version
void get_kernel_version() {
    FILE *version = fopen("/proc/version", "r");
    if (version == NULL) {
        perror("Error opening /proc/version");
        return;
    }

    char buffer[256];
    fgets(buffer, sizeof(buffer), version);
    printf("Linux kernel version: %s", buffer);
    fclose(version);
}

/* Function to get the system boot time
void get_boot_time() {
    FILE *uptime = fopen("/proc/uptime", "r");
    if (uptime == NULL) {
        perror("Error opening /proc/uptime");
        return;
    }

    double seconds_since_boot;
    fscanf(uptime, "%lf", &seconds_since_boot);
    fclose(uptime);

    time_t boot_time = time(NULL) - (time_t)seconds_since_boot;
    struct tm *bt = localtime(&boot_time);
    printf("System booted on: %02d:%02d:%02d %02d-%02d-%04d\n",
           bt->tm_hour, bt->tm_min, bt->tm_sec, bt->tm_mday, bt->tm_mon + 1, bt->tm_year + 1900);
}

// Function to get the load average for the last 15 minutes
void get_load_average() {
    FILE *loadavg = fopen("/proc/loadavg", "r");
    if (loadavg == NULL) {
        perror("Error opening /proc/loadavg");
        return;
    }

    double load_15min;
    fscanf(loadavg, "%*f %*f %lf", &load_15min);
    printf("Average load (last 15 minutes): %.2lf\n", load_15min);
    fclose(loadavg);
}
*/
// Function to get memory and swap information
void get_memory_info() {
    FILE *meminfo = fopen("/proc/meminfo", "r");
    if (meminfo == NULL) {
        perror("Error opening /proc/meminfo");
        return;
    }

    char buffer[256];
    unsigned long mem_total = 0, mem_free = 0, swap_total = 0, swap_free = 0;

    while (fgets(buffer, sizeof(buffer), meminfo)) {
        if (sscanf(buffer, "MemTotal: %lu kB", &mem_total) == 1) {
            printf("Total usable memory: %lu kB\n", mem_total);
        } else if (sscanf(buffer, "MemFree: %lu kB", &mem_free) == 1) {
            printf("Currently free memory: %lu kB\n", mem_free);
        } else if (sscanf(buffer, "SwapTotal: %lu kB", &swap_total) == 1) {
            printf("Total swap space: %lu kB\n", swap_total);
        } else if (sscanf(buffer, "SwapFree: %lu kB", &swap_free) == 1) {
            printf("Currently free swap space: %lu kB\n", swap_free);
        }
    }

    unsigned long swap_used = swap_total - swap_free;
    printf("Currently used swap space: %lu kB\n", swap_used);
    fclose(meminfo);
}

// Function to get swap partition information
void get_swap_partitions() {
    FILE *swaps = fopen("/proc/swaps", "r");
    if (swaps == NULL) {
        perror("Error opening /proc/swaps");
        return;
    }

    char buffer[256];
    printf("Swap partitions:\n");
    fgets(buffer, sizeof(buffer), swaps); // Skip the first line (header)
    while (fgets(buffer, sizeof(buffer), swaps)) {
        printf("%s", buffer);
    }
    fclose(swaps);
}

// Function to get CPU time spent in user and kernel mode
void get_cpu_time() {
    FILE *stat = fopen("/proc/stat", "r");
    if (stat == NULL) {
        perror("Error opening /proc/stat");
        return;
    }

    char buffer[256];
    unsigned long user_time, nice_time, system_time;
    while (fgets(buffer, sizeof(buffer), stat)) {
        if (sscanf(buffer, "cpu %lu %lu %lu", &user_time, &nice_time, &system_time) == 3) {
            printf("CPU time in user mode: %lu\n", user_time);
            printf("CPU time in kernel mode: %lu\n", system_time);
            break;
        }
    }
    fclose(stat);
}

// Function to get the number of context switches
void get_context_switches() {
    FILE *stat = fopen("/proc/stat", "r");
    if (stat == NULL) {
        perror("Error opening /proc/stat");
        return;
    }

    char buffer[256];
    unsigned long context_switches = 0;
    while (fgets(buffer, sizeof(buffer), stat)) {
        if (sscanf(buffer, "ctxt %lu", &context_switches) == 1) {
            printf("Number of context switches: %lu\n", context_switches);
            break;
        }
    }
    fclose(stat);
}

// Function to get the number of interrupts handled
void get_interrupts() {
    FILE *stat = fopen("/proc/stat", "r");
    if (stat == NULL) {
        perror("Error opening /proc/stat");
        return;
    }

    char buffer[256];
    unsigned long interrupts = 0;
    while (fgets(buffer, sizeof(buffer), stat)) {
        if (sscanf(buffer, "intr %lu", &interrupts) == 1) {
            printf("Number of interrupts handled: %lu\n", interrupts);
            break;
        }
    }
    fclose(stat);
}

int main() {
    get_cpu_info();
    printf("\n");
    
    get_kernel_version();
    printf("\n");

//    get_boot_time();
  //  printf("\n");

 //   get_load_average();
   // printf("\n");

    get_memory_info();
    printf("\n");

    get_swap_partitions();
    printf("\n");

    get_cpu_time();
    printf("\n");

    get_context_switches();
    printf("\n");

    get_interrupts();
    printf("\n");

    return 0;
}

