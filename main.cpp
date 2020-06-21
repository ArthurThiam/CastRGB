#include "RGBOut.hpp"


int main() {

    /// 1. IMPORT SETTINS
    Settings config("Default", "C:/Users/arthu/OneDrive/02_Projects/getrgb/Cast RGB/CastRGB 1.1/Settings.ini");
    //print_settings(config);

    /// 2. CAPTURE PIXELS
    auto start = std::chrono::high_resolution_clock::now();

    Capture screen_shot(config.nx, config.ny, config.res_x, config.res_y);
    print_capture(screen_shot);

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop-start);
    std::cout << "Stored " << screen_shot.it << " Pixels in " << duration.count() << " [ms]" << std::endl;

    //print_capture(screen_shot);

    /// 3. DETERMINE OUTPUT

    return 0;
}
