#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <string>


class Device {
public:
    virtual void poll() = 0; 
    virtual ~Device() {}    
};

class ElectricityCounter : public Device {
public:
    void poll() override {
        std::cout << "Polling Electricity Counter" << std::endl;   
    }
};

class DigitalInputBlock : public Device {
public:
    void poll() override {
        std::cout << "Polling Digital Input Block" << std::endl;   
    }
};


class HeatingControlBlock : public Device {
public:
    void poll() override {
        std::cout << "Polling Heating Control Block" << std::endl;
    }
};


class SmartHomeSystem {
private:
    std::vector<std::shared_ptr<Device>> devices;

public:
    void addDevice(std::shared_ptr<Device> device) {
        devices.push_back(device);
    }

    void pollAllDevices() {
        for (const auto& device : devices) {
            device->poll();
        }
    }

    const std::vector<std::shared_ptr<Device>>& getDevices() const {
        return devices;
    }
};

int main() {
    SmartHomeSystem smartHomeSystem;

    
    std::ifstream configFile("devices.txt");
    if (configFile.is_open()) {
        std::string deviceType;
        while (std::getline(configFile, deviceType)) {
            if (deviceType == "ElectricityCounter") {
                smartHomeSystem.addDevice(std::make_shared<ElectricityCounter>());
            }
            else if (deviceType == "DigitalInputBlock") {
                smartHomeSystem.addDevice(std::make_shared<DigitalInputBlock>());
            }
            else if (deviceType == "HeatingControlBlock") {
                smartHomeSystem.addDevice(std::make_shared<HeatingControlBlock>());
            }
        }
        configFile.close();
    }

    
    smartHomeSystem.pollAllDevices();

    // Print the created objects to the console
    for (const auto& device : smartHomeSystem.getDevices()) {
        device->poll();
    }

    return 0;
}