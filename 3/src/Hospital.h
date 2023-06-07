#pragma once 

#include <vector>

#include "DistrictDoctor.h"
#include "Specialist.h"

class Hospital
{
private:
    static bool initialized;

    int patientsCount = 0;
    std::vector<Patient*> patientsQueue;
    std::vector<Patient*> servedPatients;
    std::vector<DistrictDoctor*> districtDoctors;
    std::vector<Specialist*> specialists;

    Hospital() = default;
public:
    Hospital(const Hospital& other) = delete;
    Hospital& operator=(const Hospital& other) = delete;

    static Hospital& GetInstance();

    void Init(int districtDoctorsCount, int districtDoctorsSalary, int districtDoctorsServiceTime,
              int specialistsCount, int specialistsSalary, int specialistsServiceTime);
    void EndWork();

    int& GetPatientsCount();
    std::vector<Patient*>& GetPatientsQueue();
    std::vector<Patient*>& GetServedPatients();
    std::vector<DistrictDoctor*>& GetDistrictDoctors();
    std::vector<Specialist*>& GetSpecialists();
};