/*
int rows = matrix.size();
        int cols = matrix[0].size();

        vector<vector<int>> transpose(cols, vector<int> (rows,0));

        int a = 0, b = 0;
        for(int i = 0; i < cols; i++)
        {
            for(int j=0;j<rows;j++)
            {
                transpose[a][b] = matrix[j][i];
                b = (b+1) % rows;   // Change row of transpose till it reaches the last row
                if(b==0) a++;   // Change column of transpose
            }
        }

        return transpose;
*/