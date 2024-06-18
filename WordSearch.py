class Solution:
    def print_string(self, s):
        for char in s:
            print(char, end=" ")
        print()
    def solve(self, board, word, trial, x, y, r, c, newword, wordindex, ans):
        # Base Case
        if wordindex == len(word):
            ans.append(newword)
            return
        if x == r and y == c:
            return
        piece = word[wordindex]
        if x - 1 >= 0 and board[x - 1][y] == piece and trial[x - 1][y] == 0:
            # print("condition 1")
            trial[x - 1][y] = 1
            newword += piece
            self.solve(board, word, trial, x - 1, y, r, c, newword, wordindex + 1, ans)
            newword = newword[:-1]
            trial[x - 1][y] = 0
        # left
        if x + 1 < r and board[x + 1][y] == piece and trial[x + 1][y] == 0:
            # print("Condition 2")
            trial[x + 1][y] = 1
            newword += piece
            self.solve(board, word, trial, x + 1, y, r, c, newword, wordindex + 1, ans)
            newword = newword[:-1]
            trial[x + 1][y] = 0
        # down
        if y + 1 < c and board[x][y + 1] == piece and trial[x][y + 1] == 0:
            # print("Condition 3")
            trial[x][y + 1] = 1
            newword += piece
            self.solve(board, word, trial, x, y + 1, r, c, newword, wordindex + 1, ans)
            newword = newword[:-1]
            trial[x][y + 1] = 0
        # up
        if y - 1 >= 0 and board[x][y - 1] == piece and trial[x][y - 1] == 0:
            # print("Condition 4")
            trial[x][y - 1] = 1
            newword += piece
            self.solve(board, word, trial, x, y - 1, r, c, newword, wordindex + 1, ans)
            newword = newword[:-1]
            trial[x][y - 1] = 0
        # No movement possible
        return
    def exist(self, board, word):
        row = len(board)
        col = len(board[0])
        newword = ""
        ans = []
        trial = [[0] * col for _ in range(row)]
        wordindex = 1  # Since process starts only after first case is checked
        for i in range(row):
            for j in range(col):
                if board[i][j] == word[0]:
                    newword += word[0]
                    trial[i][j]=1
                    self.solve(board, word, trial, i, j, row, col, newword, wordindex, ans)
                    if ((len(ans) >0) and ans[0] == word):
                        return True
                    else:
                        ans.clear() 
                        newword=""
                        wordindex=1
                        trial = [[0] * col for _ in range(row)]
        return False
