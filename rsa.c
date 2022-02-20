#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 9999
int gcd(int n1,int n2){
    int gcd = 1;
   for(int i=1; i <= n1 && i <= n2; ++i)
    {
        // Checks if i is factor of both integers
        if(n1%i==0 && n2%i==0)
            gcd = i;
    }

    return gcd;

}


int genPrivKey(int pub_key,int phi,int n){
    
    for(int i=2;i<MAX;i++){
        if(pub_key*i % phi == 1){
            
            return i;
        }
    }
    printf("Valid private key not found");
}

int genPublicKey(int phi,int n){
    
    for(int i=2;i<MAX;i++){
        if(gcd(i,phi) == 1){        //relative prime condition
            return i;
        }
    }
    printf("Valid pKey not found");
}

int power(int n,int exp){
    int res = 1;
    for(int i=0;i<exp;i++){
        res *= n;
    }
    return res;
}

int main(){
    int p,q;
    int pText;
    printf("Enter prime number 1:");
    scanf("%d",&p);

    printf("\n enter prime number 2:");
    scanf("%d",&q);
    int phi = (p-1)*(q-1);
    int n = p*q;
    int e = genPublicKey(phi,n);
    int d = genPrivKey(e,phi,n);
    printf("public key is:%d and private key is %d",e,d);
    printf("\nEnter plain text to convert to cipher text");
    scanf("%d",&pText);

    printf("\n Encrypting plain text to cipher text");

    int cText = power(pText,e)%n;

    printf("\n cipher text is:%d",cText);

    printf("\n original text%d",pText);
    

//    int decryptedText = power(cText,d) %n;
//
//    printf("\nDecrypted plain text is:%d",decryptedText);

    return 0;


}