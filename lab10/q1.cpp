#include <iostream>
using namespace std;

class Server {
protected:
    string IP;

public:
    Server(string ip) : IP(ip) {}
};

class Platform {
protected:
    string PlatformName;

public:
    Platform(string name) : PlatformName(name) {}
};

class Logo : protected Server, protected Platform {
    string logo;

public:
    Logo(string l, string s, string p) : logo(l), Platform(p), Server(s) {}
    friend void Display(Logo &logo);
    friend void ChangeLogo(string newlogo, Logo &logo);
};

void ChangeLogo(string newlogo, Logo &l) {
    l.logo = newlogo;
}

void Display(Logo &logo) {
    cout << "Logo: " << logo.logo << endl;
    cout << "Platform Name: " << logo.PlatformName << endl;
    cout << "Server Name: " << logo.IP << endl;
}

int main() {
    Logo logo("Blue Bird", "192.158.1.38", "Twitter");

    Display(logo);

    ChangeLogo("Doge Coin", logo);
    Display(logo);

    return 0;
}
