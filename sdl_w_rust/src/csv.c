/*
 * Description: file to handle comma separated values
 */

// Standard C includes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Associated header files
#include "csv.h"

//! Constructor for our CSV object
/*!
 * @param      CSV    the CSV object to initialize.
 *
 * @returns    bool   whether or not the CSV object could be initialized.
 */
bool initializeCSV(CSV csv) {

    // Silence ISO compiler warnings.
    csv = csv;

    // Set the flag to here to false to note that the object does not
    // currently contain data.
    csv.currently_has_CSV_data = false;

    // Having initialized the CSV successfully, return true.
    return true;
}

//! Method designed to dump our CSV object to stdout.
/*!
 * @param      CSV     the CSV object whose data will be printed.
 *
 * @returns    none 
 */
void dumpCSV(CSV csv) {

    // Variables used to help us count our columns / rows.
    int i = 0;
    int j = 0;

    // Sanity check, make sure we actually have data. 
    if (!csv.currently_has_CSV_data) {
        fprintf(stdout, "This CSV object currently has no data!\n");
        return;
    }

    // Cycle thru each of our rows...
    for (j = 0; j < CSV_ROW_MAX; j++) {

        // Cycle thru each of our columns...
        for (i = 0; i < CSV_COLUMN_MAX; i++) {

            // If not our last element, then add a comma.
            if (i < CSV_COLUMN_MAX-1) {
               fprintf(stdout,"%i,",csv.data[i][j]);

            // Since we have reached the last column of a given row, then
            // do *not* add a comma.
            } else {
               fprintf(stdout,"%i",csv.data[i][j]);
            }
        }
        fprintf(stdout,"\n");
    }

    // Having printed out our array, we can go ahead and return.
    return; 
}

//! Method designed to read a CSV file into memory.
/*!
 * @param    CSV      the CSV object to hold the input data.
 * @param    string   the path to the file.
 *
 * @returns  bool     whether or not the read-in was successful
 */
bool readCSV(CSV csv, const char* path) {

    // Silence ISO compiler warnings.
    csv = csv;

    // Variable declaration
    FILE *csv_file;
    char buffer[CSV_LINE_BUFFER_SIZE] = {0};
    unsigned int ptr    = 0;
    char tmp_char       = 0;
    int tmp_int         = 0;
    unsigned int row    = 0;
    unsigned int column = 0;

    // Input validation
    if (!path) {
        fprintf(stderr, "CSV::read() - Invalid Input\n");
        return false;
    }

    // Attempt to open our file
    csv_file = fopen(path, "r");

    // If we couldn't open the file, end here.
    if (!csv_file) {
        fprintf(stderr, "CSV::read() - Unable to open file: %s\n", path);
        return false;
    }

    // With our file open, attempt to read it in, char-by-char
    while ((tmp_char = fgetc(csv_file)) != EOF) {
             
         // Sanity check, make sure our column size has not exceeded the
         // maximum allowed.
         if (column >= CSV_COLUMN_MAX) {
             fprintf(stderr, "CSV::read() - Line %i has exceeded the "
               "maximum allowed columns. This was in file: %s\n", row+1, path);
             return false;
         }
             
         // Further sanity check, make sure our row size has not exceeded the
         // maximum allowed.
         if (row >= CSV_ROW_MAX) {
             fprintf(stderr, "CSV::read() - Line %i has exceeded the "
               "maximum allowed rows. This was in file: %s\n", row+1, path);
             return false;
         }

         // Check if the character is a comma, in which case we have reached
         // the end of our element, so attempt to parse the element.
         if (tmp_char == 44) {

             // Attempt to convert our buffer into an integer.
             tmp_int = strtol(buffer, NULL, 10);

             // Sanity check, make sure we could convert it properly.
             if (!tmp_int) {
                 fprintf(stderr, "CSV::read() - Buffer contained invalid "
                   "integer: %s\n", buffer);
                 return false;
             }

             // Save our integer to our internal data.
             csv.data[column][row] = tmp_int;

             // Attempt to wipe our buffer.
             if (!memset(buffer, 0, sizeof(buffer))) {
                 fprintf(stderr, "CSV::read() - Unable to wipe buffer memory\n");
                 return false;
             }

             // Move on to the next element of this row.
             column++;
             ptr = 0;
             continue;
         }

         // Check if the character is a newline, in which case we increment
         // the current row, and reset the column back to zero.
         if (tmp_char == 10) {
             
             // Attempt to convert our buffer into an integer.
             tmp_int = strtol(buffer, NULL, 10);

             // Sanity check, make sure we could convert it properly.
             if (!tmp_int) {
                 fprintf(stderr, "CSV::read() - Buffer contained invalid "
                   "integer: %s\n", buffer);
                 return false;
             }

             // Save our integer to our internal data.
             csv.data[column][row] = tmp_int;

             // Attempt to wipe our buffer.
             if (!memset(buffer, 0, sizeof(buffer))) {
                 fprintf(stderr, "CSV::read() - Unable to wipe buffer "
                   "memory.\n");
                 return false;
             }

             // Move on to the first element of the next row.
             column = 0;
             row++;
             ptr = 0;
             continue;
         }

         // Otherwise we still reading in a given element, so add the given
         // character to our character buffer.
         if (!strncpy(&buffer[ptr], &tmp_char, 1)) {
             fprintf(stderr, "CSV::read() - Unable to concat the following "
               "char to the buffer: %c\n", tmp_char);
             return false;
         }

         // Move the pointer to the next character.
         ptr++;
    }

    // Attempt to close our file.
    if (fclose(csv_file)) {
        fprintf(stderr, "CSV::read() - Unable to close file: %s\n", path);
        return false;
    }

    // If everythign worked as we expect, return true.
    csv.currently_has_CSV_data = true;
    return true;
}
