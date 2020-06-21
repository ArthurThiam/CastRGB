//
// Created by Arthur Thiam on 05/03/2020.
//

#include "Settings.hpp"

#ifndef CASTRGB_HSVTORGB_HPP
#define CASTRGB_HSVTORGB_HPP

///Function converts HSV color space to RGB color space. returns a vector (r, g, b)
std::vector<double> HSVtoRGB(const std::vector<double>& input) {

    std::map<std::string, double> colour;
    colour["h"] = input[0];
    colour["s"] = input[1];
    colour["v"] = input[2];

    colour["v"] *= 255; //convert value percentage to value

    double hi = floor(int(colour["h"]/60)%6);
    double f =  (colour["h"] / 60) - floor(colour["h"] / 60);

    double p = colour["v"] * (1 - colour["s"]);
    double q = colour["v"] * (1 - f*colour["s"]);
    double t = colour["v"] * (1 - ((1- f)*colour["s"]));
    double v = colour["v"];

    std::vector<double> result;

    if (hi==0) {
        result = {v, t, p};
    } else if (hi == 1) {
        result = {q, v, p};
    } else if (hi == 2) {
        result = {p, v, t};
    } else if (hi == 3) {
        result = {p, q, v};
    } else if (hi == 4) {
        result = {t, p, v};
    } else if (hi == 5) {
        result = {v, p, q};
    } else {
        std::cout << "ERROR: Conversion from HSV to RGB failed." << std::endl;
    }

    std::cout << "HSV[" << colour["h"] << ", " << colour["s"] << ", " << colour["v"]/255 << "] = HSV[" << result[0] << ", " << result[1] << ", " << result[2] << "]" << std::endl;
    return result;
}

#endif //CASTRGB_HSVTORGB_HPP
