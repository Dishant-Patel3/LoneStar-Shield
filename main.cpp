#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

struct Offender {
    std::string id;
    std::string name;
    double lat;
    double lon;
};

std::string cleanString(std::string s) {
    // Remove tabs, carriage returns, and trim spaces
    s.erase(std::remove(s.begin(), s.end(), '\t'), s.end());
    s.erase(std::remove(s.begin(), s.end(), '\r'), s.end());
    s.erase(std::remove(s.begin(), s.end(), '\n'), s.end());
    while (!s.empty() && isspace(s.front())) s.erase(s.begin());
    while (!s.empty() && isspace(s.back())) s.pop_back();

    // Escape quotes for JS
    size_t pos = 0;
    while ((pos = s.find("\"", pos)) != std::string::npos) {
        s.replace(pos, 1, "\\\"");
        pos += 2;
    }

    return s;
}

int main() {
    std::unordered_map<std::string, std::string> idToName;
    std::ifstream namesFile("Name.txt");
    std::ifstream addressFile("Address.txt");
    std::ofstream outputFile("markers.js");

    if (!namesFile.is_open()) {
        std::cerr << "Failed to open Name.txt\n";
        return 1;
    }
    if (!addressFile.is_open()) {
        std::cerr << "Failed to open Address.txt\n";
        return 1;
    }
    if (!outputFile.is_open()) {
        std::cerr << "Failed to open markers.js for writing\n";
        return 1;
    }

    // --- Read Name.txt ---
    std::string line;
    while (std::getline(namesFile, line)) {
        if (line.empty()) continue;
        std::stringstream ss(line);
        std::string col1, id, letter, fullName;
        ss >> col1 >> id >> letter;
        std::getline(ss, fullName, '\t'); // read the rest until tab

        // extract only the 4th field (the "GARCIA,ROBERT CARLOS" style name)
        std::vector<std::string> fields;
        std::stringstream ss2(line);
        std::string temp;
        while (std::getline(ss2, temp, '\t')) {
            if (!temp.empty()) fields.push_back(temp);
        }

        std::string name = "No Name";
        if (fields.size() >= 4) {
            name = cleanString(fields[3]);  // only take column 4
        }

        idToName[id] = name;
    }

    // --- Read Address.txt ---
    std::vector<Offender> offenders;
    while (std::getline(addressFile, line)) {
        if (line.empty()) continue;

        std::stringstream ss(line);
        std::string col1, id;
        double lat, lon;

        ss >> col1 >> id;
        std::string rest;
        std::getline(ss, rest);

        // Try to extract last two numbers in line (lat, lon)
        size_t lastTab = rest.find_last_of('\t');
        if (lastTab == std::string::npos) continue;
        std::string lonStr = rest.substr(lastTab + 1);
        rest = rest.substr(0, lastTab);

        size_t secondLastTab = rest.find_last_of('\t');
        if (secondLastTab == std::string::npos) continue;
        std::string latStr = rest.substr(secondLastTab + 1);

        try {
            lat = std::stod(latStr);
            lon = std::stod(lonStr);
        } catch (...) {
            continue;
        }

        // keep only Texas area
        if (lat < 25 || lat > 37 || lon < -107 || lon > -93)
            continue;

        Offender o;
        o.id = id;
        o.lat = lat;
        o.lon = lon;

        auto it = idToName.find(id);
        o.name = (it != idToName.end()) ? it->second : "No Name";

        offenders.push_back(o);
    }

    // --- Write to markers.js ---
    outputFile << "const markers = [\n";
    for (const auto& o : offenders) {
        outputFile << "  { lat: " << o.lat
                   << ", lon: " << o.lon
                   << ", name: \"" << o.name
                   << "\", id: \"" << o.id << "\" },\n";
    }
    outputFile << "];\n";

    std::cout << "markers.js generated with " << offenders.size() << " markers.\n";
    return 0;
}