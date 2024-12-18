#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Department;

class Company {
public:
    string name;
    vector<shared_ptr<Department>> departments;

    Company(const string& name) : name(name) {
        cout << "Створено Company: " << name << endl;
    }

    ~Company() {
        cout << "Видалено Company: " << name << endl;
    }

    void addDepartment(const shared_ptr<Department>& dept) {
        departments.push_back(dept);
    }

    void printDepartments() const {
        cout << "Компанія: " << name << " має відділи:\n";
        for (const auto& dept : departments) {
            cout << "- " << dept->name << endl;
        }
    }
};

class Department {
public:
    string name;
    weak_ptr<Company> company;

    Department(const string& name) : name(name) {
        cout << "Створено Department: " << name << endl;
    }

    ~Department() {
        cout << "Видалено Department: " << name << endl;
    }

    void setCompany(const shared_ptr<Company>& comp) {
        company = comp;
    }
};

int main() {
    shared_ptr<Company> company = make_shared<Company>("Tech Corp");

    shared_ptr<Department> hr = make_shared<Department>("HR");
    shared_ptr<Department> it = make_shared<Department>("IT");

    hr->setCompany(company);
    it->setCompany(company);

    company->addDepartment(hr);
    company->addDepartment(it);

    cout << "\nІнформація про компанію та відділи:\n";
    company->printDepartments();

    return 0;
}
