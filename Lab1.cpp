#include <iostream>
#include <stdlib.h>
#include <fstream>

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

    while (1)
    {

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
        bool c = true;
        while (c)
        {
            if (cin >> p && p <= 7 && p >= 0)
            {
                c = false;
                cout << "Ok,\n";
            }
            else
            {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Ahh! Here we go again...\n";
            }
        };

        switch (p)
        {
        case (1):
        {
            cout << "Input name pipe\n"
                 << "__> ";
            cin >> t.name_t;

            cout << "Input length pipe\n"
                 << "__> ";
            cin >> t.len;

            cout << "Input diameter pipe\n"
                 << "__> ";
            cin >> t.d;

            cout << "Input mending(1/0)\n"
                 << "__> ";
            cin >> t.remont;

            break;
        }
        case (2):
        {
            cout << "Input name KS\n"
                 << "__> ";
            cin >> s.name_s;

            cout << "Input number of workshops\n"
                 << "__> ";
            cin >> s.kolvo_cex;

            cout << "Input number of workshops in work\n"
                 << "__> ";
            cin >> s.kolvo_cex_rabot;

            bool c = true;
            while (c)
            {
                if (s.kolvo_cex > s.kolvo_cex_rabot)
                {
                    c = false;
                }
                else
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "\n!!! number of workshops in work must be smaller than all number of workshops\n\n";
                    cout << "Input number of workshops in work\n"
                         << "__> ";
                    cin >> s.kolvo_cex_rabot;
                }
            };

            cout << "Input ratio\n"
                 << "__> ";
            cin >> s.k;

            break;
        }
        case (3):
        {
            cout << "Name pipe  " << t.name_t << "\n"
                 << "Length pipe  " << t.len << "\n"
                 << "Diameter pipe  " << t.d << "\n"
                 << "Mending  " << t.remont << "\n"

                 << "Name KS  " << s.name_s << "\n"
                 << "Number of workshops  " << s.kolvo_cex << "\n"
                 << "Number of workshops in work  " << s.kolvo_cex_rabot << "\n"
                 << "Ratio  " << s.k << "\n";
            break;
        }
        case (4):
        {
            p = 0;
            cout << "Choose parameter which you want to edit\n"
                 << "1. Name pipe\n"
                 << "2. mending(0/1)\n";
            bool c = true;
            while (c)
            {
                if (cin >> p && p <= 2 && p >= 1)
                {
                    c = false;
                    cout << "Ok\n";
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
            {
                cout << "Input name pipe\n"
                     << "__> ";
                cin >> t.name_t;
                break;
            }
            case (2):
            {
                cout << "Input mending(1/0)\n"
                     << "__> ";
                cin >> t.remont;
                break;
            }
            }
            break;
        }
        case (5):
        {
            p = 0;
            cout << "Choose parameter which you want to edit\n"
                 << "1. Name KS\n"
                 << "2. Number of workshops in work\n"
                 << "3. Ratio\n";
            bool c = true;
            while (c)
            {
                if (cin >> p && p <= 3 && p >= 1)
                {
                    c = false;
                    cout << "Ok\n";
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
            {
                cout << "Input Name KS\n"
                     << "__> ";
                cin >> s.name_s;
                break;
            }
            case (2):
            {
                cout << "Input Number of workshops in work\n"
                     << "__> ";
                cin >> s.kolvo_cex_rabot;
                bool c = true;
                while (c)
                {
                    if (s.kolvo_cex > s.kolvo_cex_rabot)
                    {
                        c = false;
                    }
                    else
                    {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cout << "\n!!! number of workshops in work must be smaller than all number of workshops\n\n";
                        cout << "Input number of workshops in work\n"
                             << "__> ";
                        cin >> s.kolvo_cex_rabot;
                    }
                }
                break;
            }
            case (3):
            {
                cout << "Ratio\n"
                     << "__> ";
                cin >> s.k;
                break;
            }
            }
            break;
        }
        case (6):
        {
            ofstream out;
            out.open("base.txt");
            string tr = t.name_t;
            if (out.is_open())
            {
                out << t.name_t << endl
                    << t.len << endl
                    << t.d << endl
                    << t.remont << endl
                    << s.name_s << endl
                    << s.kolvo_cex << endl
                    << s.kolvo_cex_rabot << endl
                    << s.k;
            }
            out.close();
            cout << "saved successfully" << endl;
            break;
        }

        case (7):
        {
            ifstream in;
            in.open("base.txt");
            /*cout << endl
                << in.rdbuf();
            */
            if (in.is_open() && !in.eof())
            {

                in >> t.name_t;
                in >> t.len;
                in >> t.d;
                in >> t.remont;
                in >> s.name_s;
                in >> s.kolvo_cex;
                in >> s.kolvo_cex_rabot;
                in >> s.k;
            }
            in.close();

            cout << "load successfully" << endl;
            break;
        }
        case (0):
            exit(0);
            break;
        default:
            cout << "Wrong action\n";
            return 0;
        };
    }
};