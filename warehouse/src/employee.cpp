#include <iostream>
#include <string>

#include "include/employee.hpp"

Employee::Employee(std::string _Name, bool forkliftCertificate)
    : name(_Name), busy(false), forkliftCertificate(forkliftCertificate){
}

std::string Employee::getName() {
    return this->name;
}

bool Employee::getBusy() {
    return this->busy;
}

void Employee::setBusy(bool busy) {
    this->busy = busy;
}

bool Employee::getForkliftCertificate() {
    return this->forkliftCertificate;
}

void Employee::setForkliftCertificate(bool forkliftCertificate) {
    this->forkliftCertificate = forkliftCertificate;
}
