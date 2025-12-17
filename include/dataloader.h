#pragma once

#include <vector>
#include <string>

class DataLoader {
    public:
        DataLoader();
        void load_data(const std::string& filepath);
        std::vector<std::string> get_data() const;

    private:
        std::vector<std::string> data; // Loaded data storage
}