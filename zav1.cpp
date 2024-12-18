#include <iostream>
#include <vector>
#include <memory>
#include <utility>

using namespace std;

class Employee {
public:
    string name;
    int id;

    Employee(const string& name, int id) : name(name), id(id) {
        cout << "Створено Employee: " << name << " з ID: " << id << endl;
    }

    ~Employee() {
        cout << "Видалено Employee: " << name << endl;
    }

    void printInfo() const {
        cout << "Ім'я: " << name << ", ID: " << id << endl;
    }
};

int main() {
    vector<unique_ptr<Employee>> employees;

    employees.push_back(make_unique<Employee>("Олег", 1));
    employees.push_back(make_unique<Employee>("Анна", 2));
    employees.push_back(make_unique<Employee>("Ірина", 3));

    cout << "\nСписок працівників:\n";
    for (const auto& emp : employees) {
        emp->printInfo();
    }

    vector<unique_ptr<Employee>> newEmployees;
    newEmployees.push_back(move(employees[1]));

    cout << "\nПісля передачі власності:\n";
    cout << "Старий список:\n";
    for (const auto& emp : employees) {
        if (emp) emp->printInfo();
        else cout << "Порожній слот\n";
    }

    cout << "Новий список:\n";
    for (const auto& emp : newEmployees) {
        emp->printInfo();
    }

    return 0;
}
