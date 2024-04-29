#include <iostream>

class SalonAppointment
{
private:
    std::string customerName;  
    std::string appointmentDate;
    int fee;
    bool confirmed;
    static int appointmentsNum;
    static int totalEarning;

public:
    SalonAppointment(const std::string& customerName, const std::string& appointmentDate, int fee, bool confirmed)
        : customerName(customerName), appointmentDate(appointmentDate), fee(fee), confirmed(confirmed)
    {
        updateEarnings(fee);
    }

    void updateEarnings(int fee)
    {
        totalEarning += fee;
        appointmentsNum++;
    }

    std::string getCustomerName() const { return customerName; }
    std::string getAppointmentDate() const { return appointmentDate; }
    bool isConfirmed() const { return confirmed; }
    static int getAppointmentsNum() { return appointmentsNum; }
    static int getTotalEarning() { return totalEarning; }

    static int calcAverage()
    {
        if (appointmentsNum == 0)
            return 0;
        return totalEarning / appointmentsNum;
    }
};

int SalonAppointment::appointmentsNum = 0;
int SalonAppointment::totalEarning = 0;

int main()
{
    SalonAppointment appointment1("RAO Ghulam", "2024-02-09", 100, true);
    SalonAppointment appointment2("Murtaza", "2024-02-10", 75, false);
    SalonAppointment appointment3("Naveed Sheikh", "2024-02-11", 80, true);
    SalonAppointment appointment4("Hamid ", "2024-02-12", 90, true);

    int average = SalonAppointment::calcAverage();
    std::cout << "Average earnings: " << average;

    return 0;
}
