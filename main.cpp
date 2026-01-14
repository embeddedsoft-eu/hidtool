#include <hidapi/hidapi.h>

#include <cstdint>
#include <cstring>
#include <iostream>
#include <vector>
#include <stdexcept>

constexpr size_t REPORT_LENGTH = 256;

class HidDevice {
public:
    HidDevice(uint16_t vid, uint16_t pid)
    {
        device_ = hid_open(vid, pid, nullptr);
        if (!device_) {
            throw std::runtime_error("Failed to open HID device");
        }
    }

    ~HidDevice()
    {
        if (device_) {
            hid_close(device_);
        }
    }

    bool write(const std::vector<uint8_t>& data)
    {
        std::vector<uint8_t> buffer(REPORT_LENGTH, 0);
        std::memcpy(buffer.data(), data.data(),
                    std::min(data.size(), buffer.size()));

        int res = hid_write(device_, buffer.data(), buffer.size());
        return res >= 0;
    }

private:
    hid_device* device_{nullptr};
};

int main(int argc, char* argv[])
{
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " VID PID [-w text]\n";
        return 1;
    }

    uint16_t vid = static_cast<uint16_t>(std::stoul(argv[1], nullptr, 16));
    uint16_t pid = static_cast<uint16_t>(std::stoul(argv[2], nullptr, 16));

    try {
        HidDevice hid(vid, pid);

        if (argc >= 5 && std::strcmp(argv[3], "-w") == 0) {
            std::vector<uint8_t> data(
                argv[4], argv[4] + std::strlen(argv[4])
                );

            if (!hid.write(data)) {
                std::cerr << "Write failed\n";
                return 2;
            }
        }
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
        return -1;
    }

    return 0;
}
