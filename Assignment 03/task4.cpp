#include "iostream"
#include "cmath"
using namespace std;

class Drone {
protected:
    float lat, longi, alt, speed;

public:
    Drone(float lat, float lon, float alt, float speed)  {
         this-> lat=lat;
        this-> longi=lon;
        this-> alt=alt;
        this-> speed=speed;
    }

    void setSpeed(const float speed) {
        try {
            if (speed < 0) throw "Invalid speed";
            else this->speed = speed;
        }
        catch (char* ex) {
            cout << ex;
        }
    }

    void adjustAltitude(const float meters) { alt = meters; }
};

class Flyable {
public:
    virtual void navigateTo(float latitude, float longitude, float altitude) = 0;
    virtual void takeoff() = 0;
    virtual void land() = 0;
};

class Scannable {
public:
    virtual void scanArea(float radius) = 0;
};

class ReconDrone : public Drone, public Flyable, public Scannable {
    float cameraResolution, maxFlightTime;

public:
    ReconDrone(float lat, float lon, float alt, float s, float cam_res, float max_time) : Drone(lat, lon, alt, s), cameraResolution(cam_res), maxFlightTime(max_time) {}

    void navigateTo(float latitude, float longitude, float altitude) override {
        float dx = latitude - lat;
        float dy = longitude - longi;
        float dz = altitude - alt;
        float distance = sqrt(pow(dx, 2) + pow(dy, 2) + pow(dz, 2));
        cout << "Time required to reach coordinates: " << distance / speed << " seconds" << endl;
    }

    void takeoff() { cout << "ReconDrone takeoff" << endl; }

    void land() { cout << "ReconDrone land" << endl; }

    void scanArea(float radius) {
        cout << "Scanning area within radius: " << radius << " meters." << endl;
        int detectedObjects = rand() % 10;
        cout << "Detected " << detectedObjects << " objects within the radius." << endl;
    }
};

int main() {
    ReconDrone myDrone(45, 23.2437, 360, 50, 5.5, 12);
    myDrone.takeoff();
    myDrone.setSpeed(120);
    myDrone.navigateTo(49, -23.2437, 780);
    myDrone.scanArea(400);
    myDrone.land();
    return 0;
}
