#include "Patient.h"

Patient::Patient(int disease)
    : disease(disease) { }

void Patient::Proceed()
{
    serviceTime++;
}