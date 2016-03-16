#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <string>
#include <fstream>
#include <cstdio>

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
		}
        cout << "ss dd" << endl;
	}
    return 0;
}
