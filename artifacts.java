import java.util.Scanner;

public class artifacts{
    public static void main(String[] args) {
        double atk = 0;
        double atkr = 0;
        double critd = 0.5;
        double critr = 0.05;
        Scanner sc = new Scanner(System.in);
        for (int i = 0; i < 25; i++) {
            String[] line = sc.nextLine().split("\\+");
            line[1] = line[1].replace("%","");
            double val = Double.parseDouble(line[1]);
            switch(line[0]){
                case "ATK":
                    atk += val;
                    break;
                case "ATK Rate":
                    atkr += val/100;
                    break;
                case "Crit DMG Rate":
                    critd += val/100;
                    break;
                case "Crit Rate":
                    critr += val/100;
                    critr = Math.min(critr,1.0);
                    break;
                default:
                    break;
            }

        }
        atk = 1500*(1+atkr)+atk;
        double e = atk*(1-critr)+atk*(1+critd)*critr;
        System.out.println(e);

    }
}