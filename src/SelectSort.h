#pragma once
#include "RectAndText.h"
#include <vector>
#include <graphics.h>
#include "SortVisualization.h"

class SelectSortVisualization : public SortVisualization {
private:
	virtual void Sort(const int l, const int r) noexcept override;
public:
	SelectSortVisualization() noexcept;
	SelectSortVisualization(const int cnt, const std::pair<float, float> loc, const std::pair<float, float> size) noexcept; // 生成nums个随机数
	SelectSortVisualization(const int cnt, const float x, const float y, const float x_size, const float y_size) noexcept; // 生成nums个随机数
	SelectSortVisualization(const std::initializer_list<int> list, const std::pair<float, float> loc, const std::pair<float, float> size) noexcept;
	SelectSortVisualization(const std::initializer_list<int> list, const float x, const float y, const float x_size, const float y_size) noexcept;
};