package pack;
import javax.crypto.Cipher;
import javax.crypto.spec.SecretKeySpec;
import javax.crypto.spec.IvParameterSpec;

import java.nio.ByteBuffer;
import java.nio.charset.CharacterCodingException;
import java.nio.charset.CharsetDecoder;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
// BEGIN SOLUTION
// please import only standard libraries and make sure that your code compiles and runs without unhandled exceptions 
// END SOLUTION
 
public class hw {    
  static void Problem1() throws Exception {
    byte[] cipherText = Files.readAllBytes(Paths.get("cipher1.bin"));
    // BEGIN SOLUTION
    
    byte[] key = new byte[] { 1, 2, 1, 2, 
                              1, 2, 1, 2, 
                              1, 2, 1, 2, 
                              1, 2, 1, 2 };
    
    //create key
    SecretKeySpec skeySpec = new SecretKeySpec(key, "AES");
    //create cipher of aes, cbc, and no padding
    Cipher cipher = Cipher.getInstance("AES/CBC/NoPadding");
    //decrypt 
    cipher.init(Cipher.DECRYPT_MODE, skeySpec, new IvParameterSpec(new byte[16]));
    cipherText = cipher.doFinal(cipherText);
    
    byte[] plainText = cipherText;    
    // END SOLUTION
    
    Files.write(Paths.get("plain1.txt"), plainText);
  }
  

  static void Problem2() throws Exception {
    byte[] cipherText = Files.readAllBytes(Paths.get("cipher2.bin"));
    
    // BEGIN SOLUTION
    byte[] key = new byte[] { 1, 2, 1, 2, 
            1, 2, 1, 2, 
            1, 2, 1, 2, 
            1, 2, 1, 2 };
    
    
    
	//splits the ciphertext into 3 16-byte blocks
    byte[] firstbyte = new byte[16],secondbyte=new byte[16],thirdbyte=new byte[16];
    for(int i=0; i < cipherText.length; i++) {
    		if(i<16) {
    			secondbyte[i]=cipherText[i];
    		}
    		if((i<32)&&(i>15)) {
    			firstbyte[i-16]=cipherText[i];
    		}
    		if((i<48)&&(i>31)) {
    			thirdbyte[i-32]=cipherText[i];
    		}
    	}
    
    //concetantes first and second byte blocks
	byte[] combined = new byte[firstbyte.length + secondbyte.length];
	System.arraycopy(firstbyte,0,combined,0         ,firstbyte.length);
	System.arraycopy(secondbyte,0,combined,firstbyte.length,secondbyte.length);
	//concetantes concanetated and third byte blocks
	byte[] combined2 = new byte[combined.length + thirdbyte.length];
	System.arraycopy(combined,0,combined2,0         ,combined.length);
	System.arraycopy(thirdbyte,0,combined2,combined.length,thirdbyte.length);
	
	
	
	
	SecretKeySpec skeySpec = new SecretKeySpec(key, "AES");
	Cipher cipher = Cipher.getInstance("AES/CBC/NoPadding");
	cipher.init(Cipher.DECRYPT_MODE, skeySpec, new IvParameterSpec(new byte[16]));
	cipherText = cipher.doFinal(combined2);
	
	
	
	
    byte[] modifiedCipherText = cipherText;
    byte[] plainText = modifiedCipherText;
    // END SOLUTION
    Files.write(Paths.get("plain2.txt"), plainText);
  }

