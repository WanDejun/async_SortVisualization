#pragma once
#include "RectAndText.h"
#include <vector>
#include <graphics.h>

class SortVisualization {
protected:
	std::vector<int> nums; //值数组
	std::vector<RectAndText> graphs; //图形数组
	std::pair<float, float> loc;
	std::pair<float, float> size;
	float x_size;
	Text text_i, text_j, textTemp;
	bool is_run_flag = 1;

	void text_i_set(const int idx) noexcept;
	void text_j_set(const int idx) noexcept;
	void text_i_Move(const float det_x, const float det_y) noexcept;
	void text_j_Move(const float det_x, const float det_y) noexcept;
	void SetTempValue(const int val) noexcept;
	void swapGraphs(const int idx1, const int idx2) noexcept;
	void swapNums(const int idx1, const int idx2) noexcept;
	void Clr() const noexcept;
	virtual void Sort(const int l, const int r) noexcept;

public:
	SortVisualization() noexcept;
	SortVisualization(const int cnt, const std::pair<float, float> loc, const std::pair<float, float> size) noexcept; // 生成nums个随机数
	SortVisualization(const int cnt, const float x, const float y, const float x_size, const float y_size) noexcept; // 生成nums个随机数
	SortVisualization(const std::initializer_list<int> list, const std::pair<float, float> loc, const std::pair<float, float> size) noexcept;
	SortVisualization(const std::initializer_list<int> list, const float x, const float y, const float x_size, const float y_size) noexcept;
	int GetSize() const noexcept;
	void Launch() noexcept;
	void Show(bool ClrFlag = 1) const noexcept;
};