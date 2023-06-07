#pragma once 

#include "HospitalWorker.h"

class DistrictDoctor : public HospitalWorker 
{
public:
    DistrictDoctor(int salary, int serviceTime);

    void Proceed() override;
    void AcceptPatient(Patient* patient) override;
    void ReleasePatient() override;
    void EndWork() override;
};