  static void Problem3() throws Exception {
    byte[] cipherBMP = Files.readAllBytes(Paths.get("cipher3.bmp"));
    byte[] otherBMP = Files.readAllBytes(Paths.get("msg3.bmp"));
    //1573008
    //1573002
    
    for(int i=0; i < 1000; i++) {
    	cipherBMP[i]=otherBMP[i];
	}
	
    
    byte[] modifiedCipherBMP = cipherBMP;
    // END SOLUTION
    
    Files.write(Paths.get("cipher3_modified.bmp"), modifiedCipherBMP);
  }
/*
 System.out.print(plainTextA[i]+" ");
    	System.out.print(cipherTextA[i]+" ");
    	System.out.println();
    	byte[] nonceAndCounter = new byte[16];
    System.arraycopy(new byte[16], 0, nonceAndCounter, 0, 8);
    nonceAndCounter[15] = (byte) 1; // PyCrypto's default initial value is 1
    IvParameterSpec ivSpec = new IvParameterSpec(nonceAndCounter);
 */
  static void Problem4() throws Exception {
    byte[] plainTextA = Files.readAllBytes(Paths.get("plain4A.txt"));
    byte[] cipherTextA = Files.readAllBytes(Paths.get("cipher4A.bin"));
    byte[] cipherTextB = Files.readAllBytes(Paths.get("cipher4B.bin"));
    
    int size=38;
    byte[] xorcipher = new byte[size];
    byte[] xorkey = new byte[size];
    
    for(int i=0; i < size; i++) {
    	xorcipher[i]=  (byte) (cipherTextA[i] ^ cipherTextB[i]);
	}
    
    for(int i=0; i < size; i++) {
    	//System.out.print(xorkey[i]+" ");
	}
    byte[] plainTextB = xorkey;
    // END SOLUTION
    
    Files.write(Paths.get("plain4B.txt"), plainTextB);
  }
/*for(int l=0; l < cipherText.length; l++) {
                	if((cipherText[i]>128)||(cipherText[l]<0)) {
                		english=false;
                	}
                }
                if(english) {
                	System.out.println("true");
                	System.arraycopy(cipherText, 0, text, 0, cipherText.length);
            	}
                english=true;
                for(int l=0; l < cipherText.length; l++) {
                	System.out.println(cipherText[i]);
                }
                byte[] text = new byte[0];
    boolean english=true;
    
    for(int i=0; i < 12; i++) {
    	key[0]=  (byte) i;
    	for(int j=0; j < 31; j++) {
    		key[0]=  (byte) j;
        	for(int k=0; k < 99; k++) {
            	key[2]=  (byte) k;
            	SecretKeySpec skeySpec = new SecretKeySpec(key, "AES");
                //create cipher of aes, cbc, and no padding
                Cipher cipher = Cipher.getInstance("AES/CBC/NoPadding");
                //decrypt 
                cipher.init(Cipher.DECRYPT_MODE, skeySpec, new IvParameterSpec(new byte[16]));
                cipherText = cipher.doFinal(cipherText);
                
        	}
    	}
    	
    	
    	
    	for(int i=0; i < 12; i++) {
    	key[0]=  (byte) i;
    	for(int j=0; j < 31; j++) {
    		key[1]=  (byte) j;
        	for(int k=0; k < 99; k++) {
            	key[2]=  (byte) k;
            	SecretKeySpec skeySpec = new SecretKeySpec(key, "AES");
                //create cipher of aes, cbc, and no padding
                Cipher cipher = Cipher.getInstance("AES/CBC/NoPadding");
                //decrypt 
                cipher.init(Cipher.DECRYPT_MODE, skeySpec, new IvParameterSpec(new byte[16]));
                cipherText = cipher.doFinal(cipherText);
                System.arraycopy(cipherText, 0, plainText, 0, cipherText.length);
        	}
    	}
    }
    for(int i=0; i < 12; i++) {
    	key[0]=  (byte) i;
    	for(int j=0; j < 31; j++) {
    		key[1]=  (byte) j;
        	for(int k=0; k < 99; k++) {
            	key[2]=  (byte) k;
            	SecretKeySpec skeySpec = new SecretKeySpec(key, "AES");
                //create cipher of aes, cbc, and no padding
                Cipher cipher = Cipher.getInstance("AES/CBC/NoPadding");
                //decrypt 
                cipher.init(Cipher.DECRYPT_MODE, skeySpec, new IvParameterSpec(new byte[16]));
                cipherText = cipher.doFinal(cipherText);
                System.out.println(cipherText.length);
                for(int l=0; l < cipherText.length; l++) {
                //	plainText[l+count]=cipherText[l];
                	count+=1;
                }
        	}
    	}
    }
    CharsetDecoder decoder=StandardCharsets.UTF_8.newDecoder();
                try {
                	decoder.decode(ByteBuffer.wrap(cipherText));
                }catch(CharacterCodingException ex) {
                	english=false;
                }
                if(english) {
                	for(int l=0; l < cipherText.length; l++) {
                    	plainText[l+count]=cipherText[l];
                    	count+=1;
                    }
                }
 * */
  static void Problem5() throws Exception {
    byte[] cipherText = Files.readAllBytes(Paths.get("cipher5.bin"));
    
    // BEGIN SOLUTION
    byte[] plainText = new byte[cipherText.length];
    int count=0;
    boolean english=true;
    byte[] key = new byte[] { 0, 0, 0, 0, 
                              0, 0, 0, 0, 
                              0, 0, 0, 0, 
                              0, 0, 0, 0 };
    
    for(int i=0; i < 13; i++) {
    	for(int j=0; j < 32; j++) {
        	for(int k=0; k < 100; k++) {
        		key[0]=  (byte) i;
        		key[1]=  (byte) j;
            	key[2]=  (byte) k;
            	plainText=cipherText;
            	SecretKeySpec skeySpec = new SecretKeySpec(key, "AES");
                //create cipher of aes, cbc, and no padding
                Cipher cipher = Cipher.getInstance("AES/CBC/NoPadding");
                //decrypt 
                cipher.init(Cipher.DECRYPT_MODE, skeySpec, new IvParameterSpec(new byte[16]));
                plainText = cipher.doFinal(plainText);
                
                CharsetDecoder decoder=StandardCharsets.UTF_8.newDecoder();

                try {
                	decoder.decode(ByteBuffer.wrap(plainText));
                }catch(CharacterCodingException ex) {
                	english=false;
                }
                
                if(english) {
                	Files.write(Paths.get("plain5.txt"), plainText);
                }
                english=true;
        	}
    	}
	}
  //create key
}

  public static void main(String [] args) {
    try {  
      Problem1();
      Problem2();
      Problem3();
      Problem4();
      Problem5();
    } catch (Exception e) {
      e.printStackTrace();
    } 
  }
}