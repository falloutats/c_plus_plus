#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using std::cout;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;

enum class State {kEmpty, kObstacle};


vector<State> ParseLine(string line) {

    istringstream sline(line);
    int n;
    char c;
    vector<State> row;
    while (sline >> n >> c && c == ',') {
        if(n==0){
            row.push_back(State::kEmpty);
        }
        else{
            row.push_back(State::kObstacle);
        }
    }
    return row;
}

vector<vector<State>> ReadBoardFile(string path) {

    ifstream myfile (path);
    vector<vector<State>> board{};
    if (myfile) {
        string line;
        while (getline(myfile, line)) {
            vector<State> row = ParseLine(line);
            board.push_back(row);
        }
    }
    return board;
}

string CellString(State cell){

    switch(cell){
        case State::kObstacle: return "⛰️   ";
        default:return "0  ";
    }
}

vector<vector<State>> Search(vector<vector<State>> grid, int start[2], int goal[2]){
    cout << "No path found" << "\n";
    return vector<vector<State>> {};
}

int Heuristic(int x1, int x2, int y1, int y2){

    return abs(x2 - x1) + abs(y2 - y1);
}

void PrintBoard(const vector<vector<State>> board) {

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            cout << CellString(board[i][j]);
        }
        cout << "\n";
    }
}


int main() {
    int start[2] {1,2};
    int goal[2]{4,5};
    auto board = ReadBoardFile("/Users/fallout/CLionProjects/untitled2/board");
    auto solution = Search(board, start, goal);
    PrintBoard(board);



}