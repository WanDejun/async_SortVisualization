#include "RectAndText.h"

RectAndText::RectAndText() : text(), rect() {}

RectAndText::RectAndText(const Rect& rect, const Text& text) :
	text(text), rect(rect) {
}

RectAndText::RectAndText(const RectAndText& RectAndText) :
	text(RectAndText.text), rect(RectAndText.rect) {
}

RectAndText::RectAndText(RectAndText&& RectAndText) :
	text(RectAndText.text), rect(RectAndText.rect) {
}

RectAndText& RectAndText::operator=(const RectAndText& RectAndText) {
	text = RectAndText.text;
	rect = RectAndText.rect;

	return *this;
}

RectAndText& RectAndText::operator=(RectAndText&& RectAndText) {
	text = RectAndText.text;
	rect = RectAndText.rect;

	return *this;
}

void RectAndText::Move(const float& dx, const float& dy) {
	text.Move(dx, dy);
	rect.Move(dx, dy);
}

void RectAndText::Show() const {
	text.Show();
	rect.Show();
}

void RectAndText::SetAlpha(const int alpha) {
	text.SetAlpha(alpha);
	rect.SetAlpha(alpha);
}

void RectAndText::Clr() const {
	text.Clr();
	rect.Clr();
}
