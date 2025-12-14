#include "GroceryTracker.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>

using namespace std;

GroceryTracker::GroceryTracker(const string& inputFile) {
    m_inputFileName = inputFile;
}

void GroceryTracker::LoadData() {
    ifstream inFS(m_inputFileName);
    string item;

    if (!inFS.is_open()) {
        cout << "Error opening input file." << endl;
        exit(1);
    }

    while (inFS >> item) {
        m_itemFrequency[item]++;
    }

    inFS.close();
    WriteFrequencyData();
}

void GroceryTracker::WriteFrequencyData() {
    ofstream outFS("frequency.dat");

    for (const auto& pair : m_itemFrequency) {
        outFS << pair.first << " " << pair.second << endl;
    }

    outFS.close();
}

void GroceryTracker::DisplayItemFrequency(const string& item) {
    if (m_itemFrequency.count(item)) {
        cout << item << " was purchased "
            << m_itemFrequency[item] << " time(s)." << endl;
    }
    else {
        cout << item << " was not found." << endl;
    }
}

void GroceryTracker::DisplayAllFrequencies() {
    for (const auto& pair : m_itemFrequency) {
        cout << pair.first << " " << pair.second << endl;
    }
}

void GroceryTracker::DisplayHistogram() {
    for (const auto& pair : m_itemFrequency) {
        cout << setw(15) << left << pair.first
            << string(pair.second, '*') << endl;
    }
}

void GroceryTracker::DisplayMenu() {
    cout << "\nMENU OPTIONS\n";
    cout << "1 - Search item frequency\n";
    cout << "2 - Display all frequencies\n";
    cout << "3 - Display histogram\n";
    cout << "4 - Exit\n";
    cout << "Enter choice: ";
}

void GroceryTracker::ClearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void GroceryTracker::Run() {
    int choice;
    string item;

    while (true) {
        DisplayMenu();
        cin >> choice;

        if (cin.fail()) {
            ClearInput();
            continue;
        }

        switch (choice) {
        case 1:
            cout << "Enter item name: ";
            cin >> item;
            DisplayItemFrequency(item);
            break;
        case 2:
            DisplayAllFrequencies();
            break;
        case 3:
            DisplayHistogram();
            break;
        case 4:
            cout << "Goodbye!" << endl;
            return;
        default:
            cout << "Invalid option." << endl;
        }
    }
}
