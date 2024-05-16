#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class Address {
private:
    std::string city;
    std::string street;
    std::string houseNumber;
    std::string apartmentNumber;

public:
    Address(std::string city, std::string street, std::string houseNumber, std::string apartmentNumber)
        : city(city), street(street), houseNumber(houseNumber), apartmentNumber(apartmentNumber) {}

    std::string get_output_address() const {
        return city + ", " + street + ", " + houseNumber + ", " + apartmentNumber;
    }

    std::string get_city() const {
        return city;
    }
};

void insertion_sort(std::vector<Address>& addresses) {
    for (size_t i = 1; i < addresses.size(); ++i) {
        Address key = addresses[i];
        int j = i - 1;

        while (j >= 0 && addresses[j].get_city() > key.get_city()) {
            addresses[j + 1] = addresses[j];
            j = j - 1;
        }
        addresses[j + 1] = key;
    }
}

int main() {
    std::ifstream input("D:\\in2.txt");
    std::ofstream output("D:\\out2.txt");

    if (!input.is_open()) {
        std::cerr << "Error opening input file." << std::endl;
        return 1;
    }

    int n;
    input >> n;
    input.ignore();

    std::vector<Address> addresses;
    addresses.reserve(n);

    for (int i = 0; i < n; i++) {
        std::string city, street, houseNumber, apartmentNumber;

        std::getline(input, city);
        std::getline(input, street);
        std::getline(input, houseNumber);
        std::getline(input, apartmentNumber);

        addresses.emplace_back(city, street, houseNumber, apartmentNumber);
    }

    insertion_sort(addresses);

    output << n << std::endl;
    for (const auto& address : addresses) {
        output << address.get_output_address() << std::endl;
    }

    input.close();
    output.close();

    return 0;
}
