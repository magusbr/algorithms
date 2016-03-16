#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <string>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

// adapted from:
// http://zlethic.com/bfs-knights-move/


using namespace std;

const int MAX_X = 310;
const int MAX_Y = 310;

int dist[MAX_X][MAX_Y];

struct squ{
    char x;
    char y;
	long step;
};

void print_cell_distance()
{
    // show only a fraction of the distance matrix
    for (int i = 19; i >= 0; i--)
    {
        for (int j = 0; j < 20; j++)
        {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

long bfs(char x1,char y1,char x2,char y2){
    queue<squ>que;
    squ current,src,dst;
	squ reached;
	int movement_index;
	int movement[8][2] = {{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{-2,1},{2,-1},{-2,-1}};

	// initialize src and destination
	src.step=0;
	src.x=x1;
	src.y=y1;
	dst.x=x2;
	dst.y=y2;

	// src is the first to be added to queue
	dist[src.x][src.y] = 0;
	que.push(src);

	while(1)
    {
        current = que.front();
		que.pop();

		// for each possible movement (8 directions)
	    for(movement_index = 0; movement_index < 8; movement_index++)
        {
            // tn will have current position plus movement
	        reached.x = current.x + movement[movement_index][0];
			reached.y = current.y + movement[movement_index][1];

			// from 0 till distance array limit (could be made a 2d-list to reach infinite)
			if(reached.x < MAX_X && reached.y < MAX_Y && reached.x >= 0 && reached.y >= 0)
			{
			    // is this cell already enqueued?
			    // this "if" could be replaced by a list of visited, to make it limitless
				if(dist[reached.x][reached.y] == 0)
                {
                    // if not, it can be reached in step+1
				    dist[reached.x][reached.y] = current.step+1;

				    // enqueue reached cell
					reached.step=current.step+1;
					que.push(reached);

					print_cell_distance();

					// have we reached our destination
					if(reached.x == dst.x && reached.y == dst.y)
						return reached.step;
				}
			}
	    }
	}
}


int solve_mathematically(int orig_x, int orig_y, int dest_x, int dest_y)
{
    // https://apetresc.wordpress.com/2010/10/25/the-knight-metric/
    int M = max(abs(orig_x-dest_x), abs(orig_y-dest_y));
    int m = min(abs(orig_x-dest_x), abs(orig_y-dest_y));

    // original doesn't work
    // int d_k = max((int)ceil(M/2), (int)ceil((M+m)/3)) + (M+m) - (max((int)ceil(M/2), (int)ceil((M+m)/3))%2);

    // modified - still fail for some cases...
    int d_k = max((int)ceil(M/2), (int)ceil((M+m)/3)) + ((M+m) - max((int)ceil(M/2), (int)ceil((M+m)/3)))%2;

    // need to handle special cases, but not implement yet
    // (1,1), (2,2)
    // (1,0), (0,1)
    // (2,0), (0,2)
    // (3,0), (0,3)
    // (3,2), (2,3)

    return d_k;
}

int solve_mathematically2(int x1, int y1, int x2, int y2)
{
    // http://www.codeforces.com/blog/entry/2716
    int dx = abs(x2-x1);
    int dy = abs(y2-y1);
    int lb=(dx+1)/2;
    lb = max(lb, (dy+1)/2);
    lb = max(lb, (dx+dy+2)/3);
    while ((lb%2)!=(dx+dy)%2) lb++;
    // special cases
    if (abs(dx)==1 && dy==1) return 4;
    if (abs(dx)==1 && dy==0) return 3;
    if (abs(dy)==1 && dx==0) return 3;
    if (abs(dx)==2 && abs(dy)==2) return 4;
    return lb;
}

int main(){
    char s1[3],s2[3];
	int sum;

	cout << "ss dd" << endl;
	while(scanf("%s %s",s1,s2)!=EOF){
	    memset(dist,0,sizeof(dist));
		if(!strcmp(s1,s2))
			cout<<"To get from "<<s1<<" to "<<s2<<" takes 0 knight moves."<<endl;
		else{
			 sum=bfs(s1[0]-'0',s1[1]-'0',s2[0]-'0',s2[1]-'0');
		    cout<<"To get from "<<s1<<" to "<<s2<<" takes "<<sum<<" knight moves."<<endl;
		    cout << "Mathematically: " << solve_mathematically(s1[0]-'0',s1[1]-'0',s2[0]-'0',s2[1]-'0') << endl;
		    cout << "Mathematically2: " << solve_mathematically2(s1[0]-'0',s1[1]-'0',s2[0]-'0',s2[1]-'0') << endl;
		}
        cout << "ss dd" << endl;
	}
    return 0;
}
