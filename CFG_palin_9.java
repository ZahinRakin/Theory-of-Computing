import java.util.Scanner;

/*
P → ε
P → 0
P → 1
P → 0P0
P → 1P1
*/

public class lab_09_1447{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int i;
        String input;
        String output;
        System.out.print("Input : ");
        input = scanner.nextLine();
        scanner.close();
        
       
        System.out.print("Output : ");

        if(!isPalindrome(input)){
            System.out.println("Not in this grammer!");
            System.exit(0);
        }

        output = "P";
        for(i = 0; i < input.length()/2; i++){
            if(input.charAt(i) == '0'){
                System.out.print(output + " => ");
                output = output.replace("P", "0P0");
            }else if(input.charAt(i) == '1'){
                System.out.print(output + " => ");
                output = output.replace("P", "1P1");
            }
        }

        if(input.length()%2 == 0){
            System.out.print(output + " => ");
            output = output.replace("P" , "");
            System.out.print(output);
        }else{
            System.out.print(output + " => ");
            if(input.charAt(i) == '0'){
                output = output.replace("P" , "0");
                System.out.print(output);
            }else{
                output = output.replace("P" , "1");
                System.out.print(output);
            }
        }
        System.out.println(".");
    }

    static boolean isPalindrome(String str){
        int i = 0;
        int j = str.length() - 1;
        while(i < j){
            if(str.charAt(i) == str.charAt(j)){
                i++;
                j--;
            }else{
                return false;
            }
        }
        return true;
    }
}
