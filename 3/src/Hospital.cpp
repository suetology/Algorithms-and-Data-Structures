#include "Hospital.h"

#include <stdexcept>

bool Hospital::initialized = false;

Hospital& Hospital::GetInstance()
{
    static Hospital instance;
    return instance;
}

void Hospital::Init(int districtDoctorsCount, int districtDoctorsSalary, int districtDoctorsServiceTime,
                    int specialistsCount, int specialistsSalary, int specialistsServiceTime)
{
    if (initialized)
        throw std::runtime_error("Hospital has been already initialized!");
    
    for (int i = 0; i < specialistsCount; i++) 
    {
        Specialist* specialist = new Specialist(specialistsSalary, specialistsServiceTime, i);
        specialists.push_back(specialist);
    }

    for (int i = 0; i < districtDoctorsCount; i++)
    {
        DistrictDoctor* districtDoctor = new DistrictDoctor(districtDoctorsSalary, districtDoctorsServiceTime);
        districtDoctors.push_back(districtDoctor);
    }

    initialized = true;
}

void Hospital::EndWork()
{
    for (Patient* patient : GetPatientsQueue())
        delete patient;

    for (Patient* patient : GetServedPatients())
        delete patient;

    for (DistrictDoctor* districtDoctor : GetDistrictDoctors())
        districtDoctor->EndWork();

    for (Specialist* specialist : GetSpecialists())
        specialist->EndWork();

}

int& Hospital::GetPatientsCount()
{
    patientsCount;
}

std::vector<Patient*>& Hospital::GetPatientsQueue()
{
    if (!initialized)
        throw std::runtime_error("Hospital has not been initialized!");
    return patientsQueue;
}

std::vector<Patient*>& Hospital::GetServedPatients()
{
    if (!initialized)
        throw std::runtime_error("Hospital has not been initialized!");
    return servedPatients;
}

std::vector<DistrictDoctor*>& Hospital::GetDistrictDoctors()
{
    if (!initialized)
        throw std::runtime_error("Hospital has not been initialized!");
    return districtDoctors;
}

std::vector<Specialist*>& Hospital::GetSpecialists()
{
    if (!initialized)
        throw std::runtime_error("Hospital has not been initialized!");
    return specialists;
}