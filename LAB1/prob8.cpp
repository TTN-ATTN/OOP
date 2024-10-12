#include<bits/stdc++.h>
using namespace std;

vector<string> saving_types = {"long-term", "short-term", "no-term"};
set<string> ids;
vector<float> rates = {0.05, 0.02, 0.005};

/**
 * Struct to represent a date: day, month, year.
 */
struct Date {
    int day = 1;
    int month = 1;
    int year = 2000;
};

/**
 * Struct to represent a saving account: account ID, saving type, username, national ID, opening date, account balance.
 */
struct SavingAccount {
    string account_id;
    string type;
    string username;
    string uid;
    Date open_date;
    double account_balance = 0.0;
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
 * Check if an account ID is invalid.
 * Input: id - string
 * Output: true if account ID is invalid, false otherwise
 */
bool invalid_account_id(string id) {
    for(char c: id) {
        if(!isalnum(c) || c == ' ') {
            return true;
        }
    }
    return id.size() > 5 || id.empty();
}

/**
 * Check if a name is invalid.
 * Input: name - string
 * Output: true if name is invalid, false otherwise
 */
bool invalid_name(string name) {
    for(char c: name) {
        if((c > 'z' || c < 'a') && (c < 'A' || c > 'Z') && c != ' ')
            return true;
    }
    return name.size() > 30;
}

/**
 * Check if a national ID is invalid.
 * Input: id - string
 * Output: true if national ID is invalid, false otherwise
 */
bool invalid_uid(string id) {
    for(char c: id) {
        if(c - '0' > 9) {
            return true;
        }
    }
    return id.size() != 9;
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

// ========================= input ========================= //

/**
 * Read date from user.
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
 * Read account balance from user.
 * Input: none
 * Output: account balance as double
 */
double get_balance() {
    double balance = 0.0;
    cout << "Enter account balance: ";
    cin >> balance;
    while(balance < 0) {
        cout << "Invalid amount!\nEnter account balance: ";
        cin >> balance;
    }
    return balance;
}

/**
 * Read account ID from user.
 * Input: none
 * Output: account ID as string
 */
string get_account_id() {
    string id;
    cout << "Enter account ID: ";
    cin >> id;
    id=trim(id);
    while(invalid_account_id(id)) {
        cout << "Invalid ID!\nEnter account ID: ";
        cin >> id;
        id=trim(id);
    }
    while(ids.find(id) != ids.end()) {
        cout << "Account ID already existed!\nEnter a different ID: ";
        cin >> id;
        id=trim(id);
    }
    ids.insert(id);
    return id;
}

/**
 * Read national ID from user.
 * Input: none
 * Output: national ID as string
 */
string get_uid() {
    string id;
    cout << "Enter your national ID: ";
    cin >> id;
    id = trim(id);
    while(invalid_uid(id)) {
        cout << "Invalid ID!\nEnter your national ID: ";
        cin >> id;
        id = trim(id);
    }
    while(ids.find(id) != ids.end()) {
        cout <<"ID already existed!\nEnter your national ID: ";
        cin >> id;
        id = trim(id);
    }
    ids.insert(id);
    return id;
}

/**
 * Read saving type from user.
 * Input: none
 * Output: saving type as string
 */
string get_saving_type() {
    string choice;

    cout << "Choose saving type!\n";
    cout << "1. Long-term saving\n";
    cout << "2. Short-term saving\n";
    cout << "3. No-term saving\n";
    cout << "Enter your choice (long-term/short-term/no-term): ";
    cin >> choice;

    while(choice.size() > 10 || find(saving_types.begin(), saving_types.end(), choice) == saving_types.end()) {
        cout << "Invalid choice!\nEnter your choice (long-term/short-term/no-term): ";
        cin >> choice;
    }

    return choice;
}

/**
 * Read username from user.
 * Input: none
 * Output: username as string
 */
string get_username() {
    string name;
    cout << "Enter username: ";
    getline(cin, name);
    name = trim(name);
    while(invalid_name(name)) {
        cout << "Invalid name!\nEnter username: ";
        getline(cin, name);
        name = trim(name);
    }
    return name;
}

/**
 * Read saving account details from user.
 * Input: none
 * Output: SavingAccount object
 */
SavingAccount input() {
    SavingAccount saving_account;

    saving_account.account_id = get_account_id();
    saving_account.type = get_saving_type();

    cin.ignore();
    saving_account.username = get_username();
    saving_account.uid = get_uid();

    cout << "Account opening date: \n";
    auto date = get_date();
    saving_account.open_date.day = date[0];
    saving_account.open_date.month = date[1];
    saving_account.open_date.year = date[2];

    saving_account.account_balance = get_balance();

    return saving_account;
}

// ========================= account management ========================= //

/**
 * Format date as string.
 * Input: date - Date object
 * Output: formatted date string
 */
string formatted(Date date) {
    string day, month, year;
    day = date.day < 10 ? '0' + to_string(date.day) : to_string(date.day);
    month = date.month < 10 ? '0' + to_string(date.month) : to_string(date.month);
    year = to_string(date.year);
    return day+'/'+month+'/'+year;
}

/**
 * Print account information.
 * Input: account - SavingAccount object
 * Output: account id, saving type, username, national ID, opening date, account balance
 */
void account_info(SavingAccount account) {
    cout << "\nAccount information:\n";
    cout << "Account id: " << account.account_id << endl;
    cout << "Account saving type: " << account.type + " saving"<< endl;
    cout << "Username: " << account.username << endl;
    cout << "User's national ID: " << account.uid << endl;
    cout << "Account opening date: " << formatted(account.open_date) << endl;
    cout << "Account balance: " << fixed << setprecision(2) << account.account_balance << " VND\n";
}

/**
 * Print all interest rates.
 * Input: none
 * Output: all interest rates
 */
void all_rates() {
    cout << "\nInterest rates: \n";
    cout << "1. Long-term saving: " << rates[0]*100 << "%/year\n";
    cout << "2. Short-term saving: " << rates[1]*100 << "%/year\n";
    cout << "3. No-term saving: " << rates[2]*100 << "%/year\n";
}

/**
 * Update interest rate.
 * Input: none
 * Output: updated interest rate
 */
void update_interest() {
    all_rates();

    cout << "Interest type to change: ";
    int type = 0;
    cin >> type;
    while(type > 3 || type < 1) {
        cout << "Invalid choice!\nInterest type to change: ";
        cin >> type;
    }

    float rate = 0;
    cout << "Enter new interest (%/year): ";
    cin >> rate;
    rates[type - 1] = rate/100;
    cout << "Updated!\n";

    all_rates();
}

/**
 * Sort accounts by balance.
 * Input: saving_accounts - vector of SavingAccount objects
 * Output: sorted statement
 */
void sort_by_balance(vector<SavingAccount> &saving_accounts) {
    sort(saving_accounts.begin(), saving_accounts.end(), [](SavingAccount &a, SavingAccount &b) {
        return a.account_balance > b.account_balance;
    });
    cout << "Accounts sorted by balance!\n";
}

/**
 * Sort accounts by opening date.
 * Input: saving_accounts - vector of SavingAccount objects
 * Output: sorted statement
 */
void sort_by_open_date(vector<SavingAccount> &saving_accounts) {
    sort(saving_accounts.begin(), saving_accounts.end(), [](SavingAccount &a, SavingAccount &b) {
        if (a.open_date.year != b.open_date.year)
            return a.open_date.year < b.open_date.year;
        if (a.open_date.month != b.open_date.month)
            return a.open_date.month < b.open_date.month;
        return a.open_date.day < b.open_date.day;
    });
    cout << "Accounts sorted by opening date!\n";
}

/**
 * Calculate expected interest for all accounts based on open dates.
 * Input: saving_accounts - vector of SavingAccount objects
 * Output: none
 */
void calc_interest(vector<SavingAccount> &saving_accounts) {
    time_t t = time(0);
    tm* now = localtime(&t);
    int current_year = now->tm_year + 1900;
    int current_month = now->tm_mon + 1;
    int current_day = now->tm_mday;

    cout << "Today's date: " << current_day << '/' << current_month << '/' << current_year << endl;

    for (auto &account : saving_accounts) {
        double rate = 0.0;
        if (account.type == "long-term") rate = rates[0];
        else if (account.type == "short-term") rate = rates[1];
        else if (account.type == "no-term") rate = rates[2];

        int years_open = current_year - account.open_date.year;
        int months_open = current_month - account.open_date.month;
        int days_open = current_day - account.open_date.day;

        if (months_open < 0 || (months_open == 0 && days_open < 0)) {
            years_open--;
            months_open += 12;
        }
        if (days_open < 0) {
            months_open--;
            days_open += 30; // Approximation for simplicity
        }

        double total_years_open = years_open + (months_open / 12.0) + (days_open / 365.0);
        double interest = account.account_balance * rate * total_years_open;
        cout << "Expected interest for account ID " << account.account_id << ": " << interest << " VND\n";
    }
}

/**
 * Search account by account ID.
 * Input: saving_accounts - vector of SavingAccount objects
 * Output: account information or error message
 */
void search_by_id(vector<SavingAccount> saving_accounts) {
    string id;
    cout << "Enter account ID to search: ";
    cin >> id;
    id = trim(id);

    auto it = find_if(saving_accounts.begin(), saving_accounts.end(), [&id](SavingAccount &acc) {
        return acc.account_id == id;
    });

    if (it != saving_accounts.end()) {
        account_info(*it);
    } else {
        cout << "Account not found!\n";
    }
}

/**
 * Search account by national ID.
 * Input: saving_accounts - vector of SavingAccount objects
 * Output: account information or error message
 */
void search_by_uid(vector<SavingAccount> saving_accounts) {
    string uid;
    cout << "Enter national ID to search: ";
    cin >> uid;
    uid = trim(uid);

    auto it = find_if(saving_accounts.begin(), saving_accounts.end(), [&uid](SavingAccount &acc) {
        return acc.uid == uid;
    });

    if (it != saving_accounts.end()) {
        account_info(*it);
    } else {
        cout << "Account not found!\n";
    }
}

/**
 * Withdraw money from an account.
 * Input: saving_accounts - vector of SavingAccount objects
 * Output: remaining account balance or error message
 */
void withdraw(vector<SavingAccount> &saving_accounts) {
    string id;
    cout << "Enter account ID to withdraw from: ";
    cin >> id;
    id = trim(id);

    auto it = find_if(saving_accounts.begin(), saving_accounts.end(), [&id](SavingAccount &acc) {
        return acc.account_id == id;
    });

    if (it != saving_accounts.end()) {
        double amount;
        cout << "Current account balance: " << it->account_balance << " VND\n";
        cout << "Enter amount to withdraw (or enter -1 to withdraw all): ";
        cin >> amount;
        if (amount == -1) {
            amount = it->account_balance;
        }

        if (amount > 0 && amount <= it->account_balance) {
            time_t t = time(0);
            tm* now = localtime(&t);
            int current_year = now->tm_year + 1900;
            int years_open = current_year - it->open_date.year;
            if (years_open < 1) {
                cout << "Warning: Withdrawing before term. Interest rate will be recalculated at 0.5%/year.\n";
                double interest = it->account_balance * 0.005 * years_open;
                it->account_balance += interest;
            } else {
                // Update interest based on the account type
                double rate = 0.0;
                if (it->type == "long-term") rate = rates[0];
                else if (it->type == "short-term") rate = rates[1];
                else if (it->type == "no-term") rate = rates[2];

                double interest = it->account_balance * rate * years_open;
                it->account_balance += interest;
            }

            it->account_balance -= amount;
            cout << "Withdrawal successful!\nRemaining account balance: " << it->account_balance << " VND\n";
        } else {
            cout << "Invalid amount!\n";
        }
    } else {
        cout << "Account not found!\n";
    }
}

/**
 * List all saving accounts.
 * Input: saving_accounts - vector of SavingAccount objects
 * Output: account information for all accounts
 */
void list_all(vector<SavingAccount> saving_accounts) {
    for (const auto &account : saving_accounts) {
        account_info(account);
    }
}

/**
 * Display account options and handle user input.
 * Input: saving_accounts - vector of SavingAccount objects
 * Output: results of valid options or error message
 */
void options(vector<SavingAccount> &saving_accounts) {
    while(true) {
        cout << "\nAccount options!\n";
        cout << "1. Update annual interest rate\n";
        cout << "2. Calculate interest\n";
        cout << "3. Withdraw money\n";
        cout << "4. Search account by account ID\n";
        cout << "5. Search account by national ID\n";
        cout << "6. List all saving accounts\n";
        cout << "7. Sort by balance\n";
        cout << "8. Sort by opening date\n";
        cout << "9. Exit\n";
        int choice = 0;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;
        switch(choice) {
            case 1:
                update_interest();
                break;
            case 2:
                calc_interest(saving_accounts);
                break;
            case 3:
                withdraw(saving_accounts);
                break;
            case 4:
                search_by_id(saving_accounts);
                break;
            case 5:
                search_by_uid(saving_accounts);
                break;
            case 6:
                list_all(saving_accounts);
                break;
            case 7:
                sort_by_balance(saving_accounts);
                break;
            case 8:
                sort_by_open_date(saving_accounts);
                break;
            case 9:
                exit(0);
            default:
                cout << "Invalid option!";
        }
    }
}

int main() {
    vector<SavingAccount> saving_accounts;
    int n;
    cout << "Number of account: ";
    cin >> n;
    for(int i = 0; i < n; i++) {
        cout << "Create new saving account!\n";
        cout << "Account " << i+1 << ":\n";
        saving_accounts.push_back(input());
    }
    options(saving_accounts);
    return 0;
}