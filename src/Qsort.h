#pragma once
#include "RectAndText.h"
#include <vector>
#include <graphics.h>
#include "SortVisualization.h"

class QsortVisualization : public SortVisualization {
private:
	virtual void Sort(const int l, const int r) noexcept override;
public:
	QsortVisualization() noexcept;
	QsortVisualization(const int cnt, const std::pair<float, float> loc, const std::pair<float, float> size) noexcept; // 生成nums个随机数
	QsortVisualization(const int cnt, const float x, const float y, const float x_size, const float y_size) noexcept; // 生成nums个随机数
	QsortVisualization(const std::initializer_list<int> list, const std::pair<float, float> loc, const std::pair<float, float> size) noexcept;
	QsortVisualization(const std::initializer_list<int> list, const float x, const float y, const float x_size, const float y_size) noexcept;
};