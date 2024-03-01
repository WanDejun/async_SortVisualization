#include <graphics.h>
#include "BubbleSort.h"
#include "RectAndText.h"
#include "config.h"

BubbleSortVisualization::BubbleSortVisualization() noexcept : SortVisualization::SortVisualization() {}

BubbleSortVisualization::BubbleSortVisualization(const int cnt, const std::pair<float, float> loc, const std::pair<float, float> size) noexcept :
	SortVisualization::SortVisualization(cnt, loc, size) {}

BubbleSortVisualization::BubbleSortVisualization(const int cnt, const float x, const float y, const float x_size, const float y_size) noexcept :
	BubbleSortVisualization(cnt, std::make_pair(x, y), std::make_pair(x_size, y_size)) {
}

BubbleSortVisualization::BubbleSortVisualization(const std::initializer_list<int> list, const std::pair<float, float> loc, const std::pair<float, float> size) noexcept :
	SortVisualization::SortVisualization(list, loc, size) {}

BubbleSortVisualization::BubbleSortVisualization(const std::initializer_list<int> list, const float x, const float y, const float x_size, const float y_size) noexcept :
	BubbleSortVisualization(list, std::make_pair(x, y), std::make_pair(x_size, y_size)) {
}

void BubbleSortVisualization::Sort(const int l, const int r) noexcept {
	text_i_set(l);
	text_j_set(l + 1);

	api_sleep(200);
	
	bool finish_flag;

	for (int i = 0; i < r; i++) {
		graphs[i].rect.SetColor(RectSelectColor);
		finish_flag = 1;

		text_j_set(i + 1);

		for (int j = i + 1; j <= r; j++) {
			if (nums[j] < nums[i]) {
				graphs[i].rect.SetColor(RectColor);
				graphs[j].rect.SetColor(RectSelectColor);
				finish_flag = 0;
				api_sleep(200);
				swapGraphs(i, j);
				swapNums(i, j);
				api_sleep(200);
			}

			if (j != r) text_j_Move(2 * x_size, 0);
		}

		graphs[i].rect.SetColor(RectCorrectColor);
		if (finish_flag) {
			for (int j = 0; j <= r; j++) {
				graphs[j].rect.SetColor(RectCorrectColor);
			}
		}
		text_i_Move(2 * x_size, 0);
	}

	graphs[r].rect.SetColor(RectCorrectColor);
	api_sleep(200);
}
