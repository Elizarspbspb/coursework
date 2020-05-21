#include "Element.h"
#include <iostream>
#include <stdlib.h>                     // Provides exit
using namespace std;

Element::Element()
{
	size = 40;
	color = 1;
}

Element::~Element()
{
}

Element::Element(int pn)
{
}

int Element::get_size()
{
	return size;
}

int Element::get_color()
{
	return color;
}

void Element::set_size(int k)
{
	size = k;
}

void Element::set_color(int k)
{
	color = k;
}
