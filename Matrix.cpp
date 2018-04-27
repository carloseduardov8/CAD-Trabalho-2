#include <iostream>
#include <fstream>
#include <cmath>            // Math routines
#include <random>			// For random data generation
#include "Matrix.h"

using namespace std;

// Allocates space for matrix:
Matrix::Matrix(int dimRows, int dimColumns, bool columnsSeq){


	// Saves dimensions:
	rows = dimRows;
	columns = dimColumns;

	// Saves matrix layout:
	inverted = columnsSeq;

	if (inverted){

		// Allocates *k* columns for the data matrix:
		matrix = new data_t*[columns];

		// Allocates *n* rows:
		for (int j = 0; j < columns; j++){
			matrix[j] = new data_t[rows];
		}

	} else {

		// Allocates *n* rows for the data matrix:
		matrix = new data_t*[rows];

		// Allocates *k* columns:
		for (int j = 0; j < rows; j++){
			matrix[j] = new data_t[columns];
        }
	}
}


// Returns a value:
data_t Matrix::get(int i, int j){
	if (inverted){
    	return matrix[j][i];
	} else {
		return matrix[i][j];
	}
}


// Saves a value:
data_t Matrix::put(int i, int j, data_t value){
	if (inverted){
    	matrix[j][i] = value;
	} else {
		matrix[i][j] = value;
	}
}



// Generates *n* elements, each containing *k* attributes:
void Matrix::generateRandom(){
    this->fillLinesSerial();
}




// Dependency function executed by threads to fill a random data matrix:
void Matrix::fillLinesSerial(){

    // Interval of data:
    int interval = 500;

    // Seed:
    srand(time(NULL));

	// Loops through columns:
	for (int j = 0; j < columns; j++){
		// Loops through rows:
		for (int i = 0; i < rows; i++){
			// Fills in random data:
			this->put(i, j, rand() % interval);
		}
	}

}

void Matrix::print(int numRows){
    cout << endl;
    // Loops through lines:
    for (int i = 0; i < numRows; i++){
        cout << "[";
        // Loops through columns:
        for (int j = 0; j < columns; j++){
            // Prints data:
            cout << this->get(i, j);
            if (j != columns-1){
                 cout << '\t';
            }
        }
        cout << "]" << endl;
    }
    cout << endl;
}

Matrix::~Matrix(){

	// Deletes every columns:
	for (int j = 0; j < columns; j++){
		delete[] matrix[j];
	}

    delete[] matrix;

}
