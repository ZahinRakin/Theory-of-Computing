//dfa to regex.
import java.util.Scanner;

public class lab_06_1447{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int numOfStates;
        int numOfSymbols;

        System.out.print("Enter num of states: ");
        numOfStates = Integer.parseInt(scanner.nextLine());

        System.out.print("Enter num of symbols: ");
        numOfSymbols = Integer.parseInt(scanner.nextLine());
    
        int[][] transition = new int[numOfStates][numOfStates];

        String[][][] regex = new String[numOfStates][numOfStates][numOfStates];

        //getting the transition table
        for(int i = 0; i < numOfStates; i++){
            for(int j = 0; j < numOfSymbols; j++){
                System.out.printf("\u03B4[%d][%d] : ",i,j);
                transition[i][j] = Integer.parseInt(scanner.nextLine());
            }
        }

        //understood what he wanted to do. Rij(0) loading complete.
        for(int i = 0; i < numOfStates; i++){
            for(int j = 0; j < numOfStates; j++){
                int flag = 0;

                if(i == j){
                    regex[0][i][j] = "\u03B5";
                    flag = 1;
                }

                for(int k = 0; k < numOfSymbols; k++){
                    if(transition[i][k] == j){
                        if(flag == 1){
                            regex[0][i][j] += "+";
                        }

                        regex[0][i][j] += k;
                        flag = 1;
                    }
                }

                if(flag == 0){
                    regex[0][i][j] = "\u03B5";
                }
            }
        }

        //printing the question ans : a.
        for(int i = 0; i < numOfStates; i++){
            for(int j = 0; j < numOfStates; j++){
                System.out.printf("regex[0][%d][%d] = %s\n",i+1,j+1,regex[0][i][j]);
            }
        }
        //loading the b & c's ans.
        for(int k = 1; k < numOfStates; k++){
            for(int i = 0; i < numOfStates; i++){
                for(int j = 0; j < numOfStates; j++){
                    regex[k][i][j] = regex[k-1][i][j] + "+" + regex[k-1][i][k-1] + "(" + regex[k-1][k-1][k-1] + ")*" + regex[k-1][k-1][j];
                }
            }
        }
        //printing the b & c 's ans
        for(int k = 1; k < numOfStates; k++){
            for(int i = 0; i < numOfStates; i++){
                for(int j = 0; j < numOfStates; j++){
                    System.out.printf("regex[%d][%d][%d] = %s\n", k, i+1, j+1, regex[k][i][j]);
                }
            }
        }
        scanner.close();
    }
}