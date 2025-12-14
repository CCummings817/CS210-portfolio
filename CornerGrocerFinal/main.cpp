#include "GroceryTracker.h"

int main() {
    GroceryTracker tracker("CS210_Project_Three_Input_File.txt");
    tracker.LoadData();
    tracker.Run();
    return 0;
}
