#pragma once
#include <graphics.h>
#include <utility>
#include <string>
#include "Graph.h"

class Rect : public Graph {
private:
	std::pair<float, float> loc, size;
	color_t outlineColor, filledColor;
public:
	Rect();
	Rect(std::pair<float, float> loc, std::pair<float, float> size, color_t filledColor, color_t outlineColor);
	Rect(std::pair<float, float> loc, std::pair<float, float> size, color_t filledColor);
	Rect(float x, float y, float w, float h, color_t filledColor, color_t outlineColor);
	Rect(float x, float y, float w, float h, color_t filledColor);
	Rect(const Rect& Rect);
	Rect(Rect&& Rect);
	Rect& operator=(const Rect& rect);
	Rect& operator=(Rect&& rect);
	void SetOutLineColor(color_t color);
	void SetFilledColor(color_t color);
	void SetColor(color_t color);
	virtual void Move(const float& dx, const float& dy) override;
	//virtual void rotate(const float& rad);
	virtual void Show() const override;
	virtual void SetAlpha(const int alpha) override;
	virtual void Clr() const override;
};

