#include <iostream>			// Formatted output
#include <ctime>			// For stopwatch
#include <cmath>            // Math routines
#include "Matrix.h"			// Data matrix class

using namespace std;

#define N 1000000
#define D 100


// Function declarations:
void findCentroids(Matrix* matrix);


// Main program:
int main(){

    // Starts the stopwatch:
	struct timespec start, finish;
    clock_gettime(CLOCK_MONOTONIC, &start);

	// Loads the data matrix:
	Matrix data(N, D, true);

	// Generates random data for matrix:
	data.generateRandom();

    // Runs centroid finding algorithm:
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
        //data_t acc = 0;
        // Loops through lines:
		for (int i = 0; i < N; i++){
            centroids[j] += matrix->get(i, j);
        }
        // Writes accumulator mean:
        centroids[j] /= N;
    }


    // Prints centroid values:
    for (int i = 0; i < D; i++){
        cout << centroids[i] << " - ";
    }

}
