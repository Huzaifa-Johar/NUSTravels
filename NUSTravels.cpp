/*************NUSTravels************** */

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cctype>



using namespace std;

struct Ride { 
    string name;
    string origin;
    string dropoff;
    string time;
    int    no_ofseats;
    float  fare;
};


//Function declaration.
void Interface();
void offerride(Ride& R);
void bookride(Ride& R);
void cancelride();
void view_all();
bool goBack();
string toUpper(string s);


int main() {

    cout << "|***WELCOME TO NUSTravels***|\n";
    int choice;

    do {
        Interface();
        cout << "Enter your choice: \n";
        cin >> choice;
        cout << endl;

        if (choice == 1) {
            if (goBack()) continue;
            Ride R;
            offerride(R);
        }
        else if (choice == 2) {
            if (goBack()) continue;
            Ride R1;
            bookride(R1);
        }
        else if (choice == 3) {
            if (goBack()) continue;
            view_all();
        }
        else if (choice == 4) {
            if (goBack()) continue;
            cancelride();
        }
        else if (choice == 5) {
            cout << "Thankyou for using NUSTravels!";
        }
        else {
            cout << "Invalid Output\n";
        }

    } while (choice != 5);

    return 0;
}

void Interface() {

    cout << "Please select an option: \n\n";
    cout << "1. Offer Ride\n";
    cout << "2. Book Ride\n";
    cout << "3. View All Rides\n";
    cout << "4. Cancel Ride\n";
    cout << "5. Exit\n";
}


void offerride(Ride& R) {

    cin.ignore(1000, '\n');

    cout << "Name: ";
    getline(cin, R.name);

    cout << "origin: ";
    getline(cin, R.origin);
    R.origin = toUpper(R.origin);

    cout << "Drop-off point: ";
    getline(cin, R.dropoff);
    R.dropoff = toUpper(R.dropoff);

    cout << "Time: ";
    getline(cin, R.time);

    cout << "Seats available: ";
    cin >> R.no_ofseats;

    cout << "Fare: ";
    cin >> R.fare;

    ofstream out("Ride.txt", ios::app);
    out << R.name << "," << R.origin << "," << R.dropoff << ","
        << R.time << "," << R.no_ofseats << "," << R.fare << endl;
    out.close();

    cout << "\nRide Offered Successfully!\n";
}


void bookride(Ride& R) {

    ifstream in("Ride.txt");
    if (!in) {
        cout << "No rides available!\n";
        return;
    }

    ofstream temp("Temp.txt");
    string line;

    cout << "\n--- All Rides ---\n";

    while (getline(in, line)) {

        if (line.empty() || line.find(',') == string::npos)
            continue;

        stringstream ss(line);
        string name, origin, dropoff, time, seats, fare;

        getline(ss, name, ',');
        getline(ss, origin, ',');
        getline(ss, dropoff, ',');
        getline(ss, time, ',');
        getline(ss, seats, ',');
        getline(ss, fare);

        cout << "Name: " << name << "\n";
        cout << "Starting Location: " << origin << "\n";
        cout << "Dropoff Location: " << dropoff << "\n";
        cout << "Time: " << time << "\n";
        cout << "Seats: " << seats << "\n";
        cout << "Fare: " << fare << "\n";
        cout << "--------------------\n";
    }

    in.clear();
    in.seekg(0);

    string pickup, destination;
    int bookSeats;

    cin.ignore();
    cout << "Enter the starting point of the ride you want to book: ";
    getline(cin, pickup);
    pickup = toUpper(pickup);

    cout << "Enter the dropoff point of the ride you want to book: ";
    getline(cin, destination);
    destination = toUpper(destination);

    cout << "How many seats do you want to book? ";
    cin >> bookSeats;

    bool booked = false;

    while (getline(in, line)) {

        if (line.empty() || line.find(',') == string::npos)
            continue;

        stringstream ss(line);
        string name, origin, dropoff, time, seats, fare;

        getline(ss, name, ',');
        getline(ss, origin, ',');
        getline(ss, dropoff, ',');
        getline(ss, time, ',');
        getline(ss, seats, ',');
        getline(ss, fare);

        if (origin == pickup && dropoff == destination) {

            int available = stoi(seats);

            if (bookSeats > available) {
                cout << "Not enough seats available!\n";
                temp.close();
                in.close();
                return;
            }

            available -= bookSeats;
            seats = to_string(available);
            booked = true;
        }

        temp << name << "," << origin << "," << dropoff << ","
             << time << "," << seats << "," << fare << endl;
    }

    in.close();
    temp.close();

    remove("Ride.txt");
    rename("Temp.txt", "Ride.txt");

    if (booked)
        cout << "Booking successful!\n";
    else
        cout << "Ride not found!\n";
}



void view_all() {

    ifstream in("Ride.txt");
    if (!in) {
        cout << "No Rides available!\n";
        return;
    }

    string line;
    cout << "****All Rides****\n";

    while (getline(in, line)) {

        stringstream ss(line);
        string name, origin, dropoff, time, seats, fare;

        getline(ss, name, ',');
        getline(ss, origin, ',');
        getline(ss, dropoff, ',');
        getline(ss, time, ',');
        getline(ss, seats, ',');
        getline(ss, fare);

        cout << "Name: " << name << "\n";
        cout << "Starting Location: " << origin << "\n";
        cout << "Dropoff Location: " << dropoff << "\n";
        cout << "Time: " << time << "\n";
        cout << "Seats: " << seats << "\n";
        cout << "Fare: " << fare << "\n";
        cout << "--------------------\n";
    }
}



void cancelride() {

    ifstream in("Ride.txt");
    if (!in) {
        cout << "No rides available!\n";
        return;
    }

    ofstream temp("Temp.txt");
    string line;

    string pickup, destination;
    int cancelSeats;

    cin.ignore(1000,'\n');

    cout << "Enter Ride pickup point to cancel booking: ";
    
    getline(cin, pickup);
    pickup = toUpper(pickup);

    cout << "Enter Ride dropoff point to cancel booking: ";

    getline(cin, destination);
    destination = toUpper(destination);

    cout << "Enter number of seats to cancel: ";
    cin >> cancelSeats;

    bool cancelled = false;

    while (getline(in, line)) {

        if (line.empty())
            continue;

        stringstream ss(line);
        string name, origin, dropoff, time, seats, fare;

        getline(ss, name, ',');
        getline(ss, origin, ',');
        getline(ss, dropoff, ',');
        getline(ss, time, ',');
        getline(ss, seats, ',');
        getline(ss, fare);

        if (origin == pickup && dropoff == destination) {
            int available = stoi(seats);
            available += cancelSeats;
            seats = to_string(available);
            cancelled = true;
        }

        temp << name << "," << origin << "," << dropoff << ","
             << time << "," << seats << "," << fare << endl;
    }

    in.close();
    temp.close();

    remove("Ride.txt");
    rename("Temp.txt", "Ride.txt");

    if (cancelled)
        cout << "Ride booking cancelled successfully!\n";
    else
        cout << "Ride not found!\n";
}


bool goBack() {

    char choice;
    cout << "Go back to main menu? (y/n): ";
    cin >> choice;

    if (choice == 'Y' || choice == 'y')
        return true;
    else
        return false;
}

string toUpper(string s) {

    for (int i = 0; i < s.length(); i++) {
        s[i] = toupper(s[i]);
    }

    return s;
}
