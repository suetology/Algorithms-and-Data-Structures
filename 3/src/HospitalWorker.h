#pragma once

#include "Patient.h"

class HospitalWorker 
{
protected:
    int salary;
    int serviceTime;

    int busyTime = 0;
    Patient* currentPatient = nullptr;

    inline HospitalWorker(int salary, int serviceTime)
        : salary(salary), serviceTime(serviceTime) { }

public:
    inline bool IsBusy() const { return currentPatient != nullptr; };

    virtual void Proceed() = 0;
    virtual void AcceptPatient(Patient* patient) = 0;
    virtual void ReleasePatient() = 0;
    virtual void EndWork() = 0;
};