#include "Text.h"
#include <graphics.h>
#include <stdlib.h>
#include <utility>
#include <string>
#include <Windows.h>
#include "config.h"

Text::Text() noexcept : loc({0, 0}), font_size(0) {}

Text::Text(const std::string& str, float x, float y, color_t color, int font_size, const std::string& font_name) noexcept :
	loc({x, y}),
	str(str),
	color(color),
	font_size(font_size),
	font_name(font_name) {
}

Text::Text(const std::string& str, const std::pair<float, float>& loc, color_t color, int font_size, const std::string& font_name) noexcept :
	Text(str, loc.first, loc.second, color, font_size, font_name) {
}

Text::Text(const Text& text) noexcept :
	str(text.str),
	loc(text.loc),
	color(text.color),
	font_size(text.font_size),
	font_name(text.font_name) 
{}

Text::Text(Text&& text) noexcept :
	str(text.str),
	loc(text.loc),
	color(text.color),
	font_size(text.font_size),
	font_name(text.font_name) {
}

Text& Text::operator=(const Text& text) noexcept {
	str = text.str;
	loc = text.loc;
	color = text.color;
	font_size = text.font_size;
	font_name = text.font_name;

	return *this;
}

Text& Text::operator=(Text&& text) noexcept {
	str = text.str;
	loc = text.loc;
	color = text.color;
	font_size = text.font_size;
	font_name = text.font_name;

	return *this;
}

void Text::SetFontColor(color_t color) noexcept {
	this->color = color;
}

float Text::total_x() const noexcept {
	return textwidth(str.c_str()) * 1.25f;
	//return MulDiv(font_size, GetDeviceCaps(GetDC(getHWnd()), LOGPIXELSY), 72) * str.length() / 2;
}

float Text::total_y() const noexcept {
	return textheight(str.c_str()) * 1.25f;
	//return MulDiv(font_size, GetDeviceCaps(GetDC(getHWnd()), LOGPIXELSY), 72) * str.length() / 2;
}

std::pair<float, float> Text::GetLocation() const noexcept {
	return loc;
}

void Text::Show() const {
	setfont(font_size, 0, font_name.c_str());
	setcolor(color);

	ege_drawtext(str.c_str(), loc.first, loc.second);
}

void Text::Move(const float& dx, const float& dy) {
	loc.first += dx;
	loc.second += dy;
}

void Text::SetAlpha(const int alpha) {
	if (alpha > 255) {
		;
	}
	color &= 0x00FFFFFF;
	color |= alpha << 24;
}

void Text::Clr() const {
	setfillcolor(BK_COLOR);
	ege_fillrect(loc.first, loc.second, total_x(), total_y());
}