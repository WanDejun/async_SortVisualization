#include "Rect.h"
#include <graphics.h>
#include <stdlib.h>
#include <utility>
#include <string>
#include "config.h"

Rect::Rect() : loc({ 0, 0 }), size({ 0, 0 }) {}

Rect::Rect(std::pair<float, float> loc, std::pair<float, float> size, color_t filledColor, color_t outlineColor) :
	loc(loc),
	size(size),
	filledColor(filledColor),
	outlineColor(outlineColor) {
}

Rect::Rect(std::pair<float, float> loc, std::pair<float, float> size, color_t filledColor) :
	Rect(loc, size, filledColor, filledColor) {
}

Rect::Rect(float x, float y, float w, float h, color_t filledColor, color_t outlineColor) :
	Rect(std::make_pair( x, y ), std::make_pair( w, h ), filledColor, outlineColor) {
}

Rect::Rect(float x, float y, float w, float h, color_t filledColor) :
	Rect(std::make_pair( x, y ), std::make_pair( w, h ), filledColor) {
}

Rect::Rect(const Rect& rect) :
	Rect(rect.loc, rect.size, rect.filledColor, rect.outlineColor) {
}

Rect::Rect(Rect&& rect) :
	loc(loc),
	size(size),
	filledColor(filledColor),
	outlineColor(outlineColor) {
}

Rect& Rect::operator=(const Rect& rect) {
	loc = rect.loc;
	size = rect.size;
	filledColor = rect.filledColor;
	outlineColor = rect.outlineColor;

	return *this;
}

Rect& Rect::operator=(Rect&& rect) {
	loc = rect.loc;
	size = rect.size;
	filledColor = rect.filledColor;
	outlineColor = rect.outlineColor;

	return *this;
}

void Rect::SetOutLineColor(color_t color) {
	outlineColor = color;
}
void Rect::SetFilledColor(color_t color) {
	filledColor = color;
}
void Rect::SetColor(color_t color) {
	outlineColor = filledColor = color;
}

void Rect::Show() const {
	setfillcolor(filledColor);
	ege_fillrect(loc.first, loc.second, size.first, size.second);

	setcolor(outlineColor);
	ege_rectangle(loc.first, loc.second, size.first, size.second);
}

void Rect::Move(const float& dx, const float& dy) {
	loc.first += dx;
	loc.second += dy;
}

void Rect::SetAlpha(const int alpha) {
	if (alpha > 255) {
		; // “Ï≥£¥¶¿Ì
	}
	outlineColor &= 0x00FFFFFF;
	outlineColor |= alpha << 24;
	filledColor &= 0x00FFFFFF;
	filledColor |= alpha << 24;
}

void Rect::Clr() const {
	setfillcolor(BK_COLOR);
	ege_fillrect(loc.first, loc.second, size.first, size.second);
}