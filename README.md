# 🏛️ AASTU Hall & Event Booking Management System

**Course:** Fundamentals of Programming I [SWEG2103]  
**Department:** Software Engineering, Addis Ababa Science and Technology University (AASTU)  
**Status:** ✅ Completed (Final Project)

---

## 📖 Project Overview
The **AASTU Hall and Event Booking Management System** is a software solution designed to digitize the manual process of reserving university halls. 

Currently, hall reservations rely on paper forms and verbal requests, leading to issues like **double-booking**, **misplaced information**, and **time clashes**. This project solves these problems by providing a centralized C++ platform where:
* **Administrators** can review, approve, or cancel requests.
* **Club Leaders & Students** can check availability and book venues instantly.
* **Guests** can view the schedule of upcoming events.


## ⚙️ Key Features

### 1. Multi-Role Authentication
* **Secure Login:** Username/Password verification.
* **Role Logic:** * **Admins:** Full control (Cancel/Edit).
    * **Students:** Can book and edit their own events.
    * **Guests:** Read-only access to the schedule.

### 2. Smart Booking Engine
* **Conflict Detection:** Automatically prevents double-booking by checking the status of 2D arrays before confirming a reservation.
* **Instant Updates:** Updates the "Live Schedule" immediately after a successful booking.

### 3. Admin Dashboard
* **Cancellation:** Admins can force-cancel events to free up slots.
* **Modification:** Edit event names or details without deleting the reservation.

### 4. Data & Statistics
* **Visual Schedule:** A formatted 2D grid displaying all halls and time slots.
* **Occupancy Report:** Calculates the percentage of booked slots vs. free slots.
* **Search:** Linear search algorithm to find events by Club Name.

---

## 🛠️ Technical Implementation
This project strictly adheres to the **Chapters 1–5 Syllabus**, demonstrating mastery of core C++ concepts without relying on advanced libraries.

* **Data Structures:** * **Parallel Arrays:** Used to simulate a database for Users, Passwords, and Roles.
    * **Multi-Dimensional Arrays:** A `3x4` grid (`int schedule[3][4]`) manages hall status.
* **Memory Management:** * **Pointers & Pass-by-Address:** Used in `bookHall()` to directly modify data in the main memory.
* **String Manipulation:** * **C-Strings:** Uses `<cstring>` for `strcpy` (copying data) and `strcmp` (password verification).
* **Flow Control:** * **Do-While Loops:** Powers the robust menu system.
    * **Input Validation:** `cin` error checking prevents crashes from invalid inputs.

---

## 🚀 How to Run
1.  Clone the repository:
    ```bash
    git clone https://github.com/Illusionsp/AASTU-Hall-Booking-System
    ```
2.  Open the project in **Code::Blocks**, **Dev-C++**, or **VS Code**.
3.  Compile and Run `main.cpp`.
4.  **Default Credentials for Testing:**
    * **Admin User:** `admin` | **Pass:** `admin123`
    * **Master Key (for registration):** `2024`

---

## 📂 Project Structure
* **`main.cpp`**: The complete source code, modularized into specific zones for each team member to avoid merge conflicts.
* **`README.md`**: Project documentation.

---

*"This project helps us in improving our programming skills, specifically C++, and using our skills for practical campus needs."*