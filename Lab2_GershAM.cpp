#include "utils.h"
#include "pipe.h"
#include "station.h"
#include "GTS.h"

void menu()
{
    std::cout   << "\n========================================================\n"
                << "________________________Menu____________________________\n\n"
                << "        select one of the following items:\n"
                << "1. Add pipe                         6. Save\n"
                << "2. Add KS                           7. Load\n"
                << "3. Find(edit/del) pipes             8. Link to GTS\n"
                << "4. Find(edit/del) stations          9. Graph && Topologic sort\n"
                << "5. View all objects                 0. Exit\n"
                << "__> ";
}


int main()
{
    redirect_output_wrapper cerr_out(std::cerr);
    // string time = std::format("{:%d_%m_%Y %H_%M_%OS}", system_clock::now());
    std::ofstream logfile("log_" /*+ time*/);
    if (logfile)
        cerr_out.redirect(logfile);

    GTS gts;
    
    while (true)
    {
        menu();
        switch (InputNum<int>(0, 9))
        {
            case (1):
            {
                gts.addPipe();
                break;
            }
            case (2):
            {
                gts.addKS();
                break;
            }
            case (3):
            {
                gts.findPipes();
                break;
            }
            case (4):
            {
                gts.findKSs();
                break;
            }
            case (5):
            {   
                gts.out_data();
                break;
            }
            case (6):
            {
                gts.fileOut();
                break;
            }
            case (7):
            {
                gts.fileIn();
                break;
            }
            case (8):
            {
                gts.link();
                break;
            }
            case(9):
            {
                gts.Graph_and_Topsort();
                break;
            }
            case (0):
            {
                exit(0);
            }
            default:
                std::cout << "Wrong action\n";
                return 0;
        }
    }
}