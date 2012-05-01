#include <FL/Fl_Widget.h>
#include <vector>
using namespace std;

class Drawing : public Fl_Widget
{
	vector<pair<int,int>> points;
public:
	Drawing(int x, int y, int w, int h);
	void draw();
	int handle(int event);
};
