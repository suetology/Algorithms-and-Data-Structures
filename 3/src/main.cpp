#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <time.h>
#include <algorithm>
#include <bits/stdc++.h>

#include "BigInt.h"
#include "Hospital.h"
#include "Patient.h"
#include "DistrictDoctor.h"
#include "Specialist.h"

int process, workDayLength, patientSpawnChance, 
    specialistsCount, specialistSalary, specialistServiceTime,
    districtDoctorsCount, districtDoctorsSalary, districtDoctorServiceTime;

void readFile(char* filename);
void simulateProcess1();
void simulateProcess2();
void calculateResults();

int main(int argc, char* argv[]) 
{
    if (argc < 2)
    {
        std::cerr << "You should specify file with entry data as a command line agrument" << std::endl;
        return 1;
    }
    srand(time(0));
    readFile(argv[1]);

    Hospital::GetInstance().Init(districtDoctorsCount, districtDoctorsSalary, districtDoctorServiceTime,
                                 specialistsCount, specialistSalary, specialistServiceTime);
    if (process == 1)
    {
        simulateProcess1();
    }
    else if (process == 2)
    {
        simulateProcess2();
    }
    else 
    {
        std::cerr << "You should choose either process 1 or 2" << std::endl;
        Hospital::GetInstance().EndWork();
        return 2;
    }
    calculateResults();
    Hospital::GetInstance().EndWork();

	return 0;
}

void readFile(char* filename)
{
    std::ifstream inFile;
    inFile.open(filename);
    inFile >> process >> workDayLength >> patientSpawnChance >>
    specialistsCount >> specialistSalary >> specialistServiceTime >>
    districtDoctorsCount >> districtDoctorsSalary >> districtDoctorServiceTime;
    inFile.close();
}

void simulateProcess1()
{
    for (BigInt timePassed((int)0); timePassed < workDayLength; timePassed++)
    {
        for (Specialist* specialist : Hospital::GetInstance().GetSpecialists())
            specialist->Proceed();

        if ((rand() % 100 + 1) <= patientSpawnChance)
        {
            Hospital::GetInstance().GetPatientsCount()++;
            int disease = rand() % (specialistsCount + 1) - 1;
            Patient* patient = new Patient(disease);
            
            int specialistChoice = rand() % (specialistsCount);
            Hospital::GetInstance().GetSpecialists()[specialistChoice]->AcceptPatient(patient);
        }
    }
}

void simulateProcess2()
{
    for (BigInt timePassed((int)0); timePassed < workDayLength; timePassed++)
    {
        if ((rand() % 100 + 1) <= patientSpawnChance)
        {
            Hospital::GetInstance().GetPatientsCount()++;
            int disease = rand() % (specialistsCount + 1) - 1;
            Patient* patient = new Patient(disease);
            Hospital::GetInstance().GetPatientsQueue().push_back(patient);
        }

        for (Specialist* specialist : Hospital::GetInstance().GetSpecialists())
            specialist->Proceed();
        
        for (DistrictDoctor* districtDoctor : Hospital::GetInstance().GetDistrictDoctors())
        {
            districtDoctor->Proceed();
            if (!districtDoctor->IsBusy() && Hospital::GetInstance().GetPatientsQueue().size() > 0)
            {
                districtDoctor->AcceptPatient(Hospital::GetInstance().GetPatientsQueue().front());
                Hospital::GetInstance().GetPatientsQueue().erase(Hospital::GetInstance().GetPatientsQueue().begin());
            }
        }

        for (Patient* patient : Hospital::GetInstance().GetPatientsQueue())
            patient->Proceed();
    }
}

void calculateResults()
{
    int minServiceTime = INT_MAX;
    int maxServiceTime = 0;
    int sumServiceTime = 0;    
    for (Patient* patient : Hospital::GetInstance().GetServedPatients())
    {
        if (minServiceTime > patient->GetServiceTime())
            minServiceTime = patient->GetServiceTime();

        if (maxServiceTime < patient->GetServiceTime())
            maxServiceTime = patient->GetServiceTime();
        
        sumServiceTime += patient->GetServiceTime();
    }

    float averageServiceTime = float(sumServiceTime) / Hospital::GetInstance().GetServedPatients().size();
    int hospitalExpenses;
    
    if (process == 1)
        hospitalExpenses = specialistsCount * specialistSalary;
    else if (process == 2)
        hospitalExpenses = districtDoctorsCount * districtDoctorsSalary + specialistsCount * specialistSalary;

    std::cout << std::setfill('.');
    std::cout << "Pradiniai duomenys:" << std::endl;
    std::cout << std::left << std::setw(40) << "Darbo dienos ilgis:" << std::right << std::setw(5) << workDayLength << std::endl;  
    std::cout << std::left << std::setw(40) << "Paciento atvykimo tikimybe:" << std::right << std::setw(5) << patientSpawnChance << std::endl;
    std::cout << std::left << std::setw(40) << "Specialistu kiekis:" << std::right << std::setw(5) << specialistsCount << std::endl;
    std::cout << std::left << std::setw(40) << "Specialistu dienos alga:" << std::right << std::setw(5) << specialistSalary << std::endl;
    std::cout << std::left << std::setw(40) << "Specialistu aptarnavimo laikas:" << std::right << std::setw(5) << specialistServiceTime << std::endl;
    std::cout << std::left << std::setw(40) << "Apilinkes gydytoju kiekis:" << std::right << std::setw(5) << districtDoctorsCount << std::endl;
    std::cout << std::left << std::setw(40) << "Apilinkes gydytoju dienos alga:" << std::right << std::setw(5) << districtDoctorsSalary << std::endl;
    std::cout << std::left << std::setw(40) << "Apilinkes gydytoju aptarnavimo laikas:" << std::right << std::setw(5) << districtDoctorServiceTime << std::endl;

    std::cout << "\nDienos rezultatai:" << std::endl;
    std::cout << std::left << std::setw(40) << "Pacientu atejo per diena:" << std::right << std::setw(5) << Hospital::GetInstance().GetPatientsCount() << std::endl;  
    std::cout << std::left << std::setw(40) << "Aptarnauta pacientu per diena:" << std::right << std::setw(5) << Hospital::GetInstance().GetServedPatients().size() << std::endl;  
    std::cout << std::left << std::setw(40) << "Minimalus aptarnavimo laikas:" << std::right << std::setw(5) << minServiceTime << std::endl;  
    std::cout << std::left << std::setw(40) << "Maksimalus aptarnavimo laikas:" << std::right << std::setw(5) << maxServiceTime << std::endl; 
    std::cout << std::left << std::setw(40) << "Vidutins aptarnavimo laikas:" << std::right << std::setw(5) << averageServiceTime << std::endl; 
    std::cout << std::left << std::setw(40) << "Poliklinikos dienos islaidos algoms:" << std::right << std::setw(5) << hospitalExpenses << std::endl; 
}