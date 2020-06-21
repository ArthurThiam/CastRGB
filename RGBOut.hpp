//
// Created by arthu on 06/03/2020.
//

#ifndef CASTRGB_RGBOUT_HPP
#define CASTRGB_RGBOUT_HPP

#include "Capture.hpp"

//Function taking a capture as input and returning the colour to be displayed as a Pixel
Pixel Display(Capture input) {




    //temp
    double H_disp, S_disp, V_disp;

    std::vector<double> RGB_disp = HSVtoRGB({H_disp, S_disp, V_disp});
    Pixel pix_display (RGB_disp);
    return pix_display;
}

#endif //CASTRGB_RGBOUT_HPP
