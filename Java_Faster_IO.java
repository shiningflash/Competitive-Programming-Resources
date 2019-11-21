// Java Faster I/O for competitive programming
// We wrote our own class instead of using slower default Scanner class
// @author : Amirul Islam

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {
	public static PrintWriter out;

	public static class myScanner {
		BufferedReader br;
		StringTokenizer st;
		
		public myScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}
		
		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}
		
		int nextInt() {
			return Integer.parseInt(next());
		}
		
		long nextLong() {
			return Long.parseLong(next());
		}
		
		double nextDouble() {
			return Double.parseDouble(next());
		}
		
		String nextLine() {
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}
	}
	
	public static void main(String[] args) {
		myScanner sc = new myScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		
		// regular code starts here
		int n = sc.nextInt();
		long l = sc.nextLong();
		double d = sc.nextDouble();
		String str = sc.next();
		String line = sc.nextLine();
		
		out.println(3*n);
		// code ends here
		
		out.close();
	}
}
