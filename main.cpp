#include <iostream>
#include "Person.h"

using namespace std;

int main() {
    Person somebody1;

    cout << somebody1.get_first_name() << " " << somebody1.get_last_name() << " " << somebody1.get_patronymic() << endl;
    somebody1.set_name("1561", "hkjshakjf" , "Anonimovich");
    cout << somebody1.get_first_name() << " " << somebody1.get_last_name() << " " << somebody1.get_patronymic() << endl;
    cout << endl;
    somebody1.show_address();
    cout << endl;
    somebody1.show_sex();
    cout << endl;
    somebody1.show_education();
    cout << endl;
    somebody1.show_year_of_birth();
    cout << endl;
}