#include <FL/Fl.h>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/filename.H>

#include "drawing.h"

int main(int argc, char **argv)
{
	const int xdim = 600;
	const int ydim = 480;
	Fl_Window* win = new Fl_Window(xdim, ydim);
	Drawing* drw = new Drawing(0, 0, xdim, ydim);
	win->end();
	win->show(argc, argv);
	return Fl::run();
}
