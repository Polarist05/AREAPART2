#include<stdio.h>
#include<string>
#include<iostream>
#include<stack>
struct Pos
{
	int x, y;
	Pos(int x, int y) :x(x), y(y) {}
};
bool bHorizontalEdge[100][100] = {}, bVerticleEdge[100][100] = {}, havePast[100][100] = {};
int sizeY, sizeX, lastPosY, lastPosX, ans = INT_MAX;
void Depth(Pos position, int distance) {
	if (position.x == lastPosX && position.y == lastPosY) {
		if (distance < ans) {
			ans = distance;
		}
		return;
	}
	havePast[position.y][position.x] = true;
	if (position.y - 1 >= 0 && !havePast[position.y - 1][position.x] && bHorizontalEdge[position.y][position.x]) {
		Depth(Pos(position.x, position.y - 1), distance + 1);
	}
	if (position.y + 1 < sizeY && !havePast[position.y + 1][position.x] && bHorizontalEdge[position.y + 1][position.x]) {
		Depth(Pos(position.x, position.y + 1), distance + 1);
	}
	if (position.x - 1 >= 0 && !havePast[position.y][position.x - 1] && bVerticleEdge[position.y][position.x]) {
		Depth(Pos(position.x - 1, position.y), distance + 1);
	}
	if (position.x + 1 < sizeX && !havePast[position.y][position.x + 1] && bVerticleEdge[position.y][position.x + 1]) {
		Depth(Pos(position.x + 1, position.y), distance + 1);
	}
	havePast[position.y][position.x] = false;
}
int main() {

	std::cin >> sizeY >> sizeX >> lastPosY >> lastPosX;
	lastPosY--; lastPosX--;
	for (size_t i = 0; i < sizeY; i++)
	{
		for (size_t j = 0; j < sizeX; j++)
		{
			char c;
			std::cin >> c;
			if (c == 'B') {
				bVerticleEdge[i][j + 1] = true;
				bHorizontalEdge[i + 1][j] = true;
			}
			if (c == 'R') {
				bVerticleEdge[i][j + 1] = true;
			}
			if (c == 'D') {
				bHorizontalEdge[i + 1][j] = true;
			}
		}
	}
	Depth(Pos(0, 0), 0);
	if (ans == INT_MAX)
		printf("Null");
	else
		printf("%d", ans);
}
/*
4 4 1 4
B R D D
D R B D
R R R D
N N N N
*/