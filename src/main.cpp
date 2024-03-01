#include <graphics.h>
#include <thread>
#include <string>
#include <mutex>
#include "Graph.h"
#include "RectAndText.h"
#include "config.h"
#include "Qsort.h"
#include "BubbleSort.h"
#include "SelectSort.h"

std::mutex mtx;

int main() {
    initgraph(GRAPH_X_SIZE, GRAPH_Y_SIZE, INIT_RENDERMANUAL); // 画幅 1280 * 720，关闭自动刷新
    setcaption("排序可视化"); // 窗口标题
    setrendermode(RENDER_MANUAL); // 手动渲染
    setbkmode(TRANSPARENT); //文本透明背景
    setbkcolor(BK_COLOR); //设置背景为白色
    ege_enable_aa(true); // 开启抗锯齿

    const int graph_x_block = 20, graph_y_block = 30;
    const int graph_x_size = (GRAPH_X_SIZE / 2) - (graph_x_block * 2), graph_y_size = (GRAPH_Y_SIZE / 2) - (graph_y_block * 2);
    QsortVisualization q1(15, (GRAPH_X_SIZE - graph_x_size) / 2, graph_y_block, graph_x_size, graph_y_size);
    BubbleSortVisualization q2(15, graph_x_block, (GRAPH_Y_SIZE / 2) + graph_y_block, graph_x_size, graph_y_size);
    SelectSortVisualization q3(15, (GRAPH_X_SIZE / 2) + graph_x_block, (GRAPH_Y_SIZE / 2) + graph_y_block, graph_x_size, graph_y_size);

    bool t1_is_run = 1, t2_is_run = 1, t3_is_run = 1;

    std::thread t1([&]() {
        q1.Launch();
        t1_is_run = 0;
    });

    std::thread t2([&]() {
        q2.Launch();
        t2_is_run = 0;
    });

    std::thread t3([&]() {
        q3.Launch();
        t3_is_run = 0;
    });

    std::thread t_main([&]() {
        while (t1_is_run || t2_is_run || t3_is_run) {
            q1.Show();
            q2.Show();
            q3.Show();
            delay_fps(30);
        }
    });

    t1.join();
    t2.join();
    t3.join();
    //t4.join();

    t_main.join();

    getch();

    //关闭图形界面
    closegraph();

	return 0;
}