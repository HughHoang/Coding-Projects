import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.security.MessageDigest;
import java.util.List;
import java.util.Map;
import java.math.BigInteger;
import java.security.NoSuchAlgorithmException;
import java.util.HashMap;
 
public class hw23 {
    public static byte[] getSHA(String input) throws NoSuchAlgorithmException
    {
        // Static getInstance method is called with hashing SHA
        MessageDigest digest = MessageDigest.getInstance("SHA-256");
        return digest.digest(input.getBytes(StandardCharsets.UTF_8));
    }

    public static byte[] getsalt(String input, byte[] salt) throws NoSuchAlgorithmException
    {
        // Static getInstance method is called with hashing SHA
        MessageDigest md = MessageDigest.getInstance("SHA-256");
        md.update(salt);

        return md.digest(input.getBytes(StandardCharsets.UTF_8));
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

            HashMap<String, String> hashpassmap = new HashMap<String, String>();
            HashMap<String, String> passwords = new HashMap<String, String>();
            String[] duplicated= new String[1000];
            int count=0;
            List<String> users = Files.readAllLines(Paths.get("C:/Users/UtHoa/Downloads/Problem2/users"));
            String hashpass="";
            String username1="";
            String username2="";
            for (String user : users) {
                String[] id = user.split(",");
                String username = id[0];
                hashpass = id[1];
                if(hashpassmap.containsValue(hashpass)){
                    duplicated[count] = hashpass;
                    count++;
                }
                hashpassmap.put(username, hashpass);
                String password=shamap.get(hashpass);
                passwords.put(username, password);
            }

            String duplicatehash=duplicated[0];
            boolean user=true;
            for (Map.Entry<String, String> e : hashpassmap.entrySet()){
                if(duplicatehash.equals(e.getValue())){
                    if(user){
                        username1=e.getKey();
                        user=false;
                    }
                    else{
                        username2=e.getKey();
                    }
                }
            }
            List<String> salts = Files.readAllLines(Paths.get("C:/Users/UtHoa/Downloads/Problem2/users_salted"));
            try
                    {
                        for (String salt : salts) {
                            String[] id = salt.split(",");
                            String username = id[0];
                            String saltpass = id[1];
                            hashpass = id[2];
                            if(username.equals(username1)){
                                System.out.println("Username: "+username1+ " " +"Password: "+passwords.get(username) + " " +"Salted Password: "+saltpass+passwords.get(username) + " " +"Hash Salted Password From File:  "+ hashpass + " " +"Hash Salted Password Calculated: "+ toHexString(getSHA(saltpass+passwords.get(username))));
                            }
                            else if(username.equals(username2)){
                                System.out.println("Username: "+username2+ " " +"Password: "+passwords.get(username) + " " +"Salted Password: "+saltpass+passwords.get(username) + " " +"Hash Salted Password From File: "+ hashpass + " " +"Hash Salted Password Calculated: "+toHexString(getSHA(saltpass+passwords.get(username))));
                            }
                            hashpassmap.put(username, hashpass);
                        }
                    }
                    catch (NoSuchAlgorithmException e) {
                        System.out.println("Exception thrown for incorrect algorithm: " + e);
                    }
            
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
 
}
