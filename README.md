#  *NUSTravels*  

---

##  **Team Information**
**Project Title:** *NUSTravels*  

**Team Members:**  
- **Muhammad Huzaifa Johar** – *Group Leader*  
- **Muhammad Talal Tahir**   

---

##  **Overview / Problem Description**
- This program simulates a travelling app, where students can share rides with each other inside NUST university.  
- It shows how students can offer rides, book rides, cancel the booked rides and can preview the available bookings.  
- Just like real life, this application allows users to:  
  - Offer a ride.  
  - Book a ride.  
  - Cancel the booked ride.  
  - Preview all the available rides.  
- It also stores the data in a text file, so that the data won't lose and remain there even if program is terminated.
- It imitates the working of a real life Cab booking application.  

---

##  **Program Design / Logic**

###  **Main Struct Used**
- `Ride` → It contains different variables used to offer and book ride.

###  **Main Functions Used**
- `Interface()` → Displays the output on screen.  
- `offerride()` → Allows user to share a ride.
- `bookride()`  → Allows user to book a ride.
- `cancelride()`→ Allows user to cancel a booked ride.
- `view_all()`  → Allows user to view all the available rides.
- `goBack()`    → Allows user to go back to the main interface.

###  **Logic Flow**
- The program starts and asks the user to choose one of the options (i.e. Offer ride, Book ride, View available rides, Cancel ride, Exit).  
- If the user presses **1** it asks the users about some information regarding his/her ride:
	- Name of driver
	- Driver's starting location (the school in which he is currently present)
	- Driver's drop-off location (the destination where the driver is headed)
	- Time of departure
	- Fare
- If the user presses **2** it allows the users to book a suitable ride:
	- Pick up point of the person booking the ride.
	- Destination where the user is headed.
	- Number of seats a person wants to book.
- If the user presses **3** it allows the users to cancel a booked ride:
	- The pick-up point of the booked ride.
	- Drop-off point of the booked ride.
	- Number of seats the user wants to cancel.
- If the user presses **4** it allows the users to view all available ride:
	- It shows the details about all the available rides.
- If the user presses **5** it allows the users to exit the application.

- It stores the information in txt file so that the information remains stored even if the program is terminated.
   
---

##  **Work Distribution** 
- **Huzaifa Johar** – worked as the main coder of the program.  
- **Talal Tahir** – handled the doucmentation and management part.  

---

##  **Future Improvements**
- If we knew about classes, we could make the code easier and simpler to understand.
- It would also help us make the code more organized.