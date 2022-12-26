// Write a program in C++ to use map associative container. The keys will be the names of states 
// and the values will be the populations of the states. When the program runs, the user is 
// prompted to type the name of a state. The program then looks in the map, using the state name 
// as an index and returns the population of the state.



#include <iostream>
#include <map>
#include <iomanip>
#include <iterator>
using namespace std;

void insert(map<string, int> &m)
{
    string state;
    int population, n;
    cout << "How many states?\n: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "\n\n- - - - - - - - - - - - - - - -\n\n";
        cout << "Enter the name of the state: ";
        cin.ignore();
        getline(cin, state);
        cout << "Enter the population of the state: ";
        cin >> population;

        m[state] = population;
        // instead we can also use this
        //m.insert(pair<string, int>(state, population));
    }
}

void display(map<string, int> m)
{
    map<string, int>::iterator i;
    cout << "\n\n* * * * * * * * * * * * * Information of states * * * * * * * * * * * * *\n";
    cout << endl
         << endl
         << left << setw(15) << "State" << left << setw(15) << "Population\n\n";
    for (i = m.begin(); i != m.end(); i++)
    {
        cout << left << setw(15) << i->first << left << setw(15) << i->second << endl;
    }
}

void search(map<string, int> m)
{
    cout << "\n\nEnter the name of state which is to be search: ";
    string key;
    cin >> key;
    cout << "\n\nThe population of the " << key << " is " << m[key] << endl
         << endl;
}

int main()
{
    int ch;
    map<string, int> stats;

    while (1)
    {
        cout << "\n* * * Menu * * *\n\n1. Insert the Data\n2. Display the data\n3. Get the population of State\n4. exit\n\nEnter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            insert(stats);
            break;
        case 2:
            display(stats);
            break;
        case 3:
            search(stats);
            break;
        case 4:
            return 0;
        default:
            cout << "\n\ninvalid choice\n";
        }
    }

    return 0;
}