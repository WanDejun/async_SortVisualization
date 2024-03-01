#pragma once
#include <graphics.h>
#include <utility>
#include <string>
#include "Graph.h"

class Text : public Graph {
private:
	std::string str;
	std::pair<float, float> loc;
	color_t color;
	int font_size;
	std::string font_name;
public:
	Text() noexcept;
	Text(const std::string& str, float x, float y, color_t color, int font_size, const std::string& font_name = "Consolas") noexcept;
	Text(const std::string& str, const std::pair<float, float>& loc, color_t color, int font_size, const std::string& font_name = "Consolas") noexcept;
	Text(const Text& text) noexcept;
	Text(Text&& text) noexcept;
	Text& operator=(const Text& text) noexcept;
	Text& operator=(Text&& text) noexcept;
	void SetFontColor(color_t color) noexcept;
	float total_x() const noexcept;
	float total_y() const noexcept;
	std::pair<float, float> GetLocation() const noexcept;
	virtual void Move(const float& dx, const float& dy) override;
	//virtual void rotate(const float& rad);
	virtual void Show() const override;
	virtual void SetAlpha(const int alpha) override;
	virtual void Clr() const override;
};

