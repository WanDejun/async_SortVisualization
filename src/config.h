#pragma once
#include <graphics.h>
#include <mutex>

enum color {
	RectColor = EGERGB(245, 74, 155),
	RectSelectColor = EGERGB(20, 200, 350),
	RectCorrectColor = EGERGB(250, 210, 43),
	FontColor = EGERGB(0, 0, 0),
};

const color_t BK_COLOR = WHITE;
extern std::mutex mtx;
const float SPEED = 1;
const int GRAPH_X_SIZE = 1280, GRAPH_Y_SIZE = 720;