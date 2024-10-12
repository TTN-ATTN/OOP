#include<bits/stdc++.h>
using namespace std;

/**
 * Structure to represent a Date: day, month, year.
 */
struct Date {
    int day = 1;
    int month = 1;
    int year = 2000;
};

/**
 * Structure to represent an Hour: hour, minute.
 */
struct Hour {
    int hour = 0;
    int minute = 0;
};

/**
 * Structure to represent a Flight: id, departure date, departure hour, departure place, destination.
 */
struct Flight {
    string id;
    Date depart_date;
    Hour depart_hour;
    string departure;
    string destination;
};

// ========================= data handling ========================= //

/**
 * Trim a string.
 * Input: str - string
 * Output: trimmed string
 */
string trim(const string &str) {
    size_t first = str.find_first_not_of(' ');
    if (first == string::npos) {
        return "";
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, last - first + 1);
}


/**
 * Check if a string is a valid id.
 * Input: id - string
 * Output: true if id is invalid, false otherwise
 */
bool invalid_id(string id) {
    for(char c: id) {
        if(!isalnum(c) || c == ' ') {
            return true;
        }
    }
    return id.size() > 5 || id.empty();
}

/**
 * Check if a year is a leap year.
 * Input: year - integer
 * Output: true if year is a leap year, false otherwise
 */
bool leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

/**
 * Check if a date is invalid.
 * Input: day, month, year - integers
 * Output: true if date is invalid, false otherwise
 */
bool invalid_date(int day, int month, int year) {
    if (day < 1 || month < 1 || month > 12 || year < 1) {
        return true;
    }
    if (month == 2) {
        return day > (leap_year(year) ? 29 : 28);
    }
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return day > 30;
    }
    return day > 31;
}

/**
 * Check if an hour is invalid.
 * Input: hour, minute - integers
 * Output: true if hour is invalid, false otherwise
 */
bool invalid_hour(int hour, int minute) {
    return hour < 0 || hour > 24 || minute < 0 || minute > 60;
}

/**
 * Check if a place is invalid.
 * Input: place - string
 * Output: true if place is invalid, false otherwise
 */
bool invalid_place(string place) {
    for(char c: place) {
        if((c > 'z' || c < 'A') && c != ' ')
            return true;
    }
    return place.size() > 20;
}

// ========================= input =========================//

/**
 * Read departure place from user.
 * Input: none
 * Output: departure place
 */
string get_departure() {
    string departure;
    cout << "Departure place: ";
    getline(cin, departure);
    departure = trim(departure);
    while(invalid_place(departure)) {
        cout << "Invalid departure place!\nDeparture place: ";
        getline(cin, departure);
        departure = trim(departure);
    }
    return departure;
}

/**
 * Get destination from user.
 * Input: none
 * Output: destination
 */
string get_destination() {
    string destination;
    cout << "Destination: ";
    getline(cin, destination);
    destination = trim(destination);
    while(invalid_place(destination)) {
        cout << "Invalid destination!\nDestination: ";
        getline(cin, destination);
        destination = trim(destination);
    }
    return destination;
}

/**
 * Read date from user
 * Input: none
 * Output: integer vector containing day, month, year
 */
vector<int> get_date() {
    int day, month, year;
    cout << "Day: ";
    cin >> day;
    cout << "Month: ";
    cin >> month;
    cout << "Year: ";
    cin >> year;
    while(invalid_date(day, month, year)) {
        cout << "Invalid date!\n";
        cout << "Day: ";
        cin >> day;
        cout << "Month: ";
        cin >> month;
        cout << "Year: ";
        cin >> year;
    }
    return {day, month, year};
}

/**
 * Set to store flight ids.
 */
set<string> ids;

/**
 * Input a flight.
 * Input: none
 * Output: Flight object
 */
Flight input() {
    Flight flight;
    string id;
    int hour, minute;
    cin.ignore();
    cout << "Enter flight ID: ";
    getline(cin, id);
    while(invalid_id(id)) {
        cout << "Invalid id!\nEnter flight ID: ";
        getline(cin, id);
    }
    while(ids.find(id) != ids.end()) {
        cout << "Flight ID already existed!\n Enter a different ID: ";
        cin >> id;
    }
    flight.id = id;
    ids.insert(id);

    cout << "Enter flight departure date!\n";
    auto date = get_date();

    cout << "Enter flight departure hour!\n";
    cout << "Hour: ";
    cin >> hour;
    cout << "Minute: ";
    cin >> minute;
    while(invalid_hour(hour, minute)) {
        cout << "Invalid departure hour!\n";
        cout << "Hour: ";
        cin >> hour;
        cout << "Minute: ";
        cin >> minute;
    }

    flight.depart_date.day = date[0];
    flight.depart_date.month = date[1];
    flight.depart_date.year = date[2];
    flight.depart_hour.hour = hour;
    flight.depart_hour.minute = minute;
    cin.ignore();
    flight.departure = get_departure();
    flight.destination = get_destination();

    return flight;
}

// ========================= flight management ========================= //

/**
 * Format a number to have 2 digits.
 * Input: num - integer
 * Output: 2-digit string
 */
string format(int num) {
    return num < 10 ? "0" + to_string(num) : to_string(num);
}

/**
 * Print flight information.
 * Input: Flight object
 * Output: flight information
 */
