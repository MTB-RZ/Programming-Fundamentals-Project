#include <iostream>
#include <fstream>
using namespace std;

int countRecords(char fname[]);
void loadData(char fname[], char** names, char** address, char** blood, int& rowCount);
bool choicecheck(char ch);
void allpatient(char** names, char** address, char** blood, int  rowCount);
void specificpatient(char** names, char** address, char** blood, int rowCount);
void admitpatient(char fname[]);
void dischargepatient(char fname[], char** names, char** address, char** blood, int& rowCount);

int main()
{
    char fname[] = "Hospital.txt";

    int rowslength = countRecords(fname) + 1;
    const int collength = 100;

    char** names = new char* [rowslength];
    char** address = new char* [rowslength];
    char** blood = new char* [rowslength];

    for (int i = 0; i < rowslength; i++)
    {
        names[i] = new char[collength];
        address[i] = new char[collength];
        blood[i] = new char[collength];
        for (int j = 0; j < collength; j++)
        {
            names[i][j] = '\0';
            address[i][j] = '\0';
            blood[i][j] = '\0';
        }
    }

    cout << "\t\t\t===============================================" << endl;
    cout << "\t\t\t     Welcome to Hospital Management System" << endl;
    cout << "\t\t\t===============================================" << endl << endl;

    ifstream fin(fname);
    if (!fin.is_open())
    {
        cout << "Unfortunately, no patient file was found!" << endl << "The system will be closed now..." << endl;
        cout << "Have a nice day!" << endl << endl;
        return 1;
    }

    char choice;
    do
    {
        loadData(fname, names, address, blood, rowslength);

        cout << endl << "Please choose from the following options:" << endl << endl;
        cout << "Option 1: View all Patients" << endl;
        cout << "Option 2: View Specific Patients" << endl;
        cout << "Option 3: Admit new Patients" << endl;
        cout << "Option 4: Discharge Patient" << endl;
        cout << "Option 5: Exit the system" << endl << endl;
        cout << "Please write your desired option and then press enter: ";
        cin >> choice;
        cout << endl << "_____________________________________________________" << endl;

        if (!choicecheck(choice))
        {
            cout << endl << "Invalid option! Please enter 1 through 5." << endl;
            cout << "_____________________________________________________" << endl << endl;
            continue;
        }

        switch (choice)
        {
        case '1':
            allpatient(names, address, blood, rowslength);
            break;
        case '2':
            specificpatient(names, address, blood, rowslength);
            break;
        case '3':
            admitpatient(fname);
            break;
        case '4':
            dischargepatient(fname, names, address, blood, rowslength);
            break;
        }
    } while (choice != '5');

    for (int i = 0; i < rowslength; i++)
    {
        delete[] names[i];
        delete[] address[i];
        delete[] blood[i];
    }
    delete[] names;
    delete[] address;
    delete[] blood;

    cout << endl << "\t\tThanks for using the system!" << endl;
    cout << "\t\tHave a nice day!" << endl << endl;
    return 0;
}

int countRecords(char fname[])
{
    ifstream fin(fname);
    char ch;
    int rows = 0;
    while (fin.get(ch))
    {
        if (ch == '\n')
        {
            rows++;
        }
    }
    if (!fin.eof() && rows > 0)
    {
        rows++;
    }
    fin.close();
    return rows;
}

void loadData(char fname[], char** names, char** address, char** blood, int& rowCount)
{
    ifstream fin(fname);
    if (!fin.is_open())
    {
        rowCount = 0;
        return;
    }

    int stage = 0;
    int col = 0;
    char ch;
    rowCount = 0;

    while (fin.get(ch))
    {
        if (ch == '\t')
        {
            stage++;
            col = 0;
        }
        else if (ch == '\n')
        {
            blood[rowCount][col] = '\0';
            rowCount++;
            stage = 0;
            col = 0;
        }
        else
        {
            if (stage == 0)
            {
                names[rowCount][col] = ch;
                col++;
                names[rowCount][col] = '\0';
            }
            else if (stage == 1)
            {
                address[rowCount][col] = ch;
                col++;
                address[rowCount][col] = '\0';
            }
            else if (stage == 2)
            {
                blood[rowCount][col] = ch;
                col++;
                blood[rowCount][col] = '\0';
            }
        }
    }
    fin.close();
}

