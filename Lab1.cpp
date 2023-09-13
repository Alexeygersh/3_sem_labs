#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
    struct truba
    {
        string name_t;
        double len;
        int d;
        bool remont;
    } t;

    struct station
    {
        string name_s;
        int kolvo_cex;
        int kolvo_cex_rabot;
        double k;
    } s;

    cout << "============================================\n"
         << "__________________Menu______________________\n\n"
         << "select one of the following items:\n"
         << "1. Add pipe\n"
         << "2. Add KS\n"
         << "3. View all objects\n"
         << "4. Edit pipe\n"
         << "5. Edit KS\n"
         << "6. Save\n"
         << "7. Load\n"
         << "0. Exit\n";

    short int p;
    cin >> p;
    bool c;
    c = true;
    while (c)
    {
        if (cin >> p && p <= 7 && p >= 0)
        {
            cout << "ok\n\n";
            c = false;
        }
        else
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error.Try again.\n";
        }
    };
    switch (p)
    {
    case (1):
        cout << "Input name pipe\n";
        cin >> t.name_t;
        cout << t.name_t << "<__\n";

        cout << "Input length pipe\n";
        cin >> t.len;
        cout << t.len << "<__\n";

        cout << "Input diameter pipe\n";
        cin >> t.d;
        cout << t.d << "<__\n";

        cout << "Input mending(1/0)\n";
        cin >> t.remont;
        cout << t.remont << "<__\n";

        break;
    case (2):
        cin >> s.name_s >> s.kolvo_cex >> s.kolvo_cex_rabot >> s.k;
        break;
    case (3):

        break;
    case (4):

        break;
    case (5):

        break;
    case (6):

        break;
    case (7):

        break;
    case (0):
        return 0;
        break;
    };
}