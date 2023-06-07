#include "Specialist.h"

#include "Hospital.h"

#include <vector>

Specialist::Specialist(int salary, int serviceTime, int curedDisease)
    : HospitalWorker(salary, serviceTime), curedDisease(curedDisease) { }

void Specialist::Proceed()
{
    if (!IsBusy())
        return;

    currentPatient->Proceed();
    for (Patient* patient : patientsQueue)
        patient->Proceed();

    busyTime--;
    if (busyTime == 0) 
        ReleasePatient();
}

void Specialist::AcceptPatient(Patient* patient)
{	
    if (!IsBusy())
    {
        currentPatient = patient;
	    busyTime = serviceTime;
    }  
    else 
    {
        patientsQueue.push_back(patient);
    }
}

void Specialist::ReleasePatient()
{
    if (currentPatient->IsHealthy() || currentPatient->GetDisease() == curedDisease)
        Hospital::GetInstance().GetServedPatients().push_back(currentPatient);
    else 
	    Hospital::GetInstance().GetSpecialists()[currentPatient->GetDisease()]->AcceptPatient(currentPatient);
    
    currentPatient = nullptr;
    if (patientsQueue.size() > 0)
    {
        currentPatient = patientsQueue.front();
        patientsQueue.erase(patientsQueue.begin());
    }
}

void Specialist::EndWork()
{
    if (currentPatient != nullptr)
        delete currentPatient;
    
    for (Patient* patient : patientsQueue)
        delete patient;
}