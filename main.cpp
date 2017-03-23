#include <iostream>
#include <fstream>
#include "Person.h"
#include <cstring>

#define NUM_PERSON 100
#define MAX_NAME 300

using namespace std;

Person* create_persons_array(Person* arr, ifstream& file, int& number);
void list_older_year(Person* arr, int year, int number);
void list_hight_education(Person* arr, int number);
void list_male(Person* arr, int number);

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "ERROR! File name is absents." << endl;
        return -1;
    }
    ifstream file(argv[1]);
    if (!file) {
        cout << "ERROR! File doesn't open." << endl;
        return -1;
    }
    int number = 0;
    Person array[NUM_PERSON];
    create_persons_array(array, file, number);
    if(!number){
        cout << "ERROR! Persons field are absent." << endl;
        return -1;
    }
    file.close();

    //list_older_year(array, 2000, number);
    //list_hight_education(array, number);
    list_male(array, number);
    return  0;
}

Person* create_persons_array(Person* arr, ifstream& file, int& number) {
    const char* asd;
    Person a(asd);
    char *buf = new char[1000];
    int i = -1;
    while (! file.eof() ) {
        file.getline(buf, ';');
        if(strstr(buf, "Person")) {
            i++;
            if (i == NUM_PERSON)
                return arr;
            continue;
        }
        if (strstr(buf, "name")) {
            char last[MAX_NAME] = "\0", first[MAX_NAME] = "\0", patronymic[MAX_NAME] = "\0";
            int j = 0, k = 0, flag = 0, l = 0;
            while(buf[j]) {
                if (buf[j] == ' ') {
                        flag = 1;
                    l = 0;
                    k++;
                }
                else {
                    if (flag) {
                        switch (k) {
                            case 1: {
                                last[l] = buf[j];
                                last[l + 1] = '\0';
                                break;
                            }
                            case 2: {
                                first[l] = buf[j];
                                first[l + 1] = '\0';
                                break;
                            }
                            case 3: {
                                patronymic[l] = buf[j];
                                patronymic[l + 1] = '\0';
                                break;
                            }
                        }
                        if(++l >= MAX_NAME)
                            continue;
                    }
                }
                j++;
            }
            arr[i].set_name(last, first, patronymic);
            last[0] = '\0';
            first[0] = '\0';
            patronymic[0] = '\0';
            continue;
        }
        if (strstr(buf, "address")) {
            arr[i].set_address(buf + 9);
            continue;
        }
        if (strstr(buf, "sex")) {
            if (buf[5] == '1')
                arr[i].set_sex(female);
            continue;
        }
        if (strstr(buf, "education")) {
            if (buf[11] != '0')
                if(buf[11] == '1')
                    arr[i].set_education(college);
                else
                    arr[i].set_education(university);
            continue;
        }
        if (strstr(buf, "year")){
            int year = atoi(buf + 6);
            arr[i].set_year_of_birth(year);
        }
    }
    number = i + 1;
    return arr;
}
void list_older_year(Person* arr, int year, int number) {
    for (int i = 0; i < number; i++) {
        if (arr[i].get_year_of_birth() > year) {
            arr[i].show_all();
        }
    }
}
void list_hight_education(Person* arr, int number) {
    for (int i = 0; i < number; i++) {
        if (arr[i].get_education() == university) {
            arr[i].show_all();
        }
    }
}
void list_male(Person* arr, int number) {
    for (int i = 0; i < number; i++){
        if(arr[i].get_sex() == male) {
            arr[i].show_all();
        }
    }
}