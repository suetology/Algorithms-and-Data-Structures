#pragma once

class Patient 
{
private:
    int disease;
    int serviceTime = 0;

public:
    Patient(int disease);
    void Proceed();

    inline bool IsHealthy() const { return disease == -1; }
    inline int GetDisease() const { return disease; }
    inline int GetServiceTime() const { return serviceTime; }
};