void allpatient(char** names, char** address, char** blood, int rowCount)
{
    cout << endl << endl;
    const int maxFieldLength = 100;
    for (int i = 0; i < rowCount; i++)
    {
        cout << "Record #" << (i + 1) << endl;
        cout << "Name: ";
        for (int j = 0; j < maxFieldLength && names[i][j] != '\0'; j++)
        {
            cout << names[i][j];
        }
        cout << endl << "Address: ";
        for (int j = 0; j < maxFieldLength && address[i][j] != '\0'; j++)
        {
            cout << address[i][j];
        }
        cout << endl << "Blood Group: ";
        for (int j = 0; j < maxFieldLength && blood[i][j] != '\0'; j++)
        {
            cout << blood[i][j];
        }
        cout << endl << endl;
    }
    cout << endl << "_____________________________________________________" << endl;
}

void specificpatient(char** names, char** address, char** blood, int rowCount)
{
    char chc;
    cout << endl << endl << "Would you like to search by name or blood type?" << endl << "Enter 'n' for name, or 'b' for blood type: ";
    cin >> chc;
    cout << endl;

    if (chc == 'n' || chc == 'N')
    {
        cin.ignore();
        char key[100];
        cout << "Enter full name: ";
        cin.getline(key, 100);
        cout << endl;
        for (int i = 0; key[i] != '\0'; i++)
        {
            if (i == 0 || key[i - 1] == ' ')
            {
                if (key[i] >= 'a' && key[i] <= 'z')
                {
                    key[i] = key[i] - ('a' - 'A');
                }
            }
            else
            {
                if (key[i] >= 'A' && key[i] <= 'Z')
                {
                    key[i] = key[i] + ('a' - 'A');
                }
            }
        }
        bool found = false;
        const int maxFieldLength = 100;

        for (int i = 0; i < rowCount; i++)
        {
            bool match = true;
            int j = 0;
            for (; j < maxFieldLength && names[i][j] != '\0' && key[j] != '\0'; j++)
            {
                if (names[i][j] != key[j])
                {
                    match = false;
                    break;
                }
            }
            if (names[i][j] != '\0' || key[j] != '\0')
            {
                match = false;
            }

            if (match)
            {
                cout << "Record #" << (i + 1) << endl;
                cout << "Name: " << names[i] << endl;
                cout << "Address: " << address[i] << endl;
                cout << "Blood Group: " << blood[i] << endl << endl;
                found = true;
            }
        }
        if (!found)
        {
            cout << "No patient found with the provided name!" << endl;
        }
    }
    else if (chc == 'b' || chc == 'B')
    {
        cin.ignore();
        char key[10];
        cout << "Enter blood type: ";
        cin.getline(key, 10);
        cout << endl;
        for (int i = 0; key[i] != '\0'; i++)
        {
            if (key[i] >= 'a' && key[i] <= 'z')
            {
                key[i] = key[i] - ('a' - 'A');
            }
        }
        bool found = false;
        const int maxFieldLength = 100;

        for (int i = 0; i < rowCount; i++)
        {
            bool match = true;
            int j = 0;
            for (; j < maxFieldLength && blood[i][j] != '\0' && key[j] != '\0'; j++)
            {
                if (blood[i][j] != key[j])
                {
                    match = false;
                    break;
                }
            }
            if (blood[i][j] != '\0' || key[j] != '\0')
            {
                match = false;
            }

            if (match)
            {
                cout << "Record #" << (i + 1) << endl;
                cout << "Name: " << names[i] << endl;
                cout << "Address: " << address[i] << endl;
                cout << "Blood Group: " << blood[i] << endl << endl;
                found = true;
            }
        }
        if (!found)
        {
            cout << "No patient found with that blood type!" << endl;
        }
    }
    else
    {
        cout << "Invalid Option!" << endl;
    }
    cout << endl << "_____________________________________________________" << endl;
}

