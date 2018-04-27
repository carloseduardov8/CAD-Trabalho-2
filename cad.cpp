#include <iostream>			// Formatted output
#include <ctime>			// For stopwatch
#include <cmath>            // Math routines
#include "Matrix.h"			// Data matrix class

using namespace std;

#define N 1000000
#define D 20


int similar = 0;
int* powArr;

// Function declarations:
void findCentroids(Matrix* matrix);


// Main program:
int main(){

	// Loads the data matrix:
	Matrix data(N, D, true);

	// Generates random data for matrix:
	data.generateRandom();

    // Starts the stopwatch:
	struct timespec start, finish;
    clock_gettime(CLOCK_MONOTONIC, &start);
    cout << "Start!" << endl;

    // Runs binary clustering algorithm:
    findCentroids(&data);

	// Stops the stopwatch:
	clock_gettime(CLOCK_MONOTONIC, &finish);

	// Prints out elapsed time:
    double elapsed = (finish.tv_sec - start.tv_sec);
    elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
	cout << endl << "Elapsed time: " << elapsed << " seconds." << endl;


}



void findCentroids(Matrix* matrix){

    /****************************/
    /*** CENTROID CALCULATION ***/
    /****************************/

    // Allocates centroid array:
    data_t* centroids = new data_t[D]();


    // Loops through designated columns:
	for (int j = 0; j < D; j++){
        // Accumulator:
        data_t acc = 0;
        // Loops through lines:
		for (int i = 0; i < N; i++){
            acc += matrix->get(i, j);
        }
        // Writes accumulator mean:
        centroids[j] = acc / N;
    }


    // Prints centroid values:
    for (int i = 0; i < D; i++){
        cout << centroids[i] << " - ";
    }

}

void findCentroids(int threadId, data_t* centroids, Matrix* matrix){

    // Loops through designated columns:
	for (int j = 0; j < D; j++){
        // Loops through lines:
		for (int i = 0; i < N; i++){
            centroids[j] += matrix->get(i, j);
        }
        centroids[j] /= N;
    }

}
/*
void findCentroids(int threadId, data_t* centroids, Matrix* matrix){

    // Loops through designated columns:
	for (int j = 0; j < D; j++){
        // Accumulator:
        data_t acc = 0;
        // Loops through lines:
		for (int i = 0; i < N; i++){
            acc += matrix->get(i, j);
        }
        // Writes accumulator mean:
        centroids[j] = acc / N;
    }

}*/
