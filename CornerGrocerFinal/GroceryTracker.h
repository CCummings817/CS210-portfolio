#ifndef GROCERY_TRACKER_H
#define GROCERY_TRACKER_H

#include <string>
#include <unordered_map>

using namespace std;

class GroceryTracker {
public:
    GroceryTracker(const string& inputFile);

    void LoadData();
    void Run();

private:
    void DisplayMenu();
    void DisplayItemFrequency(const string& item);
    void DisplayAllFrequencies();
    void DisplayHistogram();
    void WriteFrequencyData();
    void ClearInput();

    unordered_map<string, int> m_itemFrequency;
    string m_inputFileName;
};

#endif