void flight_info(Flight flight) {
    cout << "\nFlight information:" << endl;
    cout << "Flight ID: " << flight.id << endl;
    cout << "Departure date: " << format(flight.depart_date.day) << "/" << format(flight.depart_date.month) << "/" << flight.depart_date.year << endl;
    cout << "Departure hour: " << format(flight.depart_hour.hour) << ":" << format(flight.depart_hour.minute) << endl;
    cout << "Departure place: " << flight.departure << endl;
    cout << "Destination: " << flight.destination << endl;
}

/**
 * List all flights.
 * Input: a vector of Flight objects
 * Output: information of all flights
 */
void list_all(vector<Flight> flights) {
    for(Flight flight: flights) {
        flight_info(flight);
    }
}

/**
 * Sort flight list by date and hour, from the earliest to the latest.
 * Input: a vector of Flight objects
 * Output: none
 */
void sort_by_time(vector<Flight> &flights) {
    sort(flights.begin(), flights.end(), [](Flight a, Flight b) {
        if(a.depart_date.year != b.depart_date.year) {
            return a.depart_date.year < b.depart_date.year;
        }
        if(a.depart_date.month != b.depart_date.month) {
            return a.depart_date.month < b.depart_date.month;
        }
        if(a.depart_date.day != b.depart_date.day) {
            return a.depart_date.day < b.depart_date.day;
        }
        if(a.depart_hour.hour != b.depart_hour.hour) {
            return a.depart_hour.hour < b.depart_hour.hour;
        }
        return a.depart_hour.minute < b.depart_hour.minute;
    });
}

/**
 * Search for a flight by id.
 * Input: a vector of Flight objects
 * Output: flight information if found, "Flight not found!" otherwise
 */
void search_by_id(vector<Flight> flights) {
    string id;
    cout << "\nEnter flight id to search: ";
    cin >> id;
    for(Flight flight: flights) {
        if(flight.id == id) {
            flight_info(flight);
            return;
        }
    }
    cout << "Flight not found!\n";
}

/**
 * Search for a flight by departure place.
 * Input: a vector of Flight objects
 * Output: flight information if found, "Flight not found!" otherwise
 */
void search_by_departure(vector<Flight> flights) {
    cout << "\nEnter departure place to search!\n";
    string expected = get_departure();
    transform(expected.begin(), expected.end(), expected.begin(), ::tolower);
    for(Flight flight: flights) {
        string actual = flight.departure;
        transform(actual.begin(), actual.end(), actual.begin(), ::tolower);
        if(actual == expected) {
            flight_info(flight);
        }
    }
}

/**
 * Search for a flight by destination.
 * Input: a vector of Flight objects
 * Output: flight information if found, "Flight not found!" otherwise
 */
void search_by_destination(vector<Flight> flights, bool &found) {
    cout << "\nEnter destination to search!\n";
    string expected = get_destination();
    transform(expected.begin(), expected.end(), expected.begin(), ::tolower);
    for(Flight flight: flights) {
        string actual = flight.destination;
        transform(actual.begin(), actual.end(), actual.begin(), ::tolower);
        if(actual == expected) {
            flight_info(flight);
            found = true;
        }
    }
}

/**
 * List all flights to a destination on a specific date.
 * Input: a vector of Flight objects
 * Output: flights information if found, "No flights found!" otherwise
 */
void list_all_dest_in_date(vector<Flight> flights) {
    cout << "\nEnter date to search!\n";
    auto date = get_date();
    cin.ignore();
    bool found_date = false, found = false;

    for(Flight flight: flights) {
        if(flight.depart_date.day == date[0] && flight.depart_date.month == date[1] && flight.depart_date.year == date[2]) {
            found_date = true;
        }
    }

    if(found_date)
        search_by_destination(flights, found);

    if(!found) {
        cout << "No flights found!\n";
    }
}

/**
 * Count the number of flights from a departure place to a destination.
 * Input: a vector of Flight objects
 * Output: number of flights
 */
void count_flights_p2p(vector<Flight> flights) {
    cout << endl;
    string departure = trim(get_departure());
    string destination = trim(get_destination());

    int count = 0;

    for(Flight flight: flights) {
        if(flight.departure == departure && flight.destination == destination) {
            count++;
        }
    }
    if(count)
        cout << "Number of flight(s) from " << departure << " to " << destination << ": " << count << endl;
    else
        cout << "Not found!";
}

/**
 * Options to work with flights.
 * Input: vector of Flight objects
 * Output: results from user's option
 */
void options(vector<Flight> flights) {
    while(true) {
        bool found = false;
        cout << "\nFlight analysis options!";
        cout << "1. List all flights" << endl;
        cout << "2. Search by id" << endl;
        cout << "3. Search by departure place" << endl;
        cout << "4. Search by destination" << endl;
        cout << "5. List all flights to a destination in a specific date" << endl;
        cout << "6. Count the number of flights from a departure place to a destination" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        // cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch(choice) {
            case 1:
                list_all(flights);
                break;
            case 2:
                search_by_id(flights);
                break;
            case 3:
                cin.ignore();
                search_by_departure(flights);
                break;
            case 4:
                cin.ignore();
                search_by_destination(flights, found);
                break;
            case 5:
                list_all_dest_in_date(flights);
                break;
            case 6:
                cin.ignore();
                count_flights_p2p(flights);
                break;
            case 7:
                exit(0);
            default:
                cout << "Invalid choice!\n";
        }
    }
}

int main() {
    vector<Flight> flights;
    int n;
    cout << "Enter number of flights: ";
    cin >> n;
    for(int i = 0; i < n; i++) {
        cout << "\nFlight " << i + 1 << "!\n";
        flights.push_back(input());
    }
    sort_by_time(flights);
    options(flights);
    return 0;
}