# 🏛️ AASTU Hall & Event Booking Management System

**Course:** Fundamentals of Programming I [SWEG2103]  
**Department:** Software Engineering, Addis Ababa Science and Technology University (AASTU)  
**Version:** 6.6 (Final Release)  
**Status:** ✅ Completed

---

## 📖 Project Overview
The **AASTU Hall and Event Booking Management System** is a software solution designed to digitize the manual process of reserving university halls. 

Currently, hall reservations rely on paper forms and verbal requests, leading to issues like **double-booking**, **misplaced information**, and **time clashes**. This project solves these problems by providing a centralized C++ platform where:
* **Administrators** can review, approve, or cancel requests.
* **Club Leaders & Students** can check availability and request venues instantly.
* **Guests** can view the live schedule of upcoming events but cannot edit data.

---

## ⚙️ Key Features

### 1. Multi-Role Authentication
* **Secure Login:** Username/Password verification using Parallel Arrays.
* **Role Logic:** * **Admins:** Full control (Approve/Reject requests, Force Cancel).
    * **Organizers:** Can request bookings and edit their own event names.
    * **Guests:** Read-only access to view the schedule.

### 2. Smart Booking Workflow
* **Status System:** Events start as **[PENDING]** when requested by students.
* **Conflict Detection:** Automatically prevents double-booking by checking the hall status before confirming.
* **Approval System:** Admins must approve pending requests to change them to **[APPROVED]**.

### 3. Robust Input Validation (Crash-Proof)
* **Anti-Flicker System:** The system automatically catches invalid inputs (like typing letters instead of numbers).
* **Buffer Safety:** Uses `cin.ignore` and `clear` to prevent infinite loops.
* **Overflow Protection:** Prevents users from typing usernames longer than the database allows.

### 4. Admin Dashboard
* **Approve/Reject:** Admins can view pending requests and decide to finalize or delete them.
* **Privileged Access:** Only Admins can cancel events that belong to other users.

---

## 🛠️ Technical Implementation
This project strictly adheres to the **Chapters 1–5 Syllabus**, demonstrating mastery of core C++ concepts without relying on advanced libraries like Vectors or Classes.

* **Data Structures:** * **Parallel Arrays:** Used to simulate a database for Users, Passwords, and Roles (`char dbUsers[][]`).
    * **Multi-Dimensional Arrays:** A `3x4` grid (`int schedule[3][4]`) manages hall status and time slots.
* **Formatting:** * **iomanip:** Uses `setw()` and `left` alignment to create a clean, table-like dashboard in the console.
* **Memory Management:** * **Pointers:** Used efficiently to modify booking statuses directly in memory.
* **String Manipulation:** * **C-Strings:** Uses `<cstring>` for `strcpy` (assigning data) and `strcmp` (verifying credentials).
* **Flow Control:** * **Nested Loops:** Manages the main menu and authentication layers.
    * **Switch Cases:** Handles user menu selection efficiently.

---

## 🚀 How to Run
1.  Clone the repository:
    ```bash
    git clone [https://github.com/Illusionsp/AASTU-Hall-Booking-System](https://github.com/Illusionsp/AASTU-Hall-Booking-System)
    ```
2.  Open the project in **Code::Blocks**, **Dev-C++**, or **VS Code**.
3.  Compile and Run `main.cpp`.
4.  **Default Credentials for Testing:**

| Role | Username | Password | Notes |
| :--- | :--- | :--- | :--- |
| **Admin** | `admin` | `admin123` | Full Access (Approve/Reject) |
| **Organizer** | `club` | `1234` | Can Request Bookings |
| **Registration Key** | -- | `2024` | Required to register as new Admin |

---

## 📂 Project Structure
* **`HallSystem_Final.cpp`**: The complete source code.
* **`README.md`**: Project documentation.

---

*"This project helps us in improving our programming skills, specifically C++, and using our skills for practical campus needs."*