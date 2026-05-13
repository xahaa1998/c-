[5/10/2026 11:42 AM] ISLAM BOY: /*
NAME _________________ID
Taha Hamza           (UGR/40607/18)

   1. Description About the Program
The ASTU Phone Number Management System is a C++ programmed application developed to manage student contact information efficiently.
The system allows users to store, view, search, update, and delete contact details such as name, department, and phone number.
This system is designed to help students and staff organize phone records in a simple and structured way.
This program uses different functions and structures:
Structures
Arrays
File handling

2. Algorithm
    Main Algorithm   Store data in file
    Start program
    Display menu
    Get user choice
    Perform selected operation
    Repeat until user selects Exit
    End program
    Add Contact Algorithm
    Open file in append mode
    Input name, department, phone
    Display result
3. Development Process
    The program was developed step-by-step:
    Design Phase
    Defined structure and required features
    Planned menu-driven interface
    Implementation Phase
    Implemented basic functions (add, view)
    Added search, update, delete features
    File Handling Integration
    Added writing to file when adding data
    Added reading from file for displaying data
    Tested each function individually
    Verified file storage and retrieval
4. Changes and Improvements
     During development, several improvements were made:
     Added department field to contact structure
     Used file handling for permanent storage
     Improved output formatting using iomanip
     Used array to manage multiple contact
     Added user-friendly messages for operations
*/






#include <iostream>   // for input and output
#include <iomanip>    // for formatting output
#include <fstream>    // for file handling
using namespace std;

// structure to store contact details
struct contact
{
    string name;
    string phone;
    string dept;
};

// function declarations to tell computer
void addContact();
void viewContacts();
void searchContact();
void deleteContact();
void updateContact();

int main()
{
    int choice; // declaring variable to store user choice
     cout<<"==============ASTU PHONE NUMBER MANAGEMENT SYSTEM============"<<endl;
     cout<<"              ==================================="<<endl;
    do
    {
        // display menu options to user
        cout << "1. Add Contact\n";
        cout << "2. View Contacts\n";
        cout << "3. Update Contact\n";
        cout << "4. Delete Contact\n";
        cout << "5. Search Contact\n";
        cout << "6. Exit\n";

        cin >> choice;

        // do the function based on user choice
        switch (choice)
        {
            case 1:
                addContact(); // call function to add contact
                break;
            case 2:
                viewContacts(); // call function to view contacts
                break;
            case 3:
                updateContact(); // call function to update contact
                break;
            case 4:
                deleteContact(); // call function to delete contact
                break;
            case 5:
                searchContact(); // call function to search contact
                break;
            case 6:
                cout << "good bye"; // exit message
                break;
            default:
                cout << "invalid number! try again!"; // displaying error message
        }

    } while (choice != 6); // loop continues until user chooses exit(6)

    return 0;
}
[5/10/2026 11:42 AM] ISLAM BOY: //   add contact function initialization
void addContact()
{
    ofstream add("contact.txt", ios::app); // open file in append mode
    contact c; // create contact object

    cout << "enter name: " << endl;
    cin >> c.name; // take name input

    cout<<"enter student's department: "<<endl;
    cin>>c.dept;

    cout << "enter the phone: " << endl;
    cin >> c.phone; // take phone input

    add << c.name << " " <<c.dept<<" "<< c.phone << endl; // write name and phone and department to file

    cout << "contact saved succesfully!" << endl;

    add.close();
}

// function to view all contacts
void viewContacts()
{
    ifstream view("contact.txt"); // open file for reading
    contact c;

    // print table header.just for decoration
    cout << left << setw(20) << "NAME" << setw(20) << "Department"<< setw(20)<<"Phone"<< endl;
    cout << "-------------------------------------------------\n" << endl;

    // read and display contacts until end of file
    while (view >> c.name >>c.dept >> c.phone)
    {
        cout << left << setw(20) << c.name << setw(20) << c.dept <<setw(20)<<c.phone << endl;
    }

    view.close();
}

// function to delete a contact
void deleteContact()
{
    string searchName;
    bool found = false;

    cout << "Enter name to delete: ";
    cin >> searchName;
    ifstream file("contact.txt"); // open file for reading
    contact contacts[1000]; // array to store contacts
    int count = 0;

    // read all contacts into array
    while (file >> contacts[count].name >> contacts[count].dept>>contacts[count].phone)
    {
        count++;
    }

    file.close();

    ofstream write("contact.txt"); // open file in overwriting mode

    // rewrite all contacts except the one to delete
    for (int i = 0; i < count; i++)
    {
        if (contacts[i].name == searchName)
        {
            found = true;
            continue; // skip writing this contact
        }

        write << contacts[i].name << " " << contacts[i].dept<<" "<<contacts[i].phone << endl;
    }

    write.close();

    if (found == true)
    {
        cout << "Contact deleted successfully!\n";
    }
    else
    {
        cout << "Contact not found!\n";
    }
}

// search contact function initializatiion
void searchContact()
{
    string searchName;
    bool found = false;

    cout << "Enter name to search: ";
    cin >> searchName;

    ifstream search_name("contact.txt"); // open file
    contact c_list[1000];
    int count = 0;

    while (search_name >> c_list[count].name>>c_list[count].dept >> c_list[count].phone)
    {
        count++;
    }

    // search for the contact using for loop
    for (int i = 0; i < count; i++)
    {
        if (c_list[i].name == searchName)
        {
            found = true;

            // displaying found contact
            cout << "name :" << c_list[i].name<<endl<<"department :"<<c_list[i].dept<<endl<< "phone :" << c_list[i].phone << endl;
            break;
        }
    }

    // display result if not found
    if (found == true)
    {
        cout << "contact is found!" << endl;
    }
    else
    {
        cout << "Contact is not found!\n";
    }

    search_name.close();
}

// function to update a contact
void updateContact()
{
    string searchName;
    bool found = false;

    cout << "Enter name to update: ";
    cin >> searchName;

    ifstream update("contact.txt");
    contact c_list[1000];
    int count = 0;

    while (update >> c_list[count].name>>c_list[count].dept >> c_list[count].phone)
    {
        count++;
    }

    update.close();
    // find and update contact
    for (int i = 0; i < count; i++)
    {
        if (c_list[i].name == searchName)
        {
            found = true;

            cout << "Enter new name: "<<endl;;
            cin >> c_list[i].name;

            cout<<"enter department: "<<endl;
            cin>>c_list[i].dept;

            cout << "Enter new phone: "<<endl;
            cin >> c_list[i].phone;
        }
    }

    ofstream out("contact.txt"); // overwrite file
[5/10/2026 11:42 AM] ISLAM BOY: // write updated contacts back to file
    for (int i = 0; i < count; i++)
    {
        out << c_list[i].name<<" "<<c_list[i].dept << " " << c_list[i].phone << endl;
    }

    out.close();

    // display result to tell if it is updated or not
    if (found)
    {
        cout << "Contact updated successfully!\n";
    }
    else
    {
        cout << "contact not found" << endl;
    }
}
