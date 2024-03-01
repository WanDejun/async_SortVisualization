#include <graphics.h>
#include "SelectSort.h"
#include "RectAndText.h"
#include "config.h"

SelectSortVisualization::SelectSortVisualization() noexcept : SortVisualization::SortVisualization() {}

SelectSortVisualization::SelectSortVisualization(const int cnt, const std::pair<float, float> loc, const std::pair<float, float> size) noexcept :
	SortVisualization::SortVisualization(cnt, loc, size) {}

SelectSortVisualization::SelectSortVisualization(const int cnt, const float x, const float y, const float x_size, const float y_size) noexcept :
	SelectSortVisualization(cnt, std::make_pair(x, y), std::make_pair(x_size, y_size)) {
}

SelectSortVisualization::SelectSortVisualization(const std::initializer_list<int> list, const std::pair<float, float> loc, const std::pair<float, float> size) noexcept :
	SortVisualization::SortVisualization(list, loc, size) {}

SelectSortVisualization::SelectSortVisualization(const std::initializer_list<int> list, const float x, const float y, const float x_size, const float y_size) noexcept :
	SelectSortVisualization(list, std::make_pair(x, y), std::make_pair(x_size, y_size)) {
}

void SelectSortVisualization::Sort(const int l, const int r) noexcept {
	text_i_set(l);
	text_j_set(l + 1);

	api_sleep(200);

	bool finish_flag;

	for (int i = l; i < r; i++) {
		volatile int min = i;
		graphs[min].rect.SetColor(RectSelectColor);
		api_sleep(200);

		text_j_set(i + 1);

		for (int j = i + 1; j <= r; j++) {
			if (nums[min] > nums[j]) {
				graphs[min].rect.SetColor(RectColor);
				min = j;
				graphs[min].rect.SetColor(RectSelectColor);
				api_sleep(200);
			}
			if (j != r) text_j_Move(2 * x_size, 0);
		}

		if (min != i) {
			swapGraphs(i, min);
			swapNums(i, min);
		}
		graphs[min].rect.SetColor(RectColor);
		graphs[i].rect.SetColor(RectCorrectColor);
		api_sleep(200);

		text_i_Move(2 * x_size, 0);
	}

	graphs[r].rect.SetColor(RectCorrectColor);
}
