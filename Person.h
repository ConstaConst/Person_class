
#ifndef HW_4_PERSON_H
#define HW_4_PERSON_H

enum sex {male = true, female = false};
enum education {school, college, university};

class Person {
public:
    Person(char* last_name = nullptr, char* first_name = nullptr,
           char* patronymic = nullptr, char* address = nullptr,
          const bool sex = male, const unsigned int education = school, const int year = 0);
    Person(const Person& rhs);
    ~Person();

    const bool set_name(char* last = nullptr, char* first = nullptr, char* patronymic= nullptr);
    const bool set_address(char* address = nullptr);
    void set_sex(bool sex = male);
    void set_education(unsigned int education = school);
    void set_year_of_birth(int year = 0);

    const char* const get_last_name() const;
    const char* const get_first_name() const;
    const char* const get_patronymic() const;
    const char* const get_address() const;
    const bool get_sex() const;
    const unsigned get_education() const;
    const int get_year_of_birth() const;

    void show_last_name() const;
    void show_first_name() const;
    void show_patronymic() const;

    void show_address() const;
    void show_sex() const;
    void show_education() const;
    void show_year_of_birth() const;
    void show_all() const;

private:
    char* last_name;
    char* first_name;
    char* patronymic;
    char* address;
    bool sex;
    unsigned int education;
    int year_of_birth;

    const bool change_str (char** pre_str, char* new_str);
};


#endif //HW_4_PERSON_H
