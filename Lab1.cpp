#include <iostream>
#include <fstream>
#include <stdlib.h>

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

    system("CLS");

    t.name_t = "_";
    t.len = NULL;
    t.d = NULL;
    t.remont = 1;
    s.k = NULL;
    s.kolvo_cex = NULL;
    s.kolvo_cex_rabot = NULL;
    s.name_s = "_";

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

        short int p = 0;
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
                cout << "\n-----------------------\nPlease input correct number\n-----------------------\n";
            }
        };

        switch (p)
        {
        case (1):
        {
            cout << "Input name pipe\n"
                 << "__> ";
            cin.ignore(10000, '\n');
            getline(cin, t.name_t);

            cout << "\nInput length pipe\n"
                 << "__> ";
            cin >> t.len;
            c = true;
            while (c)
            {
                if (t.len != NULL)
                {
                    c = false;
                }
                else
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "\nWrong length!!!\n";
                    cout << "\nInput length pipe\n"
                         << "__> ";
                    cin >> t.len;
                }
            };

            cout << "Input diameter pipe\n"
                 << "__> ";
            cin >> t.d;
            c = true;
            while (c)
            {
                if (t.d != NULL)
                {
                    c = false;
                }
                else
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "\nWrong diameter!!!\n";
                    cout << "\nInput diameter pipe\n"
                         << "__> ";
                    cin >> t.d;
                }
            };

            cout << "Input mending(1/0)\n"
                 << "__> ";
            cin >> t.remont;

            system("CLS");
            break;
        }
        case (2):
        {
            cout << "Input name KS\n"
                 << "__> ";
            cin.ignore(10000, '\n');
            getline(cin, s.name_s);

            cout << "\nInput number of workshops\n"
                 << "__> ";
            cin >> s.kolvo_cex;
            bool c = true;
            while (c)
            {
                if (s.kolvo_cex != NULL)
                {
                    c = false;
                }
                else
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "\nWrong number of workshops!!!\n";
                    cout << "\nInput number of workshops\n"
                         << "__> ";
                    cin >> s.kolvo_cex;
                }
            };

            cout << "Input number of workshops in work\n"
                 << "__> ";
            cin >> s.kolvo_cex_rabot;

            c = true;
            while (c)
            {
                if (s.kolvo_cex >= s.kolvo_cex_rabot)
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
            c = true;
            while (c)
            {
                if (s.k != NULL)
                {
                    c = false;
                }
                else
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "\nWrong ratio!!!\n";
                    cout << "Input ratio\n"
                         << "__> ";
                    cin >> s.k;
                }
            };

            system("CLS");
            break;
        }
        case (3):
        {
            system("CLS");
            if ((t.name_t == "_" || t.d == NULL || t.len == NULL) &&
                (s.k == NULL || s.kolvo_cex == NULL || s.kolvo_cex_rabot == NULL || s.name_s == "_"))
            {
                cout << "input statements doesnt exist\n";
            }
            else
            {
                if (t.name_t != "_" && t.d != NULL && t.len != NULL)
                {
                    cout << "Name pipe  " << t.name_t << "\n"
                         << "Length pipe  " << t.len << "\n"
                         << "Diameter pipe  " << t.d << "\n"
                         << "Mending  " << t.remont << "\n";
                }
                if ((s.k != NULL && s.kolvo_cex != NULL && s.kolvo_cex_rabot != NULL && s.name_s != "_"))
                {
                    cout << "Name KS  " << s.name_s << "\n"
                         << "Number of workshops  " << s.kolvo_cex << "\n"
                         << "Number of workshops in work  " << s.kolvo_cex_rabot << "\n"
                         << "Ratio  " << s.k << "\n";
                }
            }
            break;
        }
        case (4):
        {
            system("CLS");
            if ((t.name_t == "_" || t.d == NULL || t.len == NULL))
            {
                cout << "\n-------------------------------------\n!!! input statements doesnt exist !!!\n-------------------------------------\n";
            }
            else
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
                    cin.ignore(10000, '\n');
                    getline(cin, s.name_s);
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
            }
            break;
        }
        case (5):
        {
            system("CLS");
            if ((s.k == NULL || s.kolvo_cex == NULL || s.kolvo_cex_rabot == NULL || s.name_s == "_"))
            {
                cout << "\n-------------------------------------\n!!! input statements doesnt exist !!!\n-------------------------------------\n";
            }
            else
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
                    cin.ignore(10000, '\n');
                    getline(cin, s.name_s);
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
                    while (s.k == NULL)
                    {
                        cout << "\nWrong ratio!!!\n";
                        cout << "Input ratio\n"
                             << "__> ";
                        cin >> s.k;
                    }
                    break;
                }
                }
            }

            break;
        }
        case (6):
        {
            system("CLS");
            if (t.name_t == "_" || t.d == NULL || t.len == NULL)
            {
                cout << "\n-------------------------------------\n!!! input pipe statements doesnt exist !!!\n-------------------------------------\n";
            }
            else
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
                cout << "pipe statements saved successfully" << endl;
            }

            if (s.kolvo_cex == NULL || s.name_s == "_")
            {
                cout << "\n-------------------------------------\n!!! input station statements doesnt exist !!!\n-------------------------------------\n";
            }
            else
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
                cout << "station statements saved successfully" << endl;
            }
        }
        break;
        case (7):
        {
            system("CLS");
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

            if ((t.name_t == "_" || t.d == NULL || t.len == NULL) ||
                (s.kolvo_cex == NULL || s.name_s == "_"))
            {
                cout << "\n-------------------------------------\n!!! input statements doesnt exist !!!\n-------------------------------------\n";
            }
            else
            {
                cout << "load successfully" << endl;
            }
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