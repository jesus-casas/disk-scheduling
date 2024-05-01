#include <stdio.h>

#define MAX_TRACKS 100

void enter_parameters(int *m) {
    printf("Enter size of sequence: ");
    scanf("%d", m);

}

int calculate_distance_fifo(int *tracks, int m, int starting_track) {
    return 0;
}

int calculate_distance_sstf(int *tracks, int m, int starting_track) {
    return 0;
}

int calculate_distance_scan(int *tracks, int m, int starting_track) {
    return 0;
}

int calculate_distance_cscan(int *tracks, int m, int starting_track) {
    return 0;
}

void sort_tracks(int *tracks, int m) {

}

void print_tracks(int *tracks, int m, int starting_track) {

}

// Main ----------------------------
int main() {
    
    // 
    int user_input, m = 0, starting_track = 0;
    int tracks[MAX_TRACKS];

    while (1) {
        printf("\nDisk Scheduling Menu:\n");
        printf("1) Enter parameters\n");
        printf("2) Calculate distance to traverse tracks using FIFO\n");
        printf("3) Calculate distance to traverse tracks using SSTF\n");
        printf("4) Calculate distance to traverse tracks using Scan\n");
        printf("5) Calculate distance to traverse tracks using C-Scan\n");
        printf("6) Quit program and free memory\n");
        printf("Enter your choice: ");
        scanf("%d", &user_input);

        switch (user_input) {
            case 1:
                enter_parameters(&m);
                break;
            case 2:
                printf("FIFO Distance: %d\n", calculate_distance_fifo(tracks, m, starting_track));
                break;
            case 3:
                printf("SSTF Distance: %d\n", calculate_distance_sstf(tracks, m, starting_track));
                break;
            case 4:
                printf("Scan Distance: %d\n", calculate_distance_scan(tracks, m, starting_track));
                break;
            case 5:
                printf("C-Scan Distance: %d\n", calculate_distance_cscan(tracks, m, starting_track));
                break;
            case 6:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } // end while
    return 0;
}