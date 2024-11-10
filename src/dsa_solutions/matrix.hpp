#include <iostream>
#include <vector>
#include <set>


namespace Solutions
{
    namespace Matrix
    {
        // https://leetcode.com/problems/set-matrix-zeroes/
        void setZeroes(std::vector<std::vector<int>>& matrix) 
        {
            bool makeFirstRowZero = false;
            bool makeFirstColZero = false;
            
            for (int M = 0; M < matrix.size(); M++)
            {
                for (int N = 0; N < matrix[M].size(); N++)
                {
                    if (matrix[M][N] == 0)
                    {
                        matrix[M][0] = 0;
                        matrix[0][N] = 0;

                        if (M == 0) 
                            makeFirstRowZero = true;

                        if (N == 0)
                            makeFirstColZero = true;
                    }
                }
            }

            for (int M = 1; M < matrix.size(); M++)
            {
                for (int N = 1; N < matrix[M].size(); N++)
                {
                    if (matrix[M][0] == 0 || matrix[0][N] == 0)
                    {
                        matrix[M][N] = 0;
                    }
                }
            }
            
            if (makeFirstRowZero)
            {    
                for (int N = 0; N < matrix[0].size(); N++)
                {
                    matrix[0][N] = 0;
                }
            }

            if (makeFirstColZero)   
            {    
                for (int M = 1; M < matrix.size(); M++)
                {
                    matrix[M][0] = 0;
                }
            }
        }

        // https://leetcode.com/problems/spiral-matrix/
        std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) 
        {
            std::vector<int> newOrder;
            return newOrder;
        }

        // https://leetcode.com/problems/rotate-image/
        void rotate(std::vector<std::vector<int>>& matrix) 
        {
            size_t X = 0; 
            size_t Y = matrix.size()-1;
            
            int pivot = 1;

            while (X < Y)
            {
                matrix[X++].swap(matrix[Y--]);
            }

            for (X = 0; X < matrix.size() - 1; X++)
            {
                for (Y = pivot; Y < matrix[X].size(); Y++)
                {
                    auto temp = matrix[X][Y];
                    matrix[X][Y] = matrix[Y][X];
                    matrix[Y][X] = temp;
                }

                pivot++;
            }
        }

        bool DFS_search(std::vector<std::vector<char>>& board, 
                        const std::string& word,
                        size_t x, 
                        size_t y, 
                        size_t k = 0)
        {
            if (x < 0 || x >= board.size())
            {
                return false;
                if (y < 0 || y >= board[x].size())
                {
                    return false;
                }
            }

            if (k == word.size())
            {
                return true;
            }
            if (word[k] != board[x][y])
            {
                return false;
            }
            
            board[x][y] = '!';

            if (DFS_search(board, word, x+1, y, k+1) ||
                DFS_search(board, word, x-1, y, k+1) ||
                DFS_search(board, word, x, y+1, k+1) ||
                DFS_search(board, word, x, y-1, k+1))
            {
                return true;
            }

            board[x][y] = word[k];

            return false;
        }

        // https://leetcode.com/problems/word-search/
        bool exist(std::vector<std::vector<char>>& board, std::string word) 
        {
            for (size_t x = 0; x < board.size(); x++)
            {
                for (size_t y = 0; y < board.size(); y++)
                {
                    if (DFS_search(board, word, x, y)) 
                        return true;
                }
            }

            return false;
        }

        /*
        {
            size_t countFound = 0;
            size_t wordLength = word.size();
            std::set<std::pair<size_t, size_t>> alreadyVisitedCords;

            bool cancelSearch = false;
            size_t x(0), y(0);

            while (!cancelSearch)
            {
                auto up = std::make_pair(x-1, y);
                auto down = std::make_pair(x+1, y);
                auto right = std::make_pair(x, y+1);
                auto left = std::make_pair(x, y-1);

                if (alreadyVisitedCords.find(up) == alreadyVisitedCords.end())
                {

                }

                if (board[x][y] == word[countFound])
                {
                    countFound++;
                    alreadyVisitedCords.insert(std::make_pair(x, y));
                }

                if (board[x][y+1] == word[countFound])
                {
                    
                }
                else if (board[x+1][y] == word[countFound])
                {
                    
                }
            }
        }
        */
    }
}