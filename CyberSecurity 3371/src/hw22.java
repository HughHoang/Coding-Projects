import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.security.MessageDigest;
import java.util.List;
import java.math.BigInteger;
import java.security.NoSuchAlgorithmException;
import java.util.HashMap;
 
public class hw22 {
    public static byte[] getSHA(String input) throws NoSuchAlgorithmException
    {
        // Static getInstance method is called with hashing SHA
        MessageDigest digest = MessageDigest.getInstance("SHA-256");
 
        // digest() method called
        // to calculate message digest of an input
        // and return array of byte
        return digest.digest(input.getBytes(StandardCharsets.UTF_8));
    }
   
    public static String toHexString(byte[] hash)
    {
        // Convert byte array into signum representation
        BigInteger number = new BigInteger(1, hash);
 
        // Convert message digest into hex value
        StringBuilder hexString = new StringBuilder(number.toString(16));
 
        // Pad with leading zeros
        while (hexString.length() < 32)
        {
            hexString.insert(0, '0');
        }
 
        return hexString.toString();
    }
    public static void main(String[] args) {
        long start = System.nanoTime();
        try {
            HashMap<String, String> shamap = new HashMap<String, String>();
            List<String> allLines = Files.readAllLines(Paths.get("C:/Users/UtHoa/Downloads/Problem2/password_dictionary"));
            for (String line : allLines) {
                try
                    {
                        String sha= toHexString(getSHA(line));
                        shamap.put(sha,line);
                    }
                    catch (NoSuchAlgorithmException e) {
                        System.out.println("Exception thrown for incorrect algorithm: " + e);
                    }
            }
            HashMap<String, String> passwords = new HashMap<String, String>();
            List<String> users = Files.readAllLines(Paths.get("C:/Users/UtHoa/Downloads/Problem2/users"));
            for (String user : users) {
                String[] id = user.split(",");
                String username = id[0];
                String hashpass = id[1];
                String password=shamap.get(hashpass);
                passwords.put(username, password);
                System.out.println("Username: "+username+ " " +"Password: "+ passwords.get(username));
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        long finish = System.nanoTime();
        long timeElapsed = finish - start;
        System.out.println(timeElapsed);
    }
 
}
 

