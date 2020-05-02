#include <easyx.h>
#include <graphics.h>
#include <conio.h>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int g[4][4];

double get_dis(int x1, int y1, int x2, int y2)
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main()
{
	srand((unsigned int)time(NULL));//生成随机种子
	initgraph(800, 900);//初始化绘图
	setbkcolor(WHITE);//背景色
	setbkmode(TRANSPARENT);//填充、字体模式为透明
	settextstyle(50, 0, _T("Consolas"));//设定字号、字体
	outtextxy(200, 200, _T("Click to start~"));
	outtextxy(250, 700, _T("Coded by Syhien"));
	int score = 0;
	while (1)
	{
		if (MouseHit())
		{
			auto m = GetMouseMsg();
			if (!m.mkLButton)
				continue;
			int jin = 0;
			double jindis = 1000.0;
			for (int i = 0; i < 4; i++)
				if (get_dis(m.x, m.y, 190 * i + 75, 875) < jindis)
					jin = i, jindis = get_dis(m.x, m.y, 190 * i + 75, 875);
			switch (jin)
			{
			case 0://up
				for (int i = 0; i < 4; i++)
				{
					for (int j = 3; j > 0; j--)
						if (g[i][j] and g[i][j - 1] == g[i][j])
						{
							g[i][j - 1] *= 2, g[i][j] = 0;
							score++;
							break;
						}
					for (int k = 0; k < 3; k++)
						for (int j = 3; j > 0; j--)
							if (!g[i][j - 1])
								g[i][j - 1] = g[i][j], g[i][j] = 0;
				}
				break;
			case 1://down
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 3; j++)
						if (g[i][j] and g[i][j + 1] == g[i][j])
						{
							g[i][j + 1] *= 2, g[i][j] = 0;
							score++;
							break;
						}
					for (int k = 0; k < 3; k++)
						for (int j = 0; j < 3; j++)
							if (!g[i][j + 1])
								g[i][j + 1] = g[i][j], g[i][j] = 0;
				}
				break;
			case 2://left
				for (int j = 0; j < 4; j++)
				{
					for (int i = 3; i > 0; i--)
						if (g[i][j] and g[i - 1][j] == g[i][j])
						{
							g[i - 1][j] *= 2, g[i][j] = 0;
							score++;
							break;
						}
					for (int k = 0; k < 3; k++)
						for (int i = 3; i > 0; i--)
							if (!g[i - 1][j])
								g[i - 1][j] = g[i][j], g[i][j] = 0;
				}
				break;
			case 3://right
				for (int j = 0; j < 4; j++)
				{
					for (int i = 0; i < 3; i++)
						if (g[i][j] and g[i + 1][j] == g[i][j])
						{
							g[i + 1][j] *= 2, g[i][j] = 0;
							score++;
							break;
						}
					for (int k = 0; k < 3; k++)
						for (int i = 0; i < 3; i++)
							if (!g[i + 1][j])
								g[i + 1][j] = g[i][j], g[i][j] = 0;
				}
				break;
			}
			switch (jin)
			{
			case 0://up
				for (int i = 0; i < 4; i++)
				{
					for (int j = 3; j > 0; j--)
						if (g[i][j] and g[i][j - 1] == g[i][j])
						{
							g[i][j - 1] *= 2, g[i][j] = 0;
							score++;
							break;
						}
					for (int k = 0; k < 3; k++)
						for (int j = 3; j > 0; j--)
							if (!g[i][j - 1])
								g[i][j - 1] = g[i][j], g[i][j] = 0;
				}
				break;
			case 1://down
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 3; j++)
						if (g[i][j] and g[i][j + 1] == g[i][j])
						{
							g[i][j + 1] *= 2, g[i][j] = 0;
							score++;
							break;
						}
					for (int k = 0; k < 3; k++)
						for (int j = 0; j < 3; j++)
							if (!g[i][j + 1])
								g[i][j + 1] = g[i][j], g[i][j] = 0;
				}
				break;
			case 2://left
				for (int j = 0; j < 4; j++)
				{
					for (int i = 3; i > 0; i--)
						if (g[i][j] and g[i - 1][j] == g[i][j])
						{
							g[i - 1][j] *= 2, g[i][j] = 0;
							score++;
							break;
						}
					for (int k = 0; k < 3; k++)
						for (int i = 3; i > 0; i--)
							if (!g[i - 1][j])
								g[i - 1][j] = g[i][j], g[i][j] = 0;
				}
				break;
			case 3://right
				for (int j = 0; j < 4; j++)
				{
					for (int i = 0; i < 3; i++)
						if (g[i][j] and g[i + 1][j] == g[i][j])
						{
							g[i + 1][j] *= 2, g[i][j] = 0;
							score++;
							break;
						}
					for (int k = 0; k < 3; k++)
						for (int i = 0; i < 3; i++)
							if (!g[i + 1][j])
								g[i + 1][j] = g[i][j], g[i][j] = 0;
				}
				break;
			}

			//判断胜利失败
			bool win = 0;
			int cnt = 0;
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
					if (g[i][j] == 2048)
						win = 1;
					else if (g[i][j])
						cnt++;
			if (cnt == 16)
			{
				closegraph();
				cout << "You lose~" << endl;
				cout << "Your score:" << endl << score << endl;
				break;
			}
			if (win)
			{
				closegraph();
				cout << "You win~" << endl;
				cout << "Your score:" << endl << score << endl;
				break;
			}

			//新加入一个2
			vector < pair<int, int> > radm;
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
					if (!g[i][j])
						radm.push_back(make_pair(i, j));
			random_shuffle(radm.begin(), radm.end());
			g[radm[0].first][radm[0].second] = 2;
			if (rand() % 2)
				g[radm[0].first][radm[0].second] += 2;

			//绘图
			cleardevice();
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
					if (g[i][j])
					{
						int c;
						//选色
						switch (g[i][j])
						{
						case 2:
							c = BLUE;
							break;
						case 4:
							c = GREEN;
							break;
						case 8:
							c = CYAN;
							break;
						case 16:
							c = RED;
							break;
						case 32:
							c = MAGENTA;
							break;
						case 64:
							c = BROWN;
							break;
						case 128:
							c = LIGHTGRAY;
							break;
						case 256:
							c = DARKGRAY;
							break;
						case 512:
							c = LIGHTBLUE;
							break;
						case 1024:
							c = LIGHTGREEN;
							break;
						case 2048:
							c = LIGHTCYAN;
							break;
						}
						setfillcolor(c);
						solidrectangle(200 * i, 200 * j, 200 * i + 200, 200 * j + 200);
						TCHAR s[5];
						_stprintf_s(s, _T("%d"), g[i][j]);
						outtextxy(200 * i + 75, 200 * j + 75, s);
					}
			setfillcolor(BLACK);
			solidrectangle(0, 800, 800, 900);
			outtextxy(200 * 0 + 75, 825, _T("UP"));
			outtextxy(190 * 1 + 75, 825, _T("DOWN"));
			outtextxy(190 * 2 + 75, 825, _T("LEFT"));
			outtextxy(190 * 3 + 75, 825, _T("RIGHT"));
		}
	}
	_getch();
}