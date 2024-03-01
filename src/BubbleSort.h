#pragma once
#include "RectAndText.h"
#include <vector>
#include <graphics.h>
#include "SortVisualization.h"

class BubbleSortVisualization : public SortVisualization {
private:
	virtual void Sort(const int l, const int r) noexcept override;
public:
	BubbleSortVisualization() noexcept;
	BubbleSortVisualization(const int cnt, const std::pair<float, float> loc, const std::pair<float, float> size) noexcept; // ����nums�������
	BubbleSortVisualization(const int cnt, const float x, const float y, const float x_size, const float y_size) noexcept; // ����nums�������
	BubbleSortVisualization(const std::initializer_list<int> list, const std::pair<float, float> loc, const std::pair<float, float> size) noexcept;
	BubbleSortVisualization(const std::initializer_list<int> list, const float x, const float y, const float x_size, const float y_size) noexcept;
};