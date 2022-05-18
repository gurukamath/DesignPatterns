#include <string>
#include <vector>
#include <iostream>
#include <boost/lexical_cast.hpp>

using std::string;
using std::vector;
using std::cout;
using std::endl;
using boost::lexical_cast;

struct Notes
{

    string name;
    vector<string> notes;

    Notes(string t)
    {
        add_note(t);
    }

    void add_note(string note)
    {
        static int sl_no {1};
        notes.push_back(lexical_cast<string>(sl_no++) + ": " + note);
    }
};


// Define Printer instead of defining a print function in Notes.
// This can be used in other classes as well.
void print(vector<string>& vec)
{
    for (string element : vec)
    {
        cout << element << endl;
    }
}



int main()
{
    Notes my_notes {"I am happy today."};

    my_notes.add_note("I was happy yesterday as well!!");

    print(my_notes.notes);
}