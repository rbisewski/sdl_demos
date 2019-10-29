/*
 * Description: header with the CSV definition
 */

#ifndef CSV_H
#define CSV_H

// C99 includes
#include <stdbool.h>

// Definitions
#define CSV_LINE_BUFFER_SIZE 16
#define CSV_COLUMN_MAX 48
#define CSV_ROW_MAX 32

/*
 * Comma Separated Values
 */
typedef struct CSV {

    // Variable to determine if we have actually read in data.
    bool currently_has_CSV_data;

    // Variable to store our numerical data.
    unsigned int data[CSV_COLUMN_MAX][CSV_ROW_MAX];

} CSV;

/*
 * Functions
 */

//! Constructor for our CSV object
/*!
 * @param      CSV    the CSV object to initialize.
 *
 * @returns    bool   whether or not the CSV object could be initialized.
 */
bool initializeCSV(CSV csv);

//! Method designed to dump our CSV object to stdout.
/*!
 * @param      CSV     the CSV object whose data will be printed.
 *
 * @returns    none 
 */
void dumpCSV(CSV csv);

//! Method designed to read a CSV file into memory.
/*!
 * @param    CSV      the CSV object to hold the input data.
 * @param    string   the path to the file.
 *
 * @returns  bool     whether or not the read-in was successful
 */
bool readCSV(CSV csv, const char* path);

#endif
