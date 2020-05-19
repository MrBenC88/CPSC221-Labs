#include <cstdlib>
#include <cmath>
#include <iostream>
#include "cs221util/PNG.h"
#include "cs221util/HSLAPixel.h"

#include <unistd.h>

using namespace cs221util;
using namespace std;

// sets up the output image
PNG* setupOutput(unsigned w, unsigned h) {
    PNG* image = new PNG(w, h);
    return image;
}

// Returns my favorite color
HSLAPixel* myFavoriteColor(double saturation) {
    HSLAPixel* pixel = new  HSLAPixel(170, saturation, 0.5);
    return pixel;
}

// Returns a score determining if the pixel is an edge
// requires 1 <= x < width - 1; 1 <= y < height - 1
double edgeScore(PNG* im, unsigned x, unsigned y) {
    double score = 0;
       
    // calculate score based on the luminance of the curret pixel
    // and the 8 neighboring pixels around it
    for (int i = -1; i < 2; i++){
        for (int j = -1; j < 2; j++){
            if (i == 0 && j == 0) {
                score += 8 * (im->getPixel(x,y)->l);
            } else {
                score -= im->getPixel(x+i, y+j)->l;
            }
        }
    }

    return score;
}


void sketchify(std::string inputFile, std::string outputFile) {
    // Load in.png
    PNG* original = new PNG() ; // cannot be null

    cout << "line " << __LINE__ << "REACHED LINE:  "  << endl;
    original->readFromFile(inputFile);
    unsigned width = original->width();
    cout << "line " << __LINE__ << "REACHED LINE:  " <<  original->readFromFile(inputFile) << endl;
    //sleep(199999999);
    unsigned height = original->height();
    cout << "line " << __LINE__ << "REACHED LINE:  "  << endl;

    // Create out.png
    PNG* output = setupOutput(width, height);

    // Load our favorite color to color the outline
    HSLAPixel* myPixel = myFavoriteColor(0.5);

    // Go over the whole image, and if a pixel is likely to be an edge,
    // color it my favorite color in the output
    for (unsigned y = 1; y < height-1; y++) { //we have to make sure we don't go out of range so we do height -1
        for (unsigned x = 1; x < width-1; x++) { // same with the width -1 here

            // calculate how "edge-like" a pixel is
            double score = edgeScore(original, x, y);

            HSLAPixel* currOutPixel = (*output).getPixel(x, y);
            // If the pixel is an edge pixel,
            // color the output pixel with my favorite color
            if (score > 0.3) {
                // we have to actually grab field from actual object and
                // use pointer to change the actual field
                currOutPixel->h = myPixel->h;
                currOutPixel->s = myPixel->s;
                currOutPixel->l = myPixel->l;
                currOutPixel->a = myPixel->a;
            }
        }
    }




    // Save the output file
    output->writeToFile(outputFile);

    // Clean up memory
    delete myPixel;
    delete output;
    delete original;
}
