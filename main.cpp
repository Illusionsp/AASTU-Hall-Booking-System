

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <limits>

using namespace std;

const int NUM_HALLS = 3;
const int NUM_SLOTS = 4;
const int NAME_LEN = 30;
const int MAX_USERS = 20;

int main() {
    char dbUsers[MAX_USERS][20] = {"admin", "club"};
    char dbPass[MAX_USERS][20]  = {"admin123", "1234"};
    char dbRoles[MAX_USERS][20] = {"admin", "organizer"}; 
    int userCount = 2; 

    const char HALL_NAMES[NUM_HALLS][20] = {"Old Graduation", "Blue Carpet", "Red Carpet"};
    const int HALL_CAPACITY[NUM_HALLS] = {500, 200, 100}; 
    const char TIME_SLOTS[NUM_SLOTS][20] = {"08:00-10:00", "10:00-12:00", "14:00-16:00", "16:00-18:00"};

    int schedule[NUM_HALLS][NUM_SLOTS] = {0}; 
    int bookingOwner[NUM_HALLS][NUM_SLOTS]; 
    char bookings[NUM_HALLS][NUM_SLOTS][NAME_LEN];

    for(int i=0; i<NUM_HALLS; i++) {
        for(int j=0; j<NUM_SLOTS; j++) {
            strcpy(bookings[i][j], "---");
            bookingOwner[i][j] = -1;
        }
    }

    schedule[0][1] = 2; 
    strcpy(bookings[0][1], "Graduation Day");
    bookingOwner[0][1] = 0;

    char currentUserRole[20] = ""; 
    int currentUserId = -1;
    bool loggedIn = false;
    bool systemRunning = true; 

    while (systemRunning) {
        while (!loggedIn && systemRunning) {
            #ifdef _WIN32
                system("cls");
            #else
                system("clear");
            #endif

            int authChoice;
            cout << "\n\t==============================================\n";
            cout << "\t   AASTU HALL MANAGEMENT SYSTEM       \n";
            cout << "\t==============================================\n";
            cout << "\t1. Login\n";
            cout << "\t2. Register (New User)\n"; 
            cout << "\t3. View as Guest\n";
            cout << "\t4. Exit\n";
            cout << "\tSelect: ";
            
            while(!(cin >> authChoice)) {
                cout << "\tInvalid. Please enter a number: ";
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            if (authChoice == 1) {
                char u[20], p[20];
                bool found = false;
                cout << "\n\t--- LOGIN ---\n";
                cout << "\tUsername: "; cin >> setw(19) >> u;
                cout << "\tPassword: "; cin >> setw(19) >> p;
                
                for (int i = 0; i < userCount; i++) {
                    if (strcmp(dbUsers[i], u) == 0 && strcmp(dbPass[i], p) == 0) {
                        strcpy(currentUserRole, dbRoles[i]); 
                        currentUserId = i; 
                        found = true;
                        loggedIn = true; 
                        break;
                    }
                }
                if(!found) {
                    cout << "\n\t[ERROR] Wrong credentials.\n";
                    cin.ignore(); cin.get();
                }

            } else if (authChoice == 2) {
                if (userCount >= MAX_USERS) {
                    cout << "\n\t[ERROR] Database Full.\n";
                    cin.ignore(); cin.get();
                } else {
                    cout << "\n\t--- REGISTER ---\n";
                    char tempUser[20];
                    char tempPass[20];
                    char tempRole[20];
                    
                    bool exists = false;
                    cout << "\tNew Username: "; cin >> setw(19) >> tempUser;
                    
                    for(int k=0; k<userCount; k++) {
                        if(strcmp(dbUsers[k], tempUser) == 0) {
                            exists = true; 
                            break; 
                        }
                    }

                    if(exists) {
                        cout << "\t[ERROR] User already exists!\n";
                        cin.ignore(); cin.get();
                    } else {
                        cout << "\tNew Password: "; cin >> setw(19) >> tempPass;
                        
                        cout << "\t1. Event Organizer\n";
                        cout << "\t2. Admin (Requires Key)\n";
                        cout << "\tChoice: ";
                        int roleChoice; 
                        while(!(cin >> roleChoice)) { 
                            cout << "\tInvalid number: "; cin.clear(); cin.ignore(1000, '\n'); 
                        }

                        bool roleApproved = true;
                        if(roleChoice == 1) strcpy(tempRole, "organizer");
                        else if(roleChoice == 2) {
                            char key[20];
                            cout << "\tMaster Key: "; cin >> setw(19) >> key;
                            if(strcmp(key, "2024") == 0) strcpy(tempRole, "admin");
                            else { 
                                cout << "\t[DENIED] Wrong Key.\n"; 
                                roleApproved = false;
                                cin.ignore(); cin.get();
                            }
                        } else strcpy(tempRole, "organizer");
                        
                        if(roleApproved) {
                            strcpy(dbUsers[userCount], tempUser);
                            strcpy(dbPass[userCount], tempPass);
                            strcpy(dbRoles[userCount], tempRole);
                            userCount++;
                            cout << "\t[SUCCESS] Registered.\n";
                            cin.ignore(); cin.get();
                        }
                    }
                }
            } else if (authChoice == 3) {
                strcpy(currentUserRole, "guest");
                currentUserId = -1; 
                loggedIn = true;
            } else if (authChoice == 4) {
                systemRunning = false;
            }
        }

        int menuChoice;
        while (loggedIn && systemRunning) {
            #ifdef _WIN32
                system("cls");
            #else
                system("clear");
            #endif

            cout << "\n  USER: " << currentUserRole << " (ID: " << currentUserId << ")\n\n";
            
            cout << "  " << left << setw(22) << "HALL INFO"; 
            for(int j=0; j<NUM_SLOTS; j++) {
                cout << "[" << j << "] " << setw(13) << TIME_SLOTS[j] << "   "; 
            }
            cout << "\n";

            cout << "  " << string(90, '-') << "\n";

            for(int i=0; i<NUM_HALLS; i++) {
                cout << "  " << i << ". " << left << setw(19) << HALL_NAMES[i];
                
                for(int j=0; j<NUM_SLOTS; j++) {
                     cout << left << setw(18); 
                     
                     if(schedule[i][j] == 0) {
                        cout << "[FREE]"; 
                    } 
                    else if(schedule[i][j] == 1) {
                        if(bookingOwner[i][j] == currentUserId) cout << "[MY REQUEST]";
                        else cout << "[WAITING]";
                    }
                    else {
                        if(strlen(bookings[i][j]) > 16) {
                            char shortName[17];
                            strncpy(shortName, bookings[i][j], 13);
                            shortName[13] = '.'; shortName[14] = '.'; shortName[15] = '.'; shortName[16] = '\0';
                            cout << shortName;
                        } else {
                            cout << bookings[i][j];
                        }
                    }
                }
                cout << "\n";
                cout << "  (Cap: " << setw(4) << HALL_CAPACITY[i] << ")\n\n"; 
            }

            cout << "  " << string(90, '-') << "\n";
            cout << "  1. Request Booking     2. Edit Event Name\n";
            cout << "  3. Cancel My Booking   ";
            
            if(strcmp(currentUserRole, "admin") == 0) cout << "4. [ADMIN] Approve/Reject\n";
            else cout << "4. (Admin Only)\n";
            
            cout << "  5. Logout\n";
            cout << "  " << string(90, '-') << "\n";
            
            cout << "  Select: ";

            while(!(cin >> menuChoice)) {
                cout << "  Invalid input. Please enter a number: ";
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            int hIndex, tIndex;
            int *statusPtr = nullptr; 

            switch(menuChoice) {
                case 1: 
                    if (currentUserId == -1) { 
                         cout << "\n  [ERROR] Guests cannot book.\n";
                    } else { 
                        cout << "\n  --- REQUEST BOOKING ---\n";
                        cout << "  Enter Hall ID (0-" << NUM_HALLS-1 << "): "; 
                        while(!(cin >> hIndex)) { cout << "  Invalid. Number only: "; cin.clear(); cin.ignore(1000, '\n'); }

                        cout << "  Enter Slot ID (0-" << NUM_SLOTS-1 << "): "; 
                        while(!(cin >> tIndex)) { cout << "  Invalid. Number only: "; cin.clear(); cin.ignore(1000, '\n'); }

                        if(hIndex >= 0 && hIndex < NUM_HALLS && tIndex >= 0 && tIndex < NUM_SLOTS) {
                            statusPtr = &schedule[hIndex][tIndex]; 
                            if (*statusPtr != 0) cout << "\n  [FAILED] Slot is not free.\n";
                            else {
                                cout << "  Enter Event Name: "; 
                                cin.ignore(); 
                                cin.getline(bookings[hIndex][tIndex], NAME_LEN);
                                bookingOwner[hIndex][tIndex] = currentUserId; 

                                if(strcmp(currentUserRole, "admin") == 0) {
                                    *statusPtr = 2; 
                                    cout << "\n  [SUCCESS] Booking Approved.\n";
                                } else {
                                    *statusPtr = 1; 
                                    cout << "\n  [SUCCESS] Request sent! Status: PENDING.\n";
                                }
                            }
                        } else { cout << "  [ERROR] Invalid ID.\n"; }
                    }
                    break;

                case 2:
                    if (currentUserId == -1) {
                         cout << "\n  [ERROR] Guests cannot edit events.\n";
                    } else {
                        cout << "\n  --- EDIT EVENT NAME ---\n";
                        cout << "  Enter Hall ID: "; 
                        while(!(cin >> hIndex)) { cout << "  Invalid. Number only: "; cin.clear(); cin.ignore(1000, '\n'); }

                        cout << "  Enter Slot ID: "; 
                        while(!(cin >> tIndex)) { cout << "  Invalid. Number only: "; cin.clear(); cin.ignore(1000, '\n'); }

                        if(hIndex >= 0 && hIndex < NUM_HALLS && tIndex >= 0 && tIndex < NUM_SLOTS) {
                            if(schedule[hIndex][tIndex] == 0) cout << "\n  [ERROR] Slot is empty.\n";
                            else if (bookingOwner[hIndex][tIndex] == currentUserId || strcmp(currentUserRole, "admin") == 0) {
                                cout << "  New Name: ";
                                cin.ignore();
                                cin.getline(bookings[hIndex][tIndex], NAME_LEN);
                                cout << "\n  [SUCCESS] Name Updated.\n";
                            } else cout << "\n  [ACCESS DENIED] Not your booking.\n";
                        }
                    }
                    break;

                case 3:
                    if (currentUserId == -1) {
                         cout << "\n  [ERROR] Guests cannot cancel events.\n";
                    } else {
                        cout << "\n  --- CANCEL BOOKING ---\n";
                        cout << "  Enter Hall ID: "; 
                        while(!(cin >> hIndex)) { cout << "  Invalid. Number only: "; cin.clear(); cin.ignore(1000, '\n'); }

                        cout << "  Enter Slot ID: "; 
                        while(!(cin >> tIndex)) { cout << "  Invalid. Number only: "; cin.clear(); cin.ignore(1000, '\n'); }

                        if(hIndex >= 0 && hIndex < NUM_HALLS && tIndex >= 0 && tIndex < NUM_SLOTS) {
                            if(schedule[hIndex][tIndex] == 0) cout << "\n  [ERROR] Slot is empty.\n";
                            else if (bookingOwner[hIndex][tIndex] == currentUserId || strcmp(currentUserRole, "admin") == 0) {
                                schedule[hIndex][tIndex] = 0;       
                                bookingOwner[hIndex][tIndex] = -1;  
                                strcpy(bookings[hIndex][tIndex], "---"); 
                                cout << "\n  [SUCCESS] Cancelled.\n";
                            } else cout << "\n  [ACCESS DENIED] Not your booking.\n";
                        }
                    }
                    break;

                case 4:
                    if (strcmp(currentUserRole, "admin") != 0) cout << "\n  [ACCESS DENIED] Admins Only.\n";
                    else {
                        cout << "\n  --- APPROVE / REJECT ---\n";
                        cout << "  Enter Hall ID: "; 
                        while(!(cin >> hIndex)) { cout << "  Invalid. Number only: "; cin.clear(); cin.ignore(1000, '\n'); }

                        cout << "  Enter Slot ID: "; 
                        while(!(cin >> tIndex)) { cout << "  Invalid. Number only: "; cin.clear(); cin.ignore(1000, '\n'); }

                        if(hIndex >= 0 && hIndex < NUM_HALLS && tIndex >= 0 && tIndex < NUM_SLOTS) {
                            if (schedule[hIndex][tIndex] == 1) { 
                                cout << "  Event: " << bookings[hIndex][tIndex] << "\n";
                                cout << "  1. Approve   2. Reject\n  Choice: ";
                                int decision; 
                                while(!(cin >> decision)) { cout << "  Invalid. Number only: "; cin.clear(); cin.ignore(1000, '\n'); }
                                
                                if(decision == 1) {
                                    schedule[hIndex][tIndex] = 2; 
                                    cout << "  [APPROVED]\n";
                                } else {
                                    schedule[hIndex][tIndex] = 0; 
                                    bookingOwner[hIndex][tIndex] = -1;
                                    strcpy(bookings[hIndex][tIndex], "---");
                                    cout << "  [REJECTED]\n";
                                }
                            } else cout << "  [INFO] Not pending.\n";
                        }
                    }
                    break;

                case 5: 
                    cout << "\n  Logging out...\n";
                    loggedIn = false; 
                    break;
                    
                default:
                    cout << "\n  [ERROR] Invalid Option.\n";
            }

            if(loggedIn) {
                cout << "\n  Press Enter to continue...";
                cin.ignore(); cin.get();
            }
        }
    }
    return 0;
}
