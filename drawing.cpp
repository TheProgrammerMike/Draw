
#include "drawing.h"
#include <FL/fl_draw.h>
#include <FL/Fl.h>
#include <iostream>
using namespace std;

Drawing::Drawing(int x, int y, int w, int h)
: Fl_Widget(x, y, w, h)
{
	// initialize here
}

void Drawing::draw()
{
	// Black background -- x(),y() etc give coordinates
	// of this widget.
	fl_color(FL_BLACK);
	fl_rectf(x(), y(), w(), h());
	cout << "Drawing " << points.size() << " points\n";
	fl_color(FL_GREEN);
	for(int i=1; i < points.size(); i++)
	{
		fl_line(points[i-1].first, points[i-1].second,
			points[i].first, points[i].second);
//		fl_point(points[i].first, points[i].second);
	}
}

// Return 1 if you are handling the event,
// Return 0 if you are ignoring it.
int Drawing::handle(int event)
{
	if(FL_ENTER == event)
	{
		cout << "entering!" << endl;
		return 1; // I care about mouse events!
	}
	if(FL_MOVE == event) // as mouse moves
	{
		return 0;
	}
	if(FL_PUSH == event) // clicked button
	{
		if(Fl::event_button3())
		{
			points.clear();
			damage(FL_DAMAGE_ALL);
		}
		cout << "CLICK" << endl;
		return 1;
	}
	if(FL_DRAG == event)
	{
//		cout << "drag " << Fl::event_x() << ","
//			<< Fl::event_y() << "\n";
		points.push_back
			(pair<int,int>(Fl::event_x(),
						   Fl::event_y()));
		damage(FL_DAMAGE_ALL);
	}
	return 0;
}
