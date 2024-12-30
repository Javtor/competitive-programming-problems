
#include <iostream>

#include <string.h>

#include <vector>

using namespace std;

vector<string> outstr;

int Checkstr()
{

    string phonenum;

    cin >> phonenum;

    if (phonenum.size() == 2 and phonenum[0] == '-' and phonenum[1] == '1')
    {

        return -1;
    }

    int count;

    cin >> count;

    vector<string> instr;

    vector<int> numstr;

    int sequence = 0;

    for (int i = 0; i < count; i++)
    {

        string tstr;

        cin >> tstr;

        instr.insert(instr.end(), tstr);
    }

    for (int i = 0; i < instr.size(); i++)
    {

        int tse = 0;

        for (int j = 0; j < instr[i].size(); j++)
        {

            int instrsq = -1;

            switch (instr[i][j])
            {

            case 'i':;

            case 'j':

                instrsq = 1;

                break;

            case 'a':;

            case 'b':;

            case 'c':

                instrsq = 2;

                break;

            case 'd':;

            case 'e':;

            case 'f':

                instrsq = 3;

                break;

            case 'g':;

            case 'h':

                instrsq = 4;

                break;

            case 'k':;

            case 'l':

                instrsq = 5;

                break;

            case 'm':;

            case 'n':

                instrsq = 6;

                break;

            case 'p':;

            case 'r':;

            case 's':

                instrsq = 7;

                break;

            case 't':;

            case 'u':;

            case 'v':

                instrsq = 8;

                break;

            case 'w':;

            case 'x':;

            case 'y':

                instrsq = 9;

                break;

            case 'o':;

            case 'q':;

            case 'z':

                instrsq = 0;

                break;

            default:

                break;
            }

            if (instrsq >= 0 and (phonenum[sequence + j] - '0') == instrsq and tse != 1)
            {

                tse = 0;

                cout << "instr1 is " << instr[i][j] << endl;
            }
            else
            {

                cout << "instr2 is " << instr[i][j] << endl;

                tse = 1;

                break;
            }
        }

        if (tse == 0)
        {

            sequence = (int)instr[i].size() + sequence;

            outstr.insert(outstr.end(), instr[i]);
        }
    }

    return 0;
}

int main(int argc, const char *argv[])
{

    vector<string> ostr;

    while (1)
    {

        if (Checkstr() == -1)
        {

            for (int i = 0; i < ostr.size(); i++)
            {

                cout << ostr[i] << endl;
            }

            break;
        }

        else
        {

            string stemp;

            if (outstr.size() < 1)
            {

                ostr.insert(ostr.end(), "No solution.");
            }

            else
            {

                for (int i = 0; i < outstr.size(); i++)
                {

                    stemp = stemp + outstr[i] + ' ';
                }

                ostr.insert(ostr.end(), stemp);

                outstr.clear();
            }
        }
    }

    return 0;
}