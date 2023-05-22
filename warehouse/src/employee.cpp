#pragma once
#include <iostream>
#include <string>

#include "include/employee.hpp"

Employee::Employee(std::string name, bool forkliftCertificate)
    : name(name), forkliftCertificate(forkliftCertificate), busy(false) {
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