#ifndef LOADERPARAM_H
#define LOADERPARAM_H

#include <string>

class LoaderParams {
	int m_x;
	int m_y;
	int m_width;
	int m_height;
	int m_zoom;
	std::string m_file;
	std::string m_id;
public:
	LoaderParams(int x, int y, int width, int height, int zoom, std::string file, std::string id)
		:m_x(x), m_y(y), m_width(width), m_height(height), m_zoom(zoom), m_file(file), m_id(id) {};
	~LoaderParams() = default;
	int getx() const { return m_x; }
	int gety() const { return m_y; }
	int getwidth() const { return m_width; }
	int getheight() const { return m_height; }
	int getzoom() const { return m_zoom; }
	std::string getfile() const { return m_file; }
	std::string getid() const { return m_id; }
};

#endif // !LOADERPARAM_H