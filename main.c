#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_TRACKS 100

// global variables
int tracks[MAX_TRACKS];
int m = 0;
int starting_track = 0;

// Function declarations
void enter_parameters();
void calculate_distance_fifo();
void calculate_distance_sstf();
void calculate_distance_scan();
void calculate_distance_cscan();
void sort_tracks(int *tracks, int m);
void print_tracks(int distance);


void enter_parameters() {
    printf("Enter size of sequence: ");
    scanf("%d", &m);

}

void calculate_distance_fifo() {
    printf("Enter starting track: ");
    scanf("%d", &starting_track);

    printf("Enter sequence of tracks to seek: ");
    for (int i = 0; i < m - 1; i++) {
        scanf("%d", &tracks[i]);
    }

    int distance = 0;
    int current_track = starting_track;

    for (int i = 0; i < m - 1; i++) {
        distance += abs(tracks[i] - current_track);
        current_track = tracks[i];
    }

    print_tracks(distance);
}

void calculate_distance_sstf() {
    printf("Enter starting track: ");
    scanf("%d", &starting_track); // Get the starting track

    printf("Enter sequence of tracks to seek: ");
    for (int i = 0; i < m - 1; i++) {
        scanf("%d", &tracks[i]); // Fill in the track requests
    }

    int distance = 0;
    int visited[MAX_TRACKS] = {0}; // Array to mark visited tracks
    int current_track = starting_track;
    int count = m - 1;

    // Process each track request
    while (count > 0) {
        int nearest = -1;
        int min_distance = 1000000;

        // Find the nearest unvisited track
        for (int j = 0; j < m - 1; j++) {
            if (!visited[j]) {
                int seek_distance = abs(tracks[j] - current_track);
                if (seek_distance < min_distance) {
                    min_distance = seek_distance;
                    nearest = j;
                }
            }
        }

        if (nearest != -1) { // If a nearest track is found
            visited[nearest] = 1; // Mark this track as visited
            distance += min_distance; // Add the distance to the total
            current_track = tracks[nearest]; // Move to this track
            count--; // Reduce the number of tracks left to process
        }
    }

    print_tracks(distance); // Print the results
}



void calculate_distance_scan() {
    
}

void calculate_distance_cscan() {
    
}


void print_tracks(int distance) {
    printf("Traversed sequence: %d ", starting_track);

    for (int i = 0; i < m - 1; i++) {
        printf("%d ", tracks[i]); // Print each track
    }
    printf("\n");
    printf("The distance of the traversed tracks is: %d\n", distance); // Print the total distance
    printf("\n");
}

// Main ----------------------------
int main() {
    
    // 
    int user_input;

    while (1) {
        printf("\nDisk Scheduling Menu:\n");
        printf("-----------------------\n");
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
                enter_parameters();
                break;
            case 2:
                calculate_distance_fifo();
                break;
            case 3:
                calculate_distance_sstf();
                break;
            case 4:
                calculate_distance_scan();
                break;
            case 5:
                calculate_distance_cscan();
                break;
            case 6:
                printf("Quitting program...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } // end while
    return 0;
}