#include <iostream>
#include <fstream>

using namespace std;

int Summ (int a, int b) {
    return a + b;
}

struct Marks {
    short aig;
    short physics;
    short math_an;
    short english;
    short programming;
    short sport;
    short philosophy;
    short informatics;
    float mid_of_marks;
};

struct Names {
    char first_name[30];
    char second_name[30];
    char third_name[30];
};

struct AboutGroup {
    unsigned int group;
    unsigned int number_in_group;
};

struct Student {
    struct Names names;
    bool sex;
    struct AboutGroup aboutGroup;
    struct Marks marks;
    int Summ (int a, int b) {
        return a + b;
    };
};

struct Idz {
    char FIO[90];
    bool sex; //1-m 0-f
    unsigned short age;
    unsigned short course;
    unsigned short razryad;
    unsigned short clothes_size; // xxs-xxl
};

void CoutStart(){
    printf("\n| %-12s| %-12s| %-12s| %-3s| %-3s| %-3s| %-3s| %-3s| %-3s| %-3s| %-3s| %-3s| %-3s| %-3s|\n",
           "First name", "Last name", "Middle name", "Sex", "Group", "ID", "A&G", "Eng", "Inf", "Math", "Philosophy", "Physics", "Prog", "P.E.");
    printf("|-------------|-------------|-------------|----|------|----|----|----|----|-----|-----------|--------|-----|-----|\n");
}
void CoutList(struct Student students[],int temp_Pr){
    printf("| %-12s| %-12s| %-12s| %-3d| %-5d| %-3d| %-3d| %-3d| %-3d| %-4d| %-10d| %-7d| %-4d| %-4d|\n",
           students[temp_Pr].names.first_name, students[temp_Pr].names.second_name, students[temp_Pr].names.third_name, students[temp_Pr].sex, students[temp_Pr].aboutGroup.group, students[temp_Pr].aboutGroup.number_in_group, students[temp_Pr].marks.aig, students[temp_Pr].marks.english, students[temp_Pr].marks.informatics, students[temp_Pr].marks.math_an, students[temp_Pr].marks.philosophy, students[temp_Pr].marks.physics, students[temp_Pr].marks.programming, students[temp_Pr].marks.sport);
    printf("|-------------|-------------|-------------|----|------|----|----|----|----|-----|-----------|--------|-----|-----|\n");
}
    bool IdzFromPract1 (char * FileName) {
        unsigned short number;
        int temp = 0;
        struct Idz idz[10];
        ifstream File;
        string data;
        File.open(FileName);
        if(!File.is_open()) {
            cout << "\nERROR:cant open file\n";
            return 0;
        }
        else {
            for(int i = 0; !File.eof(); i++) {
                File >> idz[i].FIO;
                File >> idz[i].sex;
                File >> idz[i].age;
                File >> idz[i].course;
                File >> idz[i].razryad;
                File >> idz[i].clothes_size;
                temp++;
            }
        }
        File.close();
        cout << "\nWith a volleyball category:\n";
        for(int i = 0; i < temp; i++) {
            if (idz[i].razryad > 0) {
                cout << idz[i].FIO << ' ';
                cout << idz[i].sex << ' ';
                cout << idz[i].age << ' ';
                cout << idz[i].course << ' ';
                cout << idz[i].razryad << ' ';
                cout << idz[i].clothes_size << '\n';
            }
        }
        cout << "\nIn the women's volleyball section:\n";
        for(int i = 0; i < temp; i++) {
            if (idz[i].sex == 0) {
                cout << idz[i].FIO << ' ';
                cout << idz[i].sex << ' ';
                cout << idz[i].age << ' ';
                cout << idz[i].course << ' ';
                cout << idz[i].razryad << ' ';
                cout << idz[i].clothes_size << '\n';
            }
        }
        cout << "\nEnter course: ";
        cin >> number;
        cout << "\nPlayers from " << number << " course:\n";
        for(int i = 0; i < temp; i++) {
            if (idz[i].course == number) {
                cout << idz[i].FIO << ' ';
                cout << idz[i].sex << ' ';
                cout << idz[i].age << ' ';
                cout << idz[i].course << ' ';
                cout << idz[i].razryad << ' ';
                cout << idz[i].clothes_size << '\n';
            }
        }
        cout << "\nMale players with clothing size larger than S (4): \n";
        for(int i = 0; i < temp; i++) {
            if (idz[i].course > 2 && idz[i].sex == 1) {
                cout << idz[i].FIO << ' ';
                cout << idz[i].sex << ' ';
                cout << idz[i].age << ' ';
                cout << idz[i].course << ' ';
                cout << idz[i].razryad << ' ';
                cout << idz[i].clothes_size << '\n';
            }
        }
    }

    bool ReworkFileWithStudents(struct Student students[], char * FileName, unsigned short temp) {
        ofstream File;
        File.open(FileName);
        if(!File.is_open()) {
            cout << "\nERROR:cant open file\n";
            return 0;
        }
        else {
            for(int i = 0; i < temp; i++) {
                if(i != 0) {
                    File << '\n';
                }
                File << students[i].names.first_name << ' ';
                File << students[i].names.second_name << ' ';
                File << students[i].names.third_name << ' ';
                File << students[i].sex << ' ';
                File << students[i].aboutGroup.group << ' ';
                File << students[i].aboutGroup.number_in_group << ' ';
                File << students[i].marks.aig << ' ';
                File << students[i].marks.english << ' ';
                File << students[i].marks.informatics << ' ';
                File << students[i].marks.math_an << ' ';
                File << students[i].marks.philosophy << ' ';
                File << students[i].marks.physics << ' ';
                File << students[i].marks.programming << ' ';
                File << students[i].marks.sport;
            }
        }
        File.close();
    }

    void CheckStudentsMarks(struct Student students[], unsigned short temp) {
        unsigned short noMoney[10];
        unsigned short noMoneyCount = 0;
        unsigned short midMoney[10];
        unsigned short midMoneyCount = 0;
        unsigned short bigMoney[10];
        unsigned short bigMoneyCount = 0;

        for(int i = 0; i < temp; i++) {
            if(students[i].marks.aig < 5 || students[i].marks.english < 5 || students[i].marks.philosophy < 5
            || students[i].marks.physics < 5 || students[i].marks.programming < 5 || students[i].marks.informatics < 5
            || students[i].marks.sport < 5 || students[i].marks.math_an < 5) {
                if(students[i].marks.aig < 4 || students[i].marks.english < 4 || students[i].marks.philosophy < 4
                || students[i].marks.physics < 4 || students[i].marks.programming < 4 || students[i].marks.informatics < 4
                || students[i].marks.sport < 4 || students[i].marks.math_an < 4) {
                    noMoney[noMoneyCount] = i;
                    noMoneyCount++;
                }
                else {
                    midMoney[midMoneyCount] = i;
                    midMoneyCount++;
                }
            }
            else {
                bigMoney[bigMoneyCount] = i;
                bigMoneyCount++;
            }
        }
        cout << "\nStudents without a scholarship:\n";
        for(int i = 0; i < noMoneyCount; i++) {
            cout << students[noMoney[i]].names.first_name << ' ' << students[noMoney[i]].names.second_name
            << ' ' << students[noMoney[i]].names.third_name << '\n';
        }
        cout << "\nGood students:\n";
        for(int i = 0; i < midMoneyCount; i++) {
            cout << students[midMoney[i]].names.first_name << ' ' << students[midMoney[i]].names.second_name
                 << ' ' << students[midMoney[i]].names.third_name << '\n';
        }
        cout << "\nExcellent students:\n";
        for(int i = 0; i < bigMoneyCount; i++) {
            cout << students[bigMoney[i]].names.first_name << ' ' << students[bigMoney[i]].names.second_name
                 << ' ' << students[bigMoney[i]].names.third_name << '\n';
        }
    }

    bool ReadDataAboutStudents(struct Student students[], char * FileName, unsigned short &temp) {
        ifstream File;
        string data;
        File.open(FileName);
        if(!File.is_open()) {
            cout << "\nERROR:cant open file\n";
            return 0;
        }
        else {
            for(int i = 0; !File.eof(); i++) {
                File >> students[i].names.first_name;
                File >> students[i].names.second_name;
                File >> students[i].names.third_name;
                File >> students[i].sex;
                File >> students[i].aboutGroup.group;
                File >> students[i].aboutGroup.number_in_group;
                File >> students[i].marks.aig;
                File >> students[i].marks.sport;
                File >> students[i].marks.programming;
                File >> students[i].marks.physics;
                File >> students[i].marks.philosophy;
                File >> students[i].marks.math_an;
                File >> students[i].marks.informatics;
                File >> students[i].marks.english;
                temp++;
            }
        }
        File.close();
    }

    void PrintListOfStudents(struct Student students[], unsigned short temp) {
    CoutStart();
        for(int i = 0; i < temp; i++) {
            CoutList(students,i);
        }
    }

    void CountMenAndWomen(struct Student students[], unsigned short temp) {
        unsigned short men = 0;
        unsigned short women = 0;
        for(int i = 0; i < temp; i++) {
            if(students[i].sex == 1) {
                men++;
            }
            else {
                women++;
            }
        }
        cout << "\nIn the list of students:\n"
                "males - " << men << "\nfemales - " << women;
    }

    void PrintStudentsFromGroup(struct Student students[], unsigned short number) {
        cout << "Enter the number of the group whose students you want to see\n"
                "Number: ";
        cin >> number;
        cout << "\n";
        cout << "Group " << number << " students"<< " :\n";
        CoutStart();
        for(int i = 0; i < 100; i++) {
            if(number == students[i].aboutGroup.group) {
                CoutList(students,i);
            }
        }
    }

    void PrintStudentsWithNumber(struct Student students[], unsigned short number) {
        cout << "Enter the number of students in the group\n"
                "Number: ";
        cin >> number;
        cout << "\nStudents with number in a group " << number << " :\n";
        CoutStart();
        for(int i = 0; i < 100; i++) {
            if(number == students[i].aboutGroup.number_in_group) {
                CoutList(students,i);
            }
        }
    }

    bool AddNewStudent(struct Student students[], unsigned short &temp, char * FileName) {
        ofstream File;
        File.open(FileName, ios::app);
        if(!File.is_open()) {
            cout << "\nERROR:cant open file\n";
            return 0;
        }
        else {
            File << '\n';
            cout << "\nEnter the last name, first name and patronymic of the student (in turn)\n";
            cout << "\nLast name: ";
            cin >> students[temp].names.first_name;
            File << students[temp].names.first_name << ' ';
            cout << "First name: ";
            cin >> students[temp].names.second_name;
            File << students[temp].names.second_name << ' ';;
            cout << "Patronymic: ";
            cin >> students[temp].names.third_name;
            File << students[temp].names.third_name << ' ';;
            cout << "\nEnter the gender of the student (1 - male, 0 - female)\n";
            cout << "Gender: ";
            cin >> students[temp].sex;
            File << students[temp].sex << ' ';;
            cout << "\nEnter the group number and student number in the group (in turn)\n";
            cout << "Group number: ";
            cin >> students[temp].aboutGroup.group;
            File << students[temp].aboutGroup.group << ' ';;
            cout << "Student number: ";
            cin >> students[temp].aboutGroup.number_in_group;
            File << students[temp].aboutGroup.number_in_group << ' ';;
            cout << "\nEnter student grades (in turn)\n";
            cout << "Algebra and geometry: ";
            cin >> students[temp].marks.aig;
            File << students[temp].marks.aig << ' ';;
            cout << "English: ";
            cin >> students[temp].marks.english;
            File << students[temp].marks.english << ' ';;
            cout << "Informatic: ";
            cin >> students[temp].marks.informatics;
            File << students[temp].marks.informatics << ' ';;
            cout << "Mathematical analysis: ";
            cin >> students[temp].marks.math_an;
            File << students[temp].marks.math_an << ' ';;
            cout << "Philosophy: ";
            cin >> students[temp].marks.philosophy;
            File << students[temp].marks.philosophy << ' ';;
            cout << "Fiziks: ";
            cin >> students[temp].marks.physics;
            File << students[temp].marks.physics << ' ';;
            cout << "Programming: ";
            cin >> students[temp].marks.programming;
            File << students[temp].marks.programming << ' ';;
            cout << "Physical culture: ";
            cin >> students[temp].marks.sport;
            File << students[temp].marks.sport << ' ';;
        }
        File.close();
        temp++;
        cout << "\nThe new student on the list is now numbered " << temp <<'\n';
    }

    void EditStudent(struct Student students[], unsigned short temp) {
        int temp_for_choose = 0;
        cout << "\nSelect the student whose details you want to change\n"
                "Number: ";
        cin >> temp_for_choose;
        temp_for_choose--;
        cout << "\nEnter the last name, first name and patronymic of the student (in turn)\n";
        cout << "\nLast name: ";
        cin >> students[temp_for_choose].names.first_name;
        cout << "First name: ";
        cin >> students[temp_for_choose].names.second_name;
        cout << "Patronymic: ";
        cin >> students[temp_for_choose].names.third_name;
        cout << "\nEnter the gender of the student (1 - male, 0 - female)\n";
        cout << "Gender: ";
        cin >> students[temp_for_choose].sex;
        cout << "\nEnter the group number and student number in the group (in turn)\n";
        cout << "Group number: ";
        cin >> students[temp_for_choose].aboutGroup.group;
        cout << "Student number:";
        cin >> students[temp_for_choose].aboutGroup.number_in_group;
        cout << "\nEnter student grades (in turn)\n";
        cout << "Algebra and geometry: ";
        cin >> students[temp_for_choose].marks.aig;
        cout << "English: ";
        cin >> students[temp_for_choose].marks.english;
        cout << "Informatic: ";
        cin >> students[temp_for_choose].marks.informatics;
        cout << "Mathematical analysis: ";
        cin >> students[temp_for_choose].marks.math_an;
        cout << "Philosophy: ";
        cin >> students[temp_for_choose].marks.philosophy;
        cout << "Fiziks: ";
        cin >> students[temp_for_choose].marks.physics;
        cout << "Programming: ";
        cin >> students[temp_for_choose].marks.programming;
        cout << "Physical culture: ";
        cin >> students[temp_for_choose].marks.sport;
        ReworkFileWithStudents(students, "students.txt",temp);
    }

    void MaxMidMark(struct Student students[], unsigned short temp) {
        for(int i = 0; i < temp; i++) {
            students[i].marks.mid_of_marks = (students[i].marks.aig + students[i].marks.english + students[i].marks.math_an + students[i].marks.physics +
                    students[i].marks.philosophy + students[i].marks.sport + students[i].marks.programming + students[i].marks.informatics) / 8;
        }
        for (int j = 0; j < temp - 1; j++) {
            for (int i = 0; i < temp - j - 1; ++i) {
                if (students[i].marks.mid_of_marks < students[i + 1].marks.mid_of_marks) {
                    swap(students[i], students[i + 1]);
                }
            }
        }
        cout << "Top students by middle score:\n";
        for(int i = 0; i < 5 && i < temp; i++) {
            cout << students[i].names.first_name << ' ' << students[i].names.second_name << ' ' << students[i].names.third_name << '\n';
        }
        ReworkFileWithStudents(students, "students.txt",temp);
    }