void admitpatient(char fname[])
{
    ofstream fout(fname, ios::app);
    if (!fout.is_open())
    {
        cout << "Error opening file for writing!" << endl;
        return;
    }
    char bloodG[] = { "A+,A-,B+,B-,O+,O-,AB+,AB-" };
    cin.ignore();
    char name[100];
    char addr[100];
    char bloodType[10];
    cout << "Enter full name: ";
    cin.getline(name, 100);
    for (int i = 0; name[i] != '\0'; i++)
    {
        if (i == 0 || name[i - 1] == ' ')
        {
            if (name[i] >= 'a' && name[i] <= 'z')
            {
                name[i] = name[i] - ('a' - 'A');
            }
        }
        else
        {
            if (name[i] >= 'A' && name[i] <= 'Z')
            {
                name[i] = name[i] + ('a' - 'A');
            }
        }
    }
    cout << "Enter address: ";
    cin.getline(addr, 100);
    bool correct = false;
    do
    {
        int a = 0;
        cout << "Enter blood group: ";
        cin.getline(bloodType, 10);
        int len = 0;
        for (int i = 0; bloodType[i] != '\0'; i++)
        {
            len++;
        }

        int b = 0;
        while (bloodG[a] != '\0')
        {
            bool match = true;
            for (int i = 0; i < len; i++)
            {
                if (bloodType[i] != bloodG[a + i])
                {
                    match = false;
                    break;
                }
            }

            if (match && bloodG[a + len] == ',' || bloodG[a + len] == '\0')
            {
                correct = true;
                break;
            }

            while (bloodG[a] != ',' && bloodG[a] != '\0')
            {
                a++;
            }
            if (bloodG[a] == ',')
            {
                a++;
            }
        }

        if (!correct)
        {
            cout << "Please Enter the correct Blood Type! (A+, A-, B+, B-, O+, O-, AB+, AB-)" << endl;
        }

    } while (!correct);
    fout << name << '\t' << addr << '\t' << bloodType << '\n';
    fout.close();

    cout << endl << "Patient admitted successfully." << endl << "_____________________________________________________" << endl;
}

void dischargepatient(char fname[], char** names, char** address, char** blood, int& rowCount)
{
    cin.ignore();
    cout << endl << endl << "Enter full name of patient to discharge: ";
    char key[100];
    cin.getline(key, 100);

    for (int i = 0; key[i] != '\0'; i++)
    {
        if (i == 0 || key[i - 1] == ' ')
        {
            if (key[i] >= 'a' && key[i] <= 'z')
            {
                key[i] = key[i] - ('a' - 'A');
            }
        }
        else
        {
            if (key[i] >= 'A' && key[i] <= 'Z')
            {
                key[i] = key[i] + ('a' - 'A');
            }
        }
    }

    bool found = false;
    int index = -1;
    const int maxFieldLength = 100;

    for (int i = 0; i < rowCount; i++)
    {
        char tempName[100];
        int k = 0;
        while (names[i][k] != '\0' && k < 99)
        {
            tempName[k] = names[i][k];
            k++;
        }
        tempName[k] = '\0';

        for (int x = 0; tempName[x] != '\0'; x++)
        {
            if (x == 0 || tempName[x - 1] == ' ')
            {
                if (tempName[x] >= 'a' && tempName[x] <= 'z')
                {
                    tempName[x] = tempName[x] - ('a' - 'A');
                }
            }
            else
            {
                if (tempName[x] >= 'A' && tempName[x] <= 'Z')
                {
                    tempName[x] = tempName[x] + ('a' - 'A');
                }
            }
        }

        bool match = true;
        for (int j = 0; tempName[j] != '\0' || key[j] != '\0'; j++)
        {
            if (tempName[j] != key[j])
            {
                match = false;
                break;
            }
        }

        if (match)
        {
            index = i;
            found = true;
            break;
        }
    }

    if (found)
    {
        for (int i = index; i < rowCount - 1; i++)
        {
            for (int j = 0; j < maxFieldLength; j++)
            {
                names[i][j] = names[i + 1][j];
                address[i][j] = address[i + 1][j];
                blood[i][j] = blood[i + 1][j];
            }
        }
        rowCount--;

        ofstream fout(fname);
        for (int i = 0; i < rowCount; i++)
        {
            fout << names[i] << '\t' << address[i] << '\t' << blood[i] << '\n';
        }
        fout.close();

        cout << endl << "Patient discharged successfully." << endl;
    }
    else
    {
        cout << endl << "No patient found with that name!" << endl;
    }

    cout << "_____________________________________________________" << endl;
}

bool choicecheck(char ch)
{
    if (ch >= '1' && ch <= '5')
    {
        return true;
    }
    else
    {
        return false;
    }
}