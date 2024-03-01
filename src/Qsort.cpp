#include "Qsort.h"
#include <graphics.h>
#include "RectAndText.h"
#include "config.h"

QsortVisualization::QsortVisualization() noexcept : SortVisualization::SortVisualization() {}

QsortVisualization::QsortVisualization(const int cnt, const std::pair<float, float> loc, const std::pair<float, float> size) noexcept :
	SortVisualization::SortVisualization(cnt, loc, size) {}

QsortVisualization::QsortVisualization(const int cnt, const float x, const float y, const float x_size, const float y_size) noexcept :
	QsortVisualization(cnt, std::make_pair(x, y), std::make_pair(x_size, y_size)) {}

QsortVisualization::QsortVisualization(const std::initializer_list<int> list, const std::pair<float, float> loc, const std::pair<float, float> size) noexcept :
	SortVisualization::SortVisualization(list, loc, size) {}

QsortVisualization::QsortVisualization(const std::initializer_list<int> list, const float x, const float y, const float x_size, const float y_size) noexcept :
	QsortVisualization(list, std::make_pair(x, y), std::make_pair(x_size, y_size)) {}

void QsortVisualization::Sort(const int l, const int r) noexcept {
	if (l >= r) {
		if (l == r) {
			text_i_set(l);
			text_j_set(r);
			graphs[l].rect.SetColor(RectCorrectColor);
			api_sleep(200);
		}
		return;
	}

	text_i_set(l);
	text_j_set(r);
	int i = l, j = r, t = nums[j];

	graphs[l].rect.SetColor(RectSelectColor);
	api_sleep(200);

	while (i < j) {
		while (i < j && nums[i] <= t) {
			graphs[i].rect.SetColor(RectColor);
			i++;
			text_i_Move(2 * x_size, 0);
			graphs[i].rect.SetColor(RectSelectColor);
		}

		if (i != j) {
			api_sleep(200);
			swapGraphs(i, j);
			api_sleep(200);

			nums[j] = nums[i];
		}

		while (i < j && nums[j] >= t) {
			graphs[j].rect.SetColor(RectColor);
			j--;
			text_j_Move(-2 * x_size, 0);
			graphs[j].rect.SetColor(RectSelectColor);
		}
		if (i != j) {
			api_sleep(200);
			swapGraphs(i, j);
			api_sleep(200);

			nums[i] = nums[j];
		}
	}

	graphs[i].rect.SetColor(RectCorrectColor);
	api_sleep(200);

	nums[i] = t;
	Sort(l, i - 1);
	Sort(i + 1, r);
}
