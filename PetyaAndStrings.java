import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class PetyaAndStrings {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s1 = br.readLine();
		String s2 = br.readLine();
		int a = s1.compareToIgnoreCase(s2);
		if (a == 0)
			a = 0;
		else
			a = a / Math.abs(a);
		System.out.println(a);
	}
}
