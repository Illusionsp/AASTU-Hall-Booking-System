#include <iostream>
#include <iomanip>  // For table formatting (setw)
#include <cstring>  // For string manipulation (strcpy, strcmp)
#include <cstdlib>  // For system("cls")
#include <limits>   // For input validation

using namespace std;

//  GLOBAL CONSTANTS
// These define the fixed sizes for our arrays
const int NUM_HALLS = 3;
const int NUM_SLOTS = 4;
const int NAME_LEN = 30;
const int MAX_USERS = 10;

int main() {
    
    // 1. User Database (Parallel Arrays)
    // We pre-load one Admin account
    char dbUsers[MAX_USERS][20] = {"admin"};
    char dbPass[MAX_USERS][20]  = {"admin123"};
    char dbRoles[MAX_USERS][20] = {"admin"}; 
    int userCount = 1; 

    // 2. Hall Data Structures
    // schedule: 0 = Free, 1 = Booked
    int schedule[NUM_HALLS][NUM_SLOTS] = {0}; 
    
    // bookings: Stores the text name of the event
    char bookings[NUM_HALLS][NUM_SLOTS][NAME_LEN];
    
    // Constant Names for Display
    const char HALL_NAMES[NUM_HALLS][20] = {"Main Auditorium", "Conference A", "Conference B"};
    const char TIME_SLOTS[NUM_SLOTS][20] = {"08:00-10:00", "10:00-12:00", "13:00-15:00", "15:00-17:00"};

    // Initialize all booking slots to "---"
    for(int i=0; i<NUM_HALLS; i++)
        for(int j=0; j<NUM_SLOTS; j++)
            strcpy(bookings[i][j], "---");

    // Pre-fill one slot (Demo Data)
    schedule[0][1] = 1; 
    strcpy(bookings[0][1], "Orientation Day");

    // System Control Variables
    char currentUserRole[20] = ""; 
    bool loggedIn = false;
    bool systemRunning = true; 

    // --- SUPER LOOP (Keeps the program running for "Back" button) ---
    while (systemRunning) {
}