#ifndef SVG_H_INCLUDED
#define SVG_H_INCLUDED
#include <vector>
#include <iostream>
using namespace std;

void svg_begin(double width, double height);

void svg_end();

void svg_text(double left, double baseline, string text);

void svg_rect(double x, double y, double width, double height,string stroke, string fill);


double scaling(const vector<size_t>& bins, double block, double IMAGE_WIDTH  );

void show_histogram_svg(const vector<size_t>& bins);

size_t text_reflection_check (size_t IMAGE_WIDTH , size_t TEXT_WIDTH , size_t TEXT_LEFT);


#endif // SVG_H_INCLUDED
