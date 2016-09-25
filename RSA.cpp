#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
using namespace std;


//Finds the greatest common divisor of two numbers.
unsigned long int gcd(unsigned long int a, unsigned long int b){
  unsigned long int c;

  while (b != 0){
    c = b;
    b = a % b;
    a = c;
  }
  return a;
}

unsigned long int gcd2(unsigned long int a, unsigned long int b){
  if(b){
    return(gcd(b, a%b));
  }else{
    return a;
  }
}

//Exponetial number generator.
unsigned long int expon(unsigned long int a, unsigned long int b){

  unsigned long int i;
  unsigned long int total = 1;

  for (i = 0; i < b; i++){
    total = total * a;
  }
  return total;
}

bool prime(unsigned long int p){

  unsigned long int i;
  int prime = 1;

  for (i = 2; i*i <= p; i++){
    if (p % i == 0){
      prime = false;
    }
    if (prime){
      true;
    }
  }
  return prime; 
}

int main (){
  
  //Random number generator
  srand(time(NULL));
  unsigned long int prime1 = rand() % 1000; //(expon(2,32) - 1);
  unsigned long int prime2 = rand() % 1000;//(expon(2,32) - 1);
  //Making sure that the random number is prime
  while (!prime(prime1)){
    prime1 = rand() % 1000;//(expon(2,32) - 1);
  }
  while (!prime(prime2)){
    prime2 = rand() % 1000;//(expon(2,32) - 1);
  }

  unsigned long int n;
  //This will be the modulus for the encryption and decryption portion
  n = prime1 * prime2;
  //This is use to develope the public key and the decoder
  unsigned long int phi;
  phi = (prime1 - 1)*(prime2 - 1);

  //This is the public key                                                 //
  unsigned long int key;                                                   //
                                                                           //
  key = rand() % phi; //Initializes Key for while loop                     //
  //This protion generates the public key                                  //
  while (gcd2(key,phi) != 1){                                              //
    key = rand() % phi;                                                    //
  }                                                                        //
  cout << "key is " << key << endl;                                        //
                                                                           //
  unsigned long int decoder;                                               //
  decoder = rand() % phi; //Initializes decoder for while loop             //
  //This is the decoding key                                               //
  while (((decoder*key) % phi) != 1){                                      //
    decoder = rand() % phi;                                                //
  }                                                                        //
  cout << "decoder is "<< decoder << endl;                                 //

  unsigned long int encryptedmessage;
  unsigned long int msg;

  cout << " What is your message? ";
  cin >> msg;

  encryptedmessage = expon(msg,key) % n;

  unsigned long int decryptedmessage;

  decryptedmessage = expon(encryptedmessage,decoder) % n;
  
  cout << "Prime1 is " << prime1 << endl;
  cout << "Prime2 is " << prime2 << endl;
  cout << "N is " << n << endl;
  cout << "Phi is" << phi << endl;  
  cout << "The key is " << key << endl;
  cout << "The decoder is " << decoder << endl;
  cout << "The encrypted message is " << encryptedmessage << endl;
  cout << "The decrypted message is " << decryptedmessage << endl;    

  return 0;
}
