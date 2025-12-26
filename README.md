# 🏛️ AASTU Hall & Event Booking Management System

**Course:** Fundamentals of Programming I [SWEG2103]  
**Department:** Software Engineering, Addis Ababa Science and Technology University (AASTU)  
**Status:** ✅ Completed (Final Project)

---

## 📖 Project Overview
[cite_start]The **AASTU Hall and Event Booking Management System** is a software solution designed to digitize the manual process of reserving university halls[cite: 29, 38]. 

[cite_start]Currently, hall reservations rely on paper forms and verbal requests, leading to issues like **double-booking**, **misplaced information**, and **time clashes**[cite: 36, 45, 47]. This project solves these problems by providing a centralized C++ platform where:
* [cite_start]**Administrators** can review, approve, or cancel requests[cite: 39].
* [cite_start]**Club Leaders & Students** can check availability and book venues instantly[cite: 54].
* [cite_start]**Guests** can view the schedule of upcoming events[cite: 77].


## ⚙️ Key Features

### [cite_start]1. Multi-Role Authentication [cite: 71, 130]
* **Secure Login:** Username/Password verification.
* **Role Logic:** * **Admins:** Full control (Cancel/Edit).
    * **Students:** Can book and edit their own events.
    * **Guests:** Read-only access to the schedule.

### [cite_start]2. Smart Booking Engine [cite: 85, 135]
* **Conflict Detection:** Automatically prevents double-booking by checking the status of 2D arrays before confirming a reservation.
* **Instant Updates:** Updates the "Live Schedule" immediately after a successful booking.

### [cite_start]3. Admin Dashboard [cite: 120, 124]
* **Cancellation:** Admins can force-cancel events to free up slots.
* **Modification:** Edit event names or details without deleting the reservation.

### [cite_start]4. Data & Statistics [cite: 126]
* **Visual Schedule:** A formatted 2D grid displaying all halls and time slots.
* **Occupancy Report:** Calculates the percentage of booked slots vs. free slots.
* **Search:** Linear search algorithm to find events by Club Name.

---

## 🛠️ Technical Implementation
[cite_start]This project strictly adheres to the **Chapters 1–5 Syllabus**, demonstrating mastery of core C++ concepts without relying on advanced libraries[cite: 40, 145].

* **Data Structures:** * **Parallel Arrays:** Used to simulate a database for Users, Passwords, and Roles.
    * **Multi-Dimensional Arrays:** A `3x4` grid (`int schedule[3][4]`) manages hall status.
* [cite_start]**Memory Management:** * **Pointers & Pass-by-Address:** Used in `bookHall()` to directly modify data in the main memory[cite: 145].
* **String Manipulation:** * **C-Strings:** Uses `<cstring>` for `strcpy` (copying data) and `strcmp` (password verification).
* **Flow Control:** * **Do-While Loops:** Powers the robust menu system.
    * [cite_start]**Input Validation:** `cin` error checking prevents crashes from invalid inputs[cite: 161].

---

## 🚀 How to Run
1.  Clone the repository:
    ```bash
    git clone [https://github.com/YourUsername/AASTU-Hall-Booking-System.git](https://github.com/YourUsername/AASTU-Hall-Booking-System.git)
    ```
2.  [cite_start]Open the project in **Code::Blocks**, **Dev-C++**, or **VS Code**[cite: 142].
3.  Compile and Run `main.cpp`.
4.  **Default Credentials for Testing:**
    * **Admin User:** `admin` | **Pass:** `admin123`
    * [cite_start]**Master Key (for registration):** `2024` [cite: 131]

---

## 📂 Project Structure
* **`main.cpp`**: The complete source code, modularized into specific zones for each team member to avoid merge conflicts.
* **`README.md`**: Project documentation.

---

[cite_start]*"This project helps us in improving our programming skills, specifically C++, and using our skills for practical campus needs."* [cite: 171]