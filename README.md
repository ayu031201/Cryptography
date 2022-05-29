# Cryptography
Implementation of Famous Cryptographic Techniques in C++

**★ Shift Cipher**

  => It is the most common encrypting techinique which involves replacing each letter in the message by a letter that is some fixed number of positions further along in      the alphabet.
  
**★ Keyed Cipher**

  => We choose a string as a KEY and for each character present in the we assign all 'A' as the First character of the Key, all 'B' as the Second character of the key        and so on until the character is over and the rest of the alphabets the characters that are left in sorted manner.
  
**★ Keyless Cipher**

  => As per the name this cipher dont have a *key* so we arrange our message into a table of column by column and then row by row. 
     And we take all of the row one's character first and concatenate them as a single string and we do the same with the column ones.
     Then our Encrypted message is the concatination of Row (First) and Column (Second) string.
     
**★ Affine Cipher**

  => We choose Two keys "A" and "B" and we assign each letter of the message as the ASCII character os the number A * X + B where X is the ASCII number of that                character.
  
**🌟 RSA (Rivest–Shamir–Adleman) Cryptosystem**

  => It is the most widely used Cryptosystem because of its safe and secure encryption.
  
  => It is a Public-Key Cryptosystem in which the encryption key is Public and does not matches with the Private-Key.
  
  => In RSA a user creates and publishes a public key based on two large prime numbers, along with an auxiliary value. The prime numbers are      kept secret. Messages can      be encrypted by anyone, via the public key, but can only be decoded by someone who knows those prime numbers.
  
  => The security of RSA relies on the practical difficulty of factoring the product of two large prime numbers.
  
  => RSA is used to transmit shared keys for symmetric-key cryptography, which are then used for bulk encryption–decryption.
  
 There are no published methods to defeat the system if a large enough key is used.
   
   **⭐ My Implementation :**
   
   => RSA algorithm that we use is often slow because it does not directly uses the message that we have to encrypt.
   The Security of our RSA algorithm is somewhat depends on how large we choose the prime numbers, but i have choosed small prime numbers which is not very secure and    is easy to crack. Because the random prime numbers that rand() function generates are not completely random those are psuedo random prime numbers. It takes those      two prime numbers and an integer input as a message that we have to encrypt. Then we will generate a Public-Key using it and a Private-Key which is complementary to    the Public-Key and we can decrypt the cipher text using this Private-key. We take a character value and encrypt it using its ASCII value and show the encrypted        text then we calculate the Private-Key using Extended-Eculidean Algorithm and can decrypt the encrypted message to the original message. 
