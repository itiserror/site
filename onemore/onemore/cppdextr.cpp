#include <iostream>
#include <vector>
using namespace std;
const int V=4;
//алгоритм Дейкстры
vector<int>& Dijkstra(int GR[V][V], int st,int end)
{
int distance[V],firstmin[V], count, index, i, u, m=st+1;
bool visited[V];
for (i=0; i<V; i++)
{
distance[i]=INT_MAX; visited[i]=false;
}
distance[st]=0;
for (count=0; count<V-1; count++)
{
int min=INT_MAX;
for (i=0; i<V; i++)
if (!visited[i] && distance[i]<=min)
{
min=distance[i]; index=i;
}
u=index;
visited[u]=true;
for (i=0; i<V; i++)
if (!visited[i] && GR[u][i] && distance[u]!=INT_MAX &&
distance[u]+GR[u][i]<distance[i])
{
distance[i]=distance[u]+GR[u][i];
firstmin[i]=u;
}
}
cout<<"Стоимость пути из начальной вершины до остальных:\t\n";
for (i=0; i<V; i++) if (distance[i]!=INT_MAX)
cout<<m<<" > "<<i+1<<" = "<<distance[i]<<endl;
else cout<<m<<" > "<<i+1<<" = "<<"маршрут недоступен"<<endl;


vector<int> way;
int temp=end;
while(temp!=st)
{
	way.push_back(temp);
	temp=firstmin[temp];
}
return way;
}
//главная функция
void main()
{
setlocale(LC_ALL, "Rus");
int start,end, GR[V][V]={
	{0, 5, 0, 0},
	{0, 0, 6, 2},
	{7, 0, 0, 1},
	{0, 0, 0, 0}};

   
cout<<"Начальная вершина >> ";
cin>>start;
cout<<"Конечная вершина >> ";
cin>>end;

vector<int> res=Dijkstra(GR, start-1,end-1);
cout<<"Маршрут: ";
for (int i=res.size()-1;i>-1;i--)
	cout<<res[i]<<" ";
system("pause>>void");
}