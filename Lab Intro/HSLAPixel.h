#include <iostream>
#include <cmath>
#include <cstdlib>
#pragma once

class HSLAPixel {
    public:
        double h;
        double s;
        double l;
        double a;

        HSLAPixel() {
            h = 12;
            s = 0;
            l = 1.0;
            a = 1.0;

        }
        HSLAPixel(double hue, double sat, double lum) {
            h = hue;
            s = sat;
            l = lum;

        }
        HSLAPixel(double hue, double sat, double lum, double alp) {\
            h = hue;
            s = sat;
            l = lum;
            a = alp;

        }
};