int main() {
    struct Student students[100];
    unsigned short temp = 0;
    int number_of_task;
    while(true) {
        cout << "Select the job number you want to access\n"
                "01 - Add new student\n"
                "02 - Edit student\n"
                "03 - Print list of students\n"
                "04 - Print students from group\n"
                "05 - Top most successful students with the highest rating average score\n"
                "06 - Number of male and female students\n"
                "07 - List of student by marks\n"
                "08 - Print student data with number N\n"
                "09 - Read data from file\n"
                "10 - IHW\n"
                "00 - Leave programm\n"
                "Number: ";
        
        cin >> number_of_task;
        switch (number_of_task) {
            case 1: {
                AddNewStudent(students, temp, "students.txt");
                break;
            }
            case 2: {
                EditStudent(students, temp);
                break;
            }
            case 3: {
                PrintListOfStudents(students, temp);
                break;
            }
            case 4: {
                PrintStudentsFromGroup(students, number_of_task);
                break;
            }
            case 5: {
                MaxMidMark(students, temp);
                break;
            }
            case 6: {
                CountMenAndWomen(students, temp);
                break;
            }
            case 7: {
                CheckStudentsMarks(students, temp);
                break;
            }
            case 8: {
                PrintStudentsWithNumber(students, number_of_task);
                break;
            }
            case 9: {
                ReadDataAboutStudents(students, "students.txt",temp);
                break;
            }
            case 10: {
                IdzFromPract1("voleyball.txt");
                break;
            }
            case 0:{
                return(0);
            }
            default: {
                cout << "\nERROR:Job with this number does not exist\n";
                break;
            }
        }
    }
}
