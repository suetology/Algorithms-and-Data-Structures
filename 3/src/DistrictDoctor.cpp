#include "DistrictDoctor.h"

#include "Hospital.h"

#include <vector>

DistrictDoctor::DistrictDoctor(int salary, int serviceTime)
    : HospitalWorker(salary, serviceTime) { }

void DistrictDoctor::Proceed()
{
	if (!IsBusy())
        return;

    busyTime--;
	currentPatient->Proceed();

    if (busyTime == 0) 
        ReleasePatient();
}

void DistrictDoctor::AcceptPatient(Patient* patient)
{
	if (IsBusy())
		return;
	
	currentPatient = patient;
	busyTime = serviceTime;
}

void DistrictDoctor::ReleasePatient()
{
	if (currentPatient->IsHealthy())
	{
		Hospital::GetInstance().GetServedPatients().push_back(currentPatient);
		currentPatient = nullptr;
		return;
	}

	int disease = currentPatient->GetDisease();
	Hospital::GetInstance().GetSpecialists()[disease]->AcceptPatient(currentPatient);

	currentPatient = nullptr;
}

void DistrictDoctor::EndWork()
{
	if (currentPatient != nullptr)
		delete currentPatient;
}