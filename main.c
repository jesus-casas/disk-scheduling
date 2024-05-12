#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#define MAX_TRACKS 100

// global variables
int tracks[MAX_TRACKS];
int accessed_tracks[MAX_TRACKS];
int m = 0;
int starting_track = 0;
int INT_MAX = 2147483647;

// Function declarations
void enter_parameters();
void calculate_distance_fifo();
void calculate_distance_sstf();
//void calculate_distance_scan();
void calculate_distance_cscan();
void print_tracks(int *accessed_tracks, int num_accessed, int distance);
void insertion_sort(int arr[], int n);

void enter_parameters() {
    printf("Enter size of sequence: ");
    scanf("%d", &m);

}

// *************** Calculate distance function FIFO ***************
void calculate_distance_fifo() {
    printf("Enter starting track: ");
    scanf("%d", &starting_track);
    printf("Enter sequence of tracks to seek: ");
    
    accessed_tracks[0] = starting_track; // First element is the starting track
    for (int i = 0; i < m - 1; i++) {
        scanf("%d", &tracks[i]);
        accessed_tracks[i + 1] = tracks[i]; // Copy to accessed_tracks for consistency, starting from next index
    }

    int distance = 0;
    int current_track = starting_track;

    for (int i = 1; i < m; i++) { // Start from 1 because the first track (starting track) doesn't involve movement
        distance += abs(accessed_tracks[i] - current_track);
        current_track = accessed_tracks[i];
    }

    print_tracks(accessed_tracks, m, distance); // Now we pass 'm' as the number of accessed tracks
}


// *************** Calculate distance function SSTF ***************
void calculate_distance_sstf() {
    printf("Enter starting track: ");
    scanf("%d", &starting_track);
    printf("Enter sequence of tracks to seek: ");
    for (int i = 0; i < m - 1; i++) {
        scanf("%d", &tracks[i]);
    }

    int distance = 0;
    int visited[MAX_TRACKS] = {0};  // Initializes the visited array to zero
    int current_track = starting_track;
    int accessed_index = 0;
    accessed_tracks[accessed_index++] = starting_track; // Add starting track initially

    int count = m - 1;
    while (count > 0) {
        int nearest = -1;
        int min_distance = INT_MAX;
        for (int j = 0; j < m - 1; j++) {
            if (!visited[j]) {
                int seek_distance = abs(tracks[j] - current_track);
                if (seek_distance < min_distance) {
                    min_distance = seek_distance;
                    nearest = j;
                }
            }
        }

        if (nearest != -1) { // Check if a nearest track is found
            visited[nearest] = 1;
            distance += min_distance;
            current_track = tracks[nearest];
            // Check to prevent adding the starting track twice
            if (current_track != starting_track || accessed_index == 1) {
                accessed_tracks[accessed_index++] = current_track;
            }
            count--;
        } else {
            // If no unvisited track is found, end the loop
            break;
        }
    }

    print_tracks(accessed_tracks, accessed_index, distance);
}

// *************** Calculate distance function for SCAN **************

void calculate_distance_cscan() {
    
}

// *************** Print function ***************
void print_tracks(int *accessed_tracks, int num_accessed, int distance) {
    printf("Traversed sequence: ");
    for (int i = 0; i < num_accessed; i++) {
        printf("%d ", accessed_tracks[i]);
    }
    printf("\n");
    printf("The distance of the traversed tracks is: %d\n", distance);
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
                //calculate_distance_scan();
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