//
// Created by Arthur Thiam on 05/03/2020.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <cmath>
#include <windows.h>
#include <map>
#include <initializer_list>
#include <memory>
#include <utility>
#include <chrono>

#ifndef CASTRGB_SETTINGS_HPP
#define CASTRGB_SETTINGS_HPP

using namespace std;

class Settings {
public:

    Settings(const std::string& configuration, const std::string& path) {
        const char *config = configuration.c_str();
        const char *Path = path.c_str();

        stability = GetPrivateProfileInt(config, "stability", 0, Path);

        normalstep = GetPrivateProfileInt(config, "normalstep", 0, Path);
        normalstep /= 1000.0;

        flashstep = GetPrivateProfileInt(config, "flashstep", 0, Path);

        flashvalue = GetPrivateProfileInt(config, "flashvalue", 0, Path);
        flashvalue /= 10.0;

        brightness = GetPrivateProfileInt(config, "brightness", 0, Path);

        saturation = GetPrivateProfileInt(config, "saturation", 0, Path);

        nx = GetPrivateProfileInt(config, "nx", 0, Path);
        ny = GetPrivateProfileInt(config, "ny", 0, Path);

        res_x = GetPrivateProfileInt("General", "x", 0, Path);
        res_y = GetPrivateProfileInt("General", "y", 0, Path);

        settings = {stability, normalstep, flashstep, flashvalue, brightness, saturation};
    }

    //attributes
    double stability, normalstep, flashstep, flashvalue, brightness, saturation;
    int nx, ny, res_x, res_y;
    std::vector<double> settings;
    std::string section;
};

void print_settings(const Settings& input) {
    std::cout << "\n";
    std::cout << input.section << " settings: \n";
    std::cout << "      Resolution: " << input.res_x << "x" << input.res_y << std::endl;
    std::cout << "      # parsed pixels: " << input.nx << "x" << input.ny << std::endl;
    std::cout << "      Stability: " << input.stability << std::endl;
    std::cout << "      Default Step: " << input.normalstep << std::endl;
    std::cout << "      Flash Step: " << input.flashstep << std::endl;
    std::cout << "      Flash Value: " << input.flashvalue << std::endl;
    std::cout << "      Brightness: " << input.brightness << std::endl;
    std::cout << "      Saturation: " << input.saturation << std::endl;
    std::cout << "\n";
}

#endif //CASTRGB_SETTINGS_HPP
