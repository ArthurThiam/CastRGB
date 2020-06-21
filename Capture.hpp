//
// Created by Arthur Thiam on 06/03/2020.
//

#include "Pixel.hpp"

#ifndef CASTRGB_CAPTURE_HPP
#define CASTRGB_CAPTURE_HPP

//Pixel capture_pixel(int x, int y, HDC dc) {
//    COLORREF colour = GetPixel(dc, x, y);
//
//    auto R = double(GetRValue(colour));
//    auto G = double(GetGValue(colour));
//    auto B = double(GetBValue(colour));
//
//    std::vector<double> result = {R, G, B};
//    Pixel pixel_rgb(result);
//    return pixel_rgb;
//}

class Capture {
public:

    //Generate a capture based on capture step size and screen resolution
    Capture(int nx, int ny, int res_x, int res_y): nx(nx), ny(ny) {
        int dx = res_x/nx;
        int dy = res_y/ny;

        //iterate over all requested pixels
        HDC dc = GetDC(nullptr); //take screen-shot
        int x = 0, y = 0;
        it = 0;
        for (y; y <= res_y; y+=dy) {
            for (x; x <= res_x; x+=dx) {

                //Get pixel at requested coordinates of screen-shot
                COLORREF colour = GetPixel(dc, x, y);

                //Extract R, G, B value and store in Pixel
                std::vector<double> result = {double(GetRValue(colour)), double(GetGValue(colour)), double(GetBValue(colour))};
                Pixel pixel_rgb(result);

                //Store Pixel in screen-shot color-map
                colour_vector.push_back(pixel_rgb);
                it ++;
            }
            x -= x;
        }
        ReleaseDC(nullptr, dc); //remove screen-shot

    }

    //attributes
    int nx;
    int ny;
    int it;
    std::vector<Pixel> colour_vector; //map containing RGB and HSV values of screenshot
};

void print_capture(Capture input) {
    int it = 0;
    while (it!=input.colour_vector.size()) {
        //std::cout << "Pixel " << it->first[0] << "x" << it->first[1] << " ";
        print_pixel(input.colour_vector[it]);
        it ++;
    }
}

#endif //CASTRGB_CAPTURE_HPP
