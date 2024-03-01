#include "SortVisualization.h"
#include <graphics.h>
#include "RectAndText.h"
#include "config.h"

SortVisualization::SortVisualization() noexcept : nums(0), graphs(), loc(), size() {}

SortVisualization::SortVisualization(const int cnt, const std::pair<float, float> loc, const std::pair<float, float> size) noexcept :
	nums(cnt), graphs(cnt), loc(loc), size(size), // ��ʼ��
	x_size(size.first / (cnt * 2 + 1)), // x_size(����x���) ��ʼ��(���ҿճ�һ����λ���)

	text_i("i", loc.first + x_size, loc.second + size.second - 20, FontColor, 20), // i, jָ�����ֳ�ʼ��
	text_j("j", loc.first + size.first - x_size, loc.second + size.second - 20, FontColor, 20),
	textTemp("temp:", loc.first, loc.second, 20, FontColor) {
	Text text;
	Rect rect;
	float y_size = (size.second - 40) / 100, x_loc, y_loc; // y��λ���, xy��ʼλ��

	text_i.Move((x_size - text_i.total_x()) / 2, 0); // ����i,jָ������
	text_j.Move(-(x_size + text_j.total_x()) / 2, 0);

	for (int i = 0; i < cnt; i++) {
		nums[i] = random(100); // �������ʼ��
		x_loc = loc.first + (2 * i + 1) * x_size; // rectxλ��
		y_loc = loc.second + size.second - 20 - y_size * nums[i]; // rectyλ��(�ױ߶���)

		rect = Rect(x_loc, y_loc, x_size, y_size * nums[i], RectColor); // rect��ʼ��

		text = Text(std::to_string(nums[i]), x_loc, y_loc - 25, FontColor, 20); // text��ʼ��
		text.Move((x_size - text.total_x()) / 2, 0); // ���ж���

		graphs[i] = RectAndText(rect, text); // RectAndText��ʼ��
	}
}

SortVisualization::SortVisualization(const int cnt, const float x, const float y, const float x_size, const float y_size) noexcept :
	SortVisualization(cnt, std::make_pair(x, y), std::make_pair(x_size, y_size)) {
}

SortVisualization::SortVisualization(const std::initializer_list<int> list, const std::pair<float, float> loc, const std::pair<float, float> size) noexcept :
	nums(list.size()), graphs(list.size()), loc(loc), size(size),

	x_size(size.first / (list.size() * 2 + 1)), // x_size(����x���) ��ʼ��(���ҿճ�һ����λ���)

	text_i("i", loc.first + x_size, loc.second + size.second - 20, FontColor, 20), // i, jָ�����ֳ�ʼ��
	text_j("j", loc.first + size.first - x_size, loc.second + size.second - 20, FontColor, 20),
	textTemp("temp:", loc.first, loc.second, 20, FontColor) {  // ע�ͼ� SortVisualization(int cnt, std::pair<float, float> loc, std::pair<float, float> size)
	Text text;
	Rect rect;
	float y_size = (size.second - 40) / 100, x_loc, y_loc;

	text_i.Move((x_size - text_i.total_x()) / 2, 0); // i,jָ�����
	text_j.Move(-(x_size + text_j.total_x()) / 2, 0);

	int i = 0;
	for (auto it = list.begin(); it != list.end(); it++, i++) {
		nums[i] = *it;
		x_loc = loc.first + (2 * i + 1) * x_size;
		y_loc = loc.second + size.second - 20 - y_size * nums[i];

		rect = Rect(x_loc, y_loc, x_size, y_size * nums[i], RectColor);

		text = Text(std::to_string(nums[i]), x_loc, y_loc - 25, FontColor, 20);
		text.Move((x_size - text.total_x()) / 2, 0);

		graphs[i] = RectAndText(rect, text);
	}
}

SortVisualization::SortVisualization(const std::initializer_list<int> list, const float x, const float y, const float x_size, const float y_size) noexcept :
	SortVisualization(list, std::make_pair(x, y), std::make_pair(x_size, y_size)) {
}

void SortVisualization::text_i_set(const int idx) noexcept {
	float x_loc = text_i.GetLocation().first, y_loc = text_i.GetLocation().second;
	text_i.Move(loc.first + (idx * 2 + 1) * x_size + (x_size - text_i.total_x()) / 2 - x_loc, loc.second + size.second - 20 - y_loc);
}

void SortVisualization::text_j_set(const int idx) noexcept {
	float x_loc = text_j.GetLocation().first, y_loc = text_j.GetLocation().second;
	text_j.Move(loc.first + (idx * 2 + 1) * x_size + (x_size - text_i.total_x()) / 2 - x_loc, loc.second + size.second - 20 - y_loc);
}

void SortVisualization::text_i_Move(const float det_x, const float det_y) noexcept {
	int Frames = 20 / SPEED;
	float dx = det_x / Frames, dy = det_y / Frames;

	for (int i = 0; i < Frames; i++) {
		text_i.Move(dx, dy);
		api_sleep(40);
	}
}

void SortVisualization::text_j_Move(const float det_x, const float det_y) noexcept {
	int Frames = 20 / SPEED;
	float dx = det_x / Frames, dy = det_y / Frames;

	for (int i = 0; i < Frames; i++) {
		text_j.Move(dx, dy);
		api_sleep(40);
	}
}

void SortVisualization::SetTempValue(const int val) noexcept {
	textTemp = Text("temp: " + std::to_string(val), loc.first, loc.second, 20, FontColor);
}

void SortVisualization::Clr() const noexcept{ //����
	setfillcolor(BK_COLOR);
	ege_fillrect(loc.first, loc.second, size.first, size.second);
}

void SortVisualization::swapGraphs(const int idx1, const int idx2) noexcept { // ����ͼ��
	int Frames = 30 / SPEED;
	float dx = (idx2 - idx1) * 2 * x_size / Frames, dy = 0;

	graphs[idx1].SetAlpha(127); // ����͸����
	graphs[idx2].SetAlpha(127);

	for (int i = 0; i < Frames; i++) { // ��֡�ƶ�
		graphs[idx1].Move(dx, dy);
		graphs[idx2].Move(-dx, dy);
		api_sleep(40);
	}

	RectAndText temp(graphs[idx1]); // swap
	graphs[idx1] = graphs[idx2];
	graphs[idx2] = temp;

	graphs[idx1].SetAlpha(255); // ����͸����
	graphs[idx2].SetAlpha(255);

	api_sleep(200); // �ȴ�
}

void SortVisualization::swapNums(const int idx1, const int idx2) noexcept { // ��������
	std::swap(nums[idx1], nums[idx2]);
}

void SortVisualization::Sort(const int l, const int r) noexcept {}

void SortVisualization::Launch() noexcept { // �������
	Sort(0, static_cast<int>(nums.size() - 1));
	is_run_flag = 0;
}

void SortVisualization::Show(bool ClrFlag) const noexcept { // �������
	if (ClrFlag) Clr();
	for (int i = 0; i < nums.size(); i++) {
		graphs[i].Show();
	}
	text_i.Show();
	text_j.Show();
}

int SortVisualization::GetSize() const noexcept {
	return nums.size();
}
