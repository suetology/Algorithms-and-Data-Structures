#pragma once

#include <vector>

#include "HospitalWorker.h"

class Specialist : public HospitalWorker
{
private:
    int curedDisease;
    std::vector<Patient*> patientsQueue;

public:
    Specialist(int salary, int serviceTime, int curedDisease);

    void Proceed() override;
    void AcceptPatient(Patient* patient) override;
    void ReleasePatient() override;
    void EndWork() override;
};