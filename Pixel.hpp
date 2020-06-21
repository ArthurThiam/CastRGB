//
// Created by Arthur Thiam on 05/03/2020.
//

#include "HSVtoRGB.hpp"

#ifndef CASTRGB_PIXEL_HPP
#define CASTRGB_PIXEL_HPP

class Pixel {
public:
    //Default constructor
    Pixel(): R(255), G(255), B(255), H(0), S(0), V(1) {
    }

    //Construct pixel using three integers
    Pixel(std::vector<double>& input) : R(input[0]), G(input[1]), B(input[2]) {

        int maxc = *max_element(input.begin(), input.end());
        int minc = *min_element(input.begin(), input.end());
        int deltac = (maxc - minc);

        //Determine Hue
        if (deltac == 0) {
            H = 0;

        } else if (maxc == R) {
            H = int((G - B) * 60 / deltac) % 360;

        } else if (maxc == G) {
            H = ((B - R) / deltac + 2) * 60;

        } else if (maxc == B) {
            H = ((R - G) / (deltac) + 4) * 60;

        } else {
            H = 0;
            std::cout << "ERROR: Conversion from RGB to HSV failed." << std::endl;
        }

        //hue quadrant correction
        if (H < 0) {
            H += 360;
        } else if (H > 360) {
            H -= 360;
        }

        //Determine Value
        V = double(maxc) / 255.0;

        //Determine Saturation
        if (maxc == 0) {
            S = 0.0;
        } else {
            S = double(deltac) / double(maxc);
        }

        RGB = {R, G, B};
        HSV = {H, S, V};

    }

    //Destructor
    ~Pixel() {
        R = 0;
        G = 0;
        B = 0;
        H = 0;
        S = 0;
        V = 0;

    }


    //attributes
    double R;
    double G;
    double B;
    double H;
    double S;
    double V;
    std::vector<double> RGB;
    std::vector<double> HSV;

};

void print_pixel(Pixel input) {
    std::cout << "RGB: [" << input.R << ", " << input.G << ", " << input.B << "], HSV: [" << input.H << ", " << input.S << ", " << input.V << "]\n";
}

#endif //CASTRGB_PIXEL_HPP
