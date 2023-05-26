#pragma once
#include <string>

class Employee {
    private:
        std::string name;  // Met docent besproken dat de const (tijdelijk) weg mag vanwege error
        bool busy;
        bool forkliftCertificate;

    public:
        Employee(std::string newName, bool forkliftCertificate);  // Naar newName veranderd vanwege error (voordat const weg mocht)
        std::string getName();
        bool getBusy();
        void setBusy(bool busy);
        bool getForkliftCertificate();
        void setForkliftCertificate(bool forkliftCertificate);
};
