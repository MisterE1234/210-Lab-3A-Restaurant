    #include <iostream>
    using namespace std;
    //This is Restaurant struct: It stores information gathered from the user about a restaurant
    //Name, Style, Rating (1-10), Distance (miles), and if it is open.
    struct Restaurant {
        string name;
        string style;
        int rating;
        float distance;
        char isOpen;
    };

    //These are the function prototypes:
        // Get data for a restaurant struct from user:
        Restaurant getData();
        // Output the data from a restaurant struct in a pleasing format:
        void outputRestaurant(const Restaurant &);


    int main() {
    //The main will activate the getData function, which will return a Restaurant struct to be inputted into outputRestaurant.
        Restaurant myRestaurant = getData();
        cout << "\nOutputting single car in single struct:\n";
        outputRestaurant(myRestaurant);
        cout << endl << endl;

        return 0;
    }
    //Function Definitions:
    //This function will ask the user for the data required for the Restaurant struct:
    Restaurant getData() {
        Restaurant temp; //a temperary struct variable.
        bool valid = false; // This variable will be used to make sure that the answer provided are valid.

        // Get Name for the Restuarant:
            while(!valid) {
                cout << "Enter the Name of the Restaurant: \n";
                getline(cin, temp.name);
                
                //The if statement makes sure that the name is not blank:
                if (temp.name.length() > 0) {
                    valid = true;
                } else {
                    cout << "> ERROR: Name cannot be blank\n";
                }
            }
        //Reset valid for next input:
            valid = false;
        //Get Style for the Restuarant:
            while(!valid) {
                cout << "Enter Restaurant Style:\n";
                getline(cin, temp.style);
                
                //The if statement makes sure that the name is not blank:
                if (temp.style.length() > 0) {
                    valid = true;
                } else {
                    cout << "> ERROR: Restaurant Style cannot be blank\n";
                }
            }
        //Reset valid for next input:
            valid = false;
        //Get Rating for the Restuarant:
            while (!valid) {
                cout << "Enter Restaurant Rating as an Integer (1-10): \n";
                cin >> temp.rating;
                // This if statement makes sure that entry is 1-10 and is an integer:
                if (cin.fail() || temp.rating < 1 || temp.rating > 10) {
                    cout << "> ERROR: Rating must be between 1 and 10\n";
                    cin.clear();
                    cin.ignore(100000, '\n');
                } else {
                    valid = true;
                }
            }
        //Reset valid for next input:
            valid = false;
        //Get Distance for the Restuarant:
            while (!valid) {
                cout << "Enter Distance to Restaurant in Miles: \n";
                cin >> temp.distance;
                // This if statement makes sure that entry is at least 0 and is a number:
                if (cin.fail() ||temp.distance < 0) {
                    cout << "> ERROR: Distance must be greater than 0\n";
                    cin.clear();
                    cin.ignore(100000, '\n');
                } else {
                    valid = true;
                }
            }
        //Reset valid for next input:
        valid = false;
        //Get if the Restuarant is Open:
            while (!valid) {
                cout << "Is the Restaurant Open? (Y/N): \n";
                cin >> temp.isOpen;
                // This if statement makes sure that entry is Y or N regardless of case and is a singular character:
                if (!cin.fail() && (temp.isOpen == 'Y' || temp.isOpen == 'N' || temp.isOpen == 'y' || temp.isOpen == 'n')) {
                    valid = true;
                } else {
                    cout << "> ERROR: Y/N only\n";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
            }
    
    return temp;
    }
    // This function will display the user's data on the console:
    void outputRestaurant(const Restaurant &entry) {
        cout << "Restaurant Name: " << entry.name << ":\n";
        cout << "Restaurant Style: " << entry.style << endl;
        cout << "Restaurant Rating: " << entry.rating << "/10" << endl;
        cout << "Distance to Restaurant: " << entry.distance << " miles" << endl;
        if (entry.isOpen == 'Y' || entry.isOpen == 'y') {
            cout << "Restaurant is Open" << endl;
        } else {
            cout << "Restaurant is Closed" << endl;
        }
    }
