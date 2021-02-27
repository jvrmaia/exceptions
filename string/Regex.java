import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/*
   [abc]	 a, b, or c (simple class)
   [^abc]	 Any character except a, b, or c (negation)
   [a-zA-Z]	 a through z, or A through Z, inclusive (range)
   [a-d[m-p]]	 a through d, or m through p: [a-dm-p] (union)
   [a-z&&[def]]	 d, e, or f (intersection)
   [a-z&&[^bc]]	 a through z, except for b and c: [ad-z] (subtraction)
   [a-z&&[^m-p]]	 a through z, and not m through p: [a-lq-z] (subtraction)
   .	 Any character (may or may not match line terminators)
   \d	 A digit: [0-9]
   \D	 A non-digit: [^0-9]
   \s	 A whitespace character: [ \t\n\x0B\f\r]
   \S	 A non-whitespace character: [^\s]
   \w	 A word character: [a-zA-Z_0-9]
   \W	 A non-word character: [^\w]
   ^	  The beginning of a line
   $	  The end of a line
   \b	  A word boundary
   \B	  A non-word boundary
   \A	  The beginning of the input
   \G	  The end of the previous match
   \Z	  The end of the input but for the final terminator, if any
   \z	  The end of the input
   */

public class Regex {

    public static void main(String[] args) throws Exception {
        BufferedReader stdin;
        stdin = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Digite a regex: ");
        String regex = stdin.readLine();
        System.out.println("Digite a palavra a ser verificada na regex: ");
        String word = stdin.readLine();
        Pattern pattern = Pattern.compile(regex);
        Matcher matcher = pattern.matcher(word); 
        if(matcher.find()){
            System.out.println("Achou!");
        }else{
            System.out.println("Nao achou!");
        }
    }

}
