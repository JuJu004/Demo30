#include <iostream>
using namespace std;
const int V = 7; //имеем в задачи 7 узлов

void  alg(int GR[V][V], int st) //алгоритм решения
{
	int distance[V], count, index, i, u, f = st + 1;
	bool visited[V];
	for (i = 0; i < V; i++)
	{
		distance[i] = INT_MAX; visited[i] = false;
	}
	distance[st] = 0;
	for (count = 0; count < V - 1; count++)
	{
		int min = INT_MAX;
		for (i = 0; i < V; i++)
			if (!visited[i] && distance[i] <= min)
			{
				min = distance[i]; index = i;
			}
		u = index;
		visited[u] = true;
		for (i = 0; i < V; i++)
			if (!visited[i] && GR[u][i] && distance[u] != INT_MAX &&
				distance[u] + GR[u][i] < distance[i])
				distance[i] = distance[u] + GR[u][i];
	}
	cout << "Путь из начального узла до остальных узлов:\t\n"; //ищем расстояние ммежду узлами

	for (i = 0; i < V; i++) if (distance[i] != INT_MAX)
		cout << f << " > " << i + 1 << " = " << distance[i] << endl;
	else cout << f << " > " << i + 1 << " = " << "маршрута не существует" << endl;
}

void main() // функция  для нахождения кратчайшего пути 
{
	setlocale(LC_ALL, "Rus");
	int start, GR[V][V] =  // переносим расстояние между узлами с данных задачи
	{
	  {0, 2, 4, 10, 0, 0, 0},
	  {0, 0, 0, 11, 5, 18, 0},
	  {0, 0, 0, 3, 11, 1, 0},
	  {0, 0, 0, 0, 8, 7, 0},
	  {0, 0, 0, 0, 0, 0, 6},
	  {0, 0, 0, 0, 0, 0, 9},
	  {0, 0, 0, 0, 0, 0, 0}
	};
	cout << "Начальный узел >> "; cin >> start; 
	alg(GR, start - 1);
	system("pause>>void");
}