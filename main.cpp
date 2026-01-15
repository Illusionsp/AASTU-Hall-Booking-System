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
        
       while (!loggedIn && systemRunning) {
            int authChoice;
            cout << "\n\t==============================================\n";
            cout << "\t   AASTU HALL & EVENT MANAGEMENT SYSTEM       \n";
            cout << "\t==============================================\n";
            cout << "\t1. Login\n";
            cout << "\t2. Register New User\n";
            cout << "\t3. View as Guest (Read Only)\n";
            cout << "\t4. Exit Program\n";
            cout << "\tSelect: ";

            while(!(cin >> authChoice)) {
                cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\tInvalid input. Try again: ";
            }

            if (authChoice == 1) {
                // --- LOGIN LOGIC ---
                char u[20], p[20];
                bool found = false;
                cout << "\n\t--- LOGIN ---\n";
                cout << "\tUsername: "; cin >> u;
                cout << "\tPassword: "; cin >> p;

                // Linear Search
                for (int i = 0; i < userCount; i++) {
                    if (strcmp(dbUsers[i], u) == 0 && strcmp(dbPass[i], p) == 0) {
                        strcpy(currentUserRole, dbRoles[i]);
                        found = true;
                        loggedIn = true; // Breaks Auth Loop, moves to App Loop
                        break;
                    }
                }
                if(!found) {
                    cout << "\n\t[ERROR] Invalid credentials.\n";
                    cin.ignore(); cin.get();
                }

            } else if (authChoice == 2) {
                // --- REGISTRATION LOGIC (SECURE VERSION) ---
                if (userCount >= MAX_USERS) {
                    cout << "\n\t[ERROR] Database Full!\n";
                } else {
                    cout << "\n\t--- REGISTRATION ---\n";
                    int roleChoice;
                    cout << "\tSelect Role (1=Student, 2=Admin): "; cin >> roleChoice;

                    if (roleChoice == 2) {
                        // Admin Path
                        char key[20];
                        cout << "\t[SECURITY] Enter Master Key: "; cin >> key;
                        if(strcmp(key, "2024") == 0) {
                            cout << "\tNew Username: "; cin >> dbUsers[userCount];
                            cout << "\tNew Password: "; cin >> dbPass[userCount];
                            strcpy(dbRoles[userCount], "admin");
                            userCount++;
                            cout << "\t[SUCCESS] Admin Account Created.\n";
                        } else {
                            cout << "\n\t[FAILED] Incorrect Master Key. Aborted.\n";
                        }
                    }
                    else if (roleChoice == 1) {
                        // Student Path
                        cout << "\tNew Username: "; cin >> dbUsers[userCount];
                        cout << "\tNew Password: "; cin >> dbPass[userCount];
                        strcpy(dbRoles[userCount], "student");
                        userCount++;
                        cout << "\t[SUCCESS] Student Account Created.\n";
                    }
                    else {
                        cout << "\t[ERROR] Invalid Role Selection.\n";
                    }
                }
                cin.ignore(); cin.get();

            } else if (authChoice == 3) {
                // --- GUEST LOGIC ---
                strcpy(currentUserRole, "guest");
                loggedIn = true;
            } else if (authChoice == 4) {
                // --- EXIT LOGIC ---
                systemRunning = false; // Stops the Super Loop
            }
        }

    }

        while (loggedIn && systemRunning) {
            #ifdef _WIN32
                system("cls");
            #else
                system("clear");
            #endif

            cout << "\n\t==============================================\n";
            cout << "\t   UNIVERSITY HALL BOOKING SYSTEM v1.0        \n";
            cout << "\t==============================================\n";
            cout << "\tLogged in as: " << currentUserRole << "\n\n";

            // Grid Display
            cout << left << setw(18) << "HALL NAME";
            for(int j=0; j<NUM_SLOTS; j++) cout << setw(15) << TIME_SLOTS[j];
            cout << "\n\t" << string(75, '-') << endl;

            for(int i=0; i<NUM_HALLS; i++) {
                cout << left << setw(18) << HALL_NAMES[i];
                for(int j=0; j<NUM_SLOTS; j++) {
                    if(schedule[i][j] == 0) cout << left << setw(15) << "[FREE]";
                    else cout << left << setw(15) << bookings[i][j];
                }
                cout << endl;
            }

            // Menu
            cout << "\n\t-----------------------------";
            cout << "\n\t1. Book a Hall";
            cout << "\n\t2. Edit Event Name";
            cout << "\n\t3. Cancel Reservation";
            cout << "\n\t4. Search by Event Name"; // UPDATED
            cout << "\n\t5. View Statistics";
            cout << "\n\t6. Back"; 
            cout << "\n\t-----------------------------";
            cout << "\n\tSelect Option: ";
            
            while(!(cin >> menuChoice)) {
                cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\tInvalid. Enter 1-6: ";
            }

            // Shared Variables for Switch
            int hIndex, tIndex;
            char eventInput[NAME_LEN]; // Changed var name to eventInput for clarity
            int *statusPtr = nullptr; // Pointers (Ch 5)
            break; // temporary
        }

    // Temporary exit to avoid infinite loop
    systemRunning = false;


}