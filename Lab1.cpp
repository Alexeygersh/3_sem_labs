#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

int main(void)
{
    while (1)
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

        while (c)
        {
            if (cin >> p && p <= 7 && p >= 0)
            {
                cout << "ok\n";
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

        case (2):
            cout << "Input name KS\n"
                 << "__> ";
            cin >> s.name_s;

            cout << "Input number of workshops\n"
                 << "__> ";
            cin >> s.kolvo_cex;

            cout << "Input number of workshops in work\n"
                 << "__> ";
            cin >> s.kolvo_cex_rabot;

            cout << "Input ratio\n"
                 << "__> ";
            cin >> s.k;

            break;

        case (3):
            cout << "Name pipe  " << t.name_t << "\n"
                 << "Length pipe  " << t.len << "\n"
                 << "Diameter pipe  " << t.d << "\n"
                 << "Mending  " << t.remont << "\n"

                 << "Name KS  " << s.name_s << "\n"
                 << "Number of workshops  " << s.kolvo_cex << "\n"
                 << "Number of workshops in work  " << s.kolvo_cex_rabot << "\n"
                 << "Ratio  " << s.k << "\n";
            break;

        case (4):
            break;

        case (5):
            break;

        case (6):
        {
            ofstream out;
            out.open("base.txt", ios::out);
            if (out.is_open())
            {
                const char *chr = t.name_t.c_str();

                out << chr << endl
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
            in.open("base.txt", ios::in);
            /*cout << endl
                 << in.rdbuf();
            */
            if (in.is_open() && !in.eof())
            {
                string temp[9];
                for (int i = 0; i < 8; i++)
                {
                    getline(in, temp[i]);
                }
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
        };
    }
    return 0;
}