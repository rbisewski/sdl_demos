#![crate_type = "lib"]
#![no_std]

extern crate std;

use std::{print, println, eprintln};
use std::string::String;
use std::path::Path;
use std::vec::Vec;

pub const CSV_LINE_BUFFER_SIZE: usize = 16;
pub const CSV_COLUMN_MAX: usize = 48;
pub const CSV_ROW_MAX: usize = 32;

//
// CSV
//
pub struct CSV {
    currently_has_csv_data: bool,
    data: [[u32; CSV_COLUMN_MAX]; CSV_ROW_MAX],
}

// Constructor for our CSV object
// 
// @param      CSV    the CSV object to initialize.
// 
// @returns    bool   whether or not the CSV object could be initialized.
// 
#[no_mangle]
pub extern "C" fn initializeCSV(mut csv: CSV) -> bool {

    csv.currently_has_csv_data = false;
    true
}

//  Method designed to dump our CSV object to stdout.
// 
// @param      CSV     the CSV object whose data will be printed.
// 
// @returns    none 
// 
#[no_mangle]
pub extern "C" fn dumpCSV(csv: CSV) {

    // Sanity check, make sure we actually have data. 
    if !csv.currently_has_csv_data {
        println!("This CSV object currently has no data!");
        return
    }

    for j in 0..=CSV_ROW_MAX-1 {
        for i in 0..=CSV_COLUMN_MAX-1 {

            // If not our last element, then add a comma.
            if i < CSV_COLUMN_MAX-1 {
               print!("{},",csv.data[i][j]);
               continue;
            }

            // Since we have reached the last column of a given row, then
            // do *not* add a comma.
            println!("{}",csv.data[i][j]);
        }
    }
}

//  Method designed to read a CSV file into memory.
// 
// @param    CSV      the CSV object to hold the input data.
// @param    string   the path to the file.
// 
// @returns  bool     whether or not the read-in was successful
// 
#[no_mangle]
pub extern "C" fn readCSV(mut csv: CSV, path_string: String) -> bool {

    if path_string == "" {
        eprintln!("CSV::read() - Invalid Input");
        return false;
    }

    let path = Path::new(&path_string);

    let contents = match std::fs::read_to_string(path) {
        Ok(contents) => contents,
        Err(e) => {
            eprintln!("CSV::read() - {:?}",e);
            return false;
        },
    };

    let mut lines = contents.lines();

    let mut row = 0;
    let mut column = 0;

    loop {
        match lines.next() {
            None => break,
            Some(line) => {
                if row > CSV_ROW_MAX-1 {
                    break;
                }

                let elements: Vec<&str> = line.split(',').collect();

                for raw in elements.into_iter() {
                    if column > CSV_COLUMN_MAX-1 {
                        break;
                    }

                    // check if the string can be parsed as a unsigned int
                    let v: u32 = match raw.parse::<u32>() {
                        Ok(v) => v,
                        Err(e) => {
                            eprintln!("CSV::read() - {:?}",e);
                            return false;
                        },
                    };

                    csv.data[column][row] = v;
                    column += 1;
                }

                row += 1;
            },
        };
    }

    csv.currently_has_csv_data = true;
    true
}
