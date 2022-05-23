#include <iostream>

struct Student {
    char* name;
    size_t nMarks;
    int* marks;

};

void init_student(Student& st)
{
    st.name = nullptr;
    st.marks = nullptr;
    st.nMarks = 0;

}

void init_student(Student& st, const char* name, const int* marks, size_t nMarks)
{
    size_t nameLen = strlen(name);

    st.name = new char[nameLen + 1];
    strcpy(st.name, name);
    st.marks = nullptr;

    st.nMarks = nMarks;
    if (nMarks > 0) {
        st.marks = new int[nMarks];
        for (size_t i = 0; i < st.nMarks; i++)
        {
            st.marks[i] = marks[i];
        }

    }


}

bool student_check(const Student& st)
{
    if (st.name == nullptr && st.marks == nullptr) return 1; else return 0;
}

void student_set_name(Student& st, const char* name)
{
    if (st.name != nullptr) {
        delete[] st.name;
        st.name = nullptr;
    }
    size_t nameLen = strlen(name);
    st.name = new char[nameLen + 1];
    strcpy(st.name, name);
}

void student_relise(Student& st)
{
    if (st.name != nullptr)
    {
        delete[] st.name;
    }
    if (st.marks != nullptr)
        delete[] st.marks;
    init_student(st);
}

void student_get_mark(Student& st, int mark)
{
    int* marks = st.marks;

    st.marks = new int[st.nMarks + 1];

    if (marks != nullptr) {
        for (size_t i = 0; i < st.nMarks; i++)
        {
            st.marks[i] = marks[i];
        }
        delete[] marks;
    }
    st.marks[st.nMarks] = mark;
    st.nMarks++;
}

void Print_arr(Student& st)
{
    for (int i = 0; i < st.nMarks; i++)
    {
        std::cout << st.marks[i] << std::endl;
    }
}

double Sr_bal(Student& st)
{
    double avg{};
    for (int i = 0; i < st.nMarks; i++)
    {
        avg += st.marks[i];
    }
    return avg / st.nMarks;
}

int main()
{
    Student st;
    init_student(st);
    student_set_name(st, "Hasan");
    student_get_mark(st, 5);
    student_get_mark(st, 2);
    student_get_mark(st, 3);
    student_get_mark(st, 4);
    Print_arr(st);
    std::cout << Sr_bal(st) << std::endl;
    std::cout << st.name << std::endl;
    // student_relise(st);
    std::cout << st.name;

}