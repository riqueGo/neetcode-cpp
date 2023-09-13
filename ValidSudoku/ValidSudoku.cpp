#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using std::vector;
using std::unordered_map;
using std::unordered_set;

class Solution {
    private:
        unordered_map<int,unordered_set<char>> rows;
        unordered_map<int,unordered_set<char>> columns;
        unordered_map<int,unordered_set<char>> subBox;

        bool isValidSubSudoku(vector<vector<char>>& board, int row, int column){
            unordered_set<char> boardValues;

            for(int i = row; i < 3 + row; i++){
                for(int j = column; j < 3 + column; j++){
                    if(board[i][j] == '.') continue;

                    if(boardValues.count(board[i][j]) > 0 ||
                        rows[i].count(board[i][j]) > 0 ||
                        columns[j].count(board[i][j]) > 0 ){
                        return false;
                    }

                    boardValues.insert(board[i][j]);
                    rows[i].insert(board[i][j]);
                    columns[j].insert(board[i][j]);
                }
            }
            return true;
        }

    public:
        bool isValidSudoku(vector<vector<char>>& board){
            for(int i = 0; i < 9; i+=3){
                for(int j = 0; j < 9; j+=3){
                    if(!isValidSubSudoku(board, i, j)) return false;
                }
            }
            return true;
        }
};

int main() {
    //Valid Sudoku
    // vector<vector<char>> board{
    //     {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
    //     {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
    //     {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
    //     {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
    //     {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
    //     {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
    //     {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
    //     {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
    //     {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    // };

    //Invalid Sudoku
    // vector<vector<char>> board{
    //     {'8', '3', '.', '.', '7', '.', '.', '.', '.'},
    //     {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
    //     {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
    //     {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
    //     {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
    //     {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
    //     {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
    //     {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
    //     {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    // };

    //Invalid Sudoku
    vector<vector<char>> board{
        {'.', '.', '4', '.', '.', '.', '6', '3', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'5', '.', '.', '.', '.', '.', '.', '9', '.'},
        {'.', '.', '.', '5', '6', '.', '.', '.', '.'},
        {'4', '.', '3', '.', '.', '.', '.', '.', '1'},
        {'.', '.', '.', '7', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '5', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'}
    };

    Solution solution;
    std::cout << solution.isValidSudoku(board) << std::endl;
}