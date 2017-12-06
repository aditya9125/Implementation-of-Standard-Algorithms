
void shortest_path_bfs(int source)
{


	queue<II> q;


    q.push({source,0});

    while(!q.empty())
    {
        II top =q.front();

        int pn= top.first;

        int pd=top.second;

        q.pop();

        for(int j=0;j<adj[pn].size();j++)
        {

			int nn= adj[pn][j];

			if(!visited[nn])
			{
                dist[nn]= pd +1;

                q.push({nn,dist[nn]});

                visited[nn]=1;
			}

        }
    }
}
