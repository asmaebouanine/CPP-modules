 typedef struct  s_point
   {
	       int           x;
	           int           y;
   }	t_point;
void	fill(char start, char **tab, t_point size, int y, int x)
{
	if (y<0||x<0|y >= size.y|| x >= size.x || tab[y][x] != start)
		return ;
	tab[y][x] = 'F';

	fill(start, tab, size, y - 1, x);
	fill(start, tab, size, y + 1, x);
	fill(start, tab, size, y, x - 1);
	fill(start, tab, size, y, x + 1);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	char start = tab[begin.y][begin.x];
	fill(start, tab, size, begin.y, begin.x);
}
