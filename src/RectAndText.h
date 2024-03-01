#pragma once
#include <graphics.h>
#include "Graph.h"
#include "Text.h"
#include "Rect.h"

class RectAndText : public Graph {
public:
	Text text;
	Rect rect;
	RectAndText();
	RectAndText(const Rect& rect, const Text& text);
	RectAndText(const RectAndText& RectAndText);
	RectAndText(RectAndText&& RectAndText);
	RectAndText& operator=(const RectAndText& RectAndText);
	RectAndText& operator=(RectAndText&& RectAndText);
	virtual void Move(const float& dx, const float& dy) override;
	//virtual void rotate(const float& rad);
	virtual void Show() const override;
	virtual void SetAlpha(const int alpha) override;
	virtual void Clr() const override;
};

