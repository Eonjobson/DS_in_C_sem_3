

public class SudokuSolver {
    public static void main(String[] args) {
        int[][] board = new int[][]{
            {3, 0, 6, 5, 0, 8, 4, 0, 0},
            {5, 2, 0, 0, 0, 0, 0, 0, 0},
            {0, 8, 7, 0, 0, 0, 0, 3, 1},
            {0, 0, 3, 0, 1, 0, 0, 8, 0},
            {9, 0, 0, 8, 6, 3, 0, 0, 5},
            {0, 5, 0, 0, 9, 0, 6, 0, 0},
            {1, 3, 0, 0, 0, 0, 2, 5, 0},
            {0, 0, 0, 0, 0, 0, 0, 7, 4},
            {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };

    if (solve(board)) {
        display(board);
    } else {
        System.out.println("Cannot solve");
    }

}
    
    static boolean solve(int [][] board){
        int n = board.length;
        int row =-1;
        int col = -1;
        boolean NoEmptyLeft = true;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==0){
                    row = i;
                    col = j;
                    NoEmptyLeft = false;
                    break;
                }
            }
            if(!NoEmptyLeft){
                    break;
                }
            
        }
        if(NoEmptyLeft){
            //Sudoku has been solved
            return true;
        }
        for(int number=0;number<=9;number++){
            if(isSafe(board, row, col, number)){
                board[row][col] = number;
                if(solve(board)){
                    return true;
                }
                else{
                    board[row][col] =0;
                }
            }
        }
        return false;

    }
    private static void display(int[][] board) {
        for(int[] row : board) {
            for(int num : row) {
                System.out.print(num + " ");
            }
            System.out.println();
        }
    }
    static boolean isSafe(int[][] board,int row,int col,int num){
        //Check row
        for(int i=0;i<board.length;i++){
            if(board[row][i]==num){
                return false;
            }
        }
        //Check column
        for(int[] nums:board){
            if(nums[col]==num){
                return false;
            }
        }
        //Check the mini grid
        int n = (int)Math.sqrt(board.length);
        int startRow = row - row%n;
        int startCol = col - col%n;
        for (int r = startRow; r < startRow + n; r++) {
            for (int c = startCol; c < startCol + n; c++) {
                if (board[r][c] == num) {
                    return false;
                }
            }
        }
        return true;



    }